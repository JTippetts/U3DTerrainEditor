#include "Uniforms.hlsl"
#include "Samplers.hlsl"
#include "Transform.hlsl"
#include "ScreenPos.hlsl"
#include "Lighting.hlsl"
#include "Fog.hlsl"

// When rendering a shadowed point light, disable specular calculations on Shader Model 2 to avoid exceeding the instruction limit
#if !defined(SM3) && defined(SHADOW) && defined(POINTLIGHT)
    #undef SPECULAR
#endif

sampler2D sWeightMap0 : register(S0);
sampler2D sWeightMap1 : register(S1);
sampler2D sDetailMap1 : register(S2);
sampler2D sDetailMap2 : register(S3);
sampler2D sNormalMap1 : register(S4);
sampler2D sNormalMap2 : register(S14);
sampler2D sMask : register(S12);

uniform float2 cDetailTiling;

void VS(float4 iPos : POSITION,
    float3 iNormal : NORMAL,
    float2 iTexCoord : TEXCOORD0,
	#ifdef NORMALMAP
        float4 iTangent : TANGENT,
    #endif
    #ifndef NORMALMAP
        out float2 oTexCoord : TEXCOORD0,
    #else
        out float4 oTexCoord : TEXCOORD0,
        out float4 oTangent : TEXCOORD3,
    #endif
    out float3 oNormal : TEXCOORD1,
    out float4 oWorldPos : TEXCOORD2,
    out float2 oDetailTexCoord : TEXCOORD4,
    #ifdef PERPIXEL
        #ifdef SHADOW
            out float4 oShadowPos[NUMCASCADES] : TEXCOORD4,
        #endif
        #ifdef SPOTLIGHT
            out float4 oSpotPos : TEXCOORD5,
        #endif
        #ifdef POINTLIGHT
            out float3 oCubeMaskVec : TEXCOORD5,
        #endif
    #else
        out float3 oVertexLight : TEXCOORD4,
        out float4 oScreenPos : TEXCOORD5,
    #endif
    out float4 oPos : POSITION)
{
    float4x3 modelMatrix = iModelMatrix;
    float3 worldPos = GetWorldPos(modelMatrix);
    oPos = GetClipPos(worldPos);
    oNormal = GetWorldNormal(modelMatrix);
    oWorldPos = float4(worldPos, GetDepth(oPos));
    #ifdef NORMALMAP
        float3 tangent = GetWorldTangent(modelMatrix);
        float3 bitangent = cross(tangent, oNormal) * iTangent.w;
        oTexCoord = float4(GetTexCoord(iTexCoord), bitangent.xy);
        oTangent = float4(tangent, bitangent.z);
    #else
        oTexCoord = GetTexCoord(iTexCoord);
    #endif
    oDetailTexCoord = cDetailTiling * oTexCoord;

    #ifdef PERPIXEL
        // Per-pixel forward lighting
        float4 projWorldPos = float4(worldPos.xyz, 1.0);

        #ifdef SHADOW
            // Shadow projection: transform from world space to shadow space
            GetShadowPos(projWorldPos, oShadowPos);
        #endif

        #ifdef SPOTLIGHT
            // Spotlight projection: transform from world space to projector texture coordinates
            oSpotPos = mul(projWorldPos, cLightMatrices[0]);
        #endif

        #ifdef POINTLIGHT
            oCubeMaskVec = mul(worldPos - cLightPos.xyz, (float3x3)cLightMatrices[0]);
        #endif
    #else
        // Ambient & per-vertex lighting
        oVertexLight = GetAmbient(GetZonePos(worldPos));

        #ifdef NUMVERTEXLIGHTS
            for (int i = 0; i < NUMVERTEXLIGHTS; ++i)
                oVertexLight += GetVertexLight(i, worldPos, oNormal) * cVertexLights[i * 3].rgb;
        #endif
        
        oScreenPos = GetScreenPos(oPos);
    #endif
}

void PS(
	#ifndef NORMALMAP
        float2 iTexCoord : TEXCOORD0,
    #else
        float4 iTexCoord : TEXCOORD0,
        float4 iTangent : TEXCOORD3,
    #endif
    float3 iNormal : TEXCOORD1,
    float4 iWorldPos : TEXCOORD2,
    float2 iDetailTexCoord : TEXCOORD4,
    #ifdef PERPIXEL
        #ifdef SHADOW
            float4 iShadowPos[NUMCASCADES] : TEXCOORD4,
        #endif
        #ifdef SPOTLIGHT
            float4 iSpotPos : TEXCOORD5,
        #endif
        #ifdef CUBEMASK
            float3 iCubeMaskVec : TEXCOORD5,
        #endif
    #else
        float3 iVertexLight : TEXCOORD4,
        float4 iScreenPos : TEXCOORD5,
    #endif
    #ifdef PREPASS
        out float4 oDepth : COLOR1,
    #endif
    #ifdef DEFERRED
        out float4 oAlbedo : COLOR1,
        out float4 oNormal : COLOR2,
        out float4 oDepth : COLOR3,
    #endif
    out float4 oColor : COLOR0)
{
    // Get material diffuse albedo
    float4 weights0 = tex2D(sWeightMap0, iTexCoord.xy).rgba;
	float4 weights1 = tex2D(sWeightMap1, iTexCoord.xy).rgba;
	float mask=tex2D(sMask, iTexCoord.xy).r;
    float sumWeights = weights0.r + weights0.g + weights0.b + weights0.a + weights1.r + weights1.g + weights1.b + weights1.a;
    weights0 /= sumWeights;
	weights1 /= sumWeights;
	
	float pixelOffset=8;
	float shrunkSize=(512.0-pixelOffset)/1024.0;
	float zeroOffset=(pixelOffset*0.5)/1024.0;
	float halfOffset=(pixelOffset*0.5+512.0)/1024.0;
	
	float2 smallFrac=frac(iDetailTexCoord.xy);
	float4 diffColor = cMatDiffColor * (
			weights0.r * (tex2D(sDetailMap1, smallFrac*shrunkSize)+zeroOffset) +
			weights0.g * (tex2D(sDetailMap1, smallFrac*shrunkSize+float2(halfOffset,zeroOffset))) +
			weights0.b * (tex2D(sDetailMap1, smallFrac*shrunkSize+float2(zeroOffset,halfOffset))) +
			weights0.a * (tex2D(sDetailMap1, smallFrac*shrunkSize+float2(halfOffset,halfOffset))) +
		
			weights1.r * (tex2D(sDetailMap2, smallFrac*shrunkSize)+zeroOffset) +
			weights1.g * (tex2D(sDetailMap2, smallFrac*shrunkSize+float2(halfOffset,zeroOffset))) +
			weights1.b * (tex2D(sDetailMap2, smallFrac*shrunkSize+float2(zeroOffset,halfOffset))) +
			weights1.a * (tex2D(sDetailMap2, smallFrac*shrunkSize+float2(halfOffset,halfOffset)))
		);
	diffColor=lerp(float4(1,0.5,0.3, 1), diffColor, mask);
	

    // Get material specular albedo
    float3 specColor = cMatSpecColor.rgb;

    // Get normal
    #ifdef NORMALMAP
        float3x3 tbn = float3x3(iTangent.xyz, float3(iTexCoord.zw, iTangent.w), iNormal);
        // We may be running low on instructions on Shader Model 2, so skip normalize if necessary
		float4 normalColor =(
			weights0.r * (tex2D(sNormalMap1, smallFrac*shrunkSize)+zeroOffset) +
			weights0.g * (tex2D(sNormalMap1, smallFrac*shrunkSize+float2(halfOffset,zeroOffset))) +
			weights0.b * (tex2D(sNormalMap1, smallFrac*shrunkSize+float2(zeroOffset,halfOffset))) +
			weights0.a * (tex2D(sNormalMap1, smallFrac*shrunkSize+float2(halfOffset,halfOffset))) +
		
			weights1.r * (tex2D(sNormalMap2, smallFrac*shrunkSize)+zeroOffset) +
			weights1.g * (tex2D(sNormalMap2, smallFrac*shrunkSize+float2(halfOffset,zeroOffset))) +
			weights1.b * (tex2D(sNormalMap2, smallFrac*shrunkSize+float2(zeroOffset,halfOffset))) +
			weights1.a * (tex2D(sNormalMap2, smallFrac*shrunkSize+float2(halfOffset,halfOffset)))
		);
		//float4 normalColor=tex2D(sDetailMap1, (iDetailTexCoord*0.25).xy);
        //#if defined(SM3) || !defined(SHADOW) || !defined(SPECULAR)
            float3 normal = normalize(mul(DecodeNormal(normalColor), tbn));
        //#else
          //  float3 normal = mul(DecodeNormal(normalcolor), tbn);
        //#endif
    #else
        float3 normal = normalize(iNormal);
    #endif

    // Get fog factor
    #ifdef HEIGHTFOG
        float fogFactor = GetHeightFogFactor(iWorldPos.w, iWorldPos.y);
    #else
        float fogFactor = GetFogFactor(iWorldPos.w);
    #endif

    #if defined(PERPIXEL)
        // Per-pixel forward lighting
        float3 lightDir;
        float3 lightColor;
        float3 finalColor;
        
        float diff = GetDiffuse(normal, iWorldPos.xyz, lightDir);

        #ifdef SHADOW
            diff *= GetShadow(iShadowPos, iWorldPos.w);
        #endif
    
        #if defined(SPOTLIGHT)
            lightColor = iSpotPos.w > 0.0 ? tex2Dproj(sLightSpotMap, iSpotPos).rgb * cLightColor.rgb : 0.0;
        #elif defined(CUBEMASK)
            lightColor = texCUBE(sLightCubeMap, iCubeMaskVec).rgb * cLightColor.rgb;
        #else
            lightColor = cLightColor.rgb;
        #endif
    
        #ifdef SPECULAR
            float spec = GetSpecular(normal, cCameraPosPS - iWorldPos.xyz, lightDir, cMatSpecColor.a);
            finalColor = diff * lightColor * (diffColor.rgb + spec * specColor * cLightColor.a);
        #else
            finalColor = diff * lightColor * diffColor.rgb;
        #endif

        #ifdef AMBIENT
            finalColor += cAmbientColor * diffColor.rgb;
            finalColor += cMatEmissiveColor;
            oColor = float4(GetFog(finalColor, fogFactor), diffColor.a);
        #else
            oColor = float4(GetLitFog(finalColor, fogFactor), diffColor.a);
        #endif
    #elif defined(PREPASS)
        // Fill light pre-pass G-Buffer
        float specPower = cMatSpecColor.a / 255.0;

        oColor = float4(normal * 0.5 + 0.5, specPower);
        oDepth = iWorldPos.w;
    #elif defined(DEFERRED)
        // Fill deferred G-buffer
        float specIntensity = specColor.g;
        float specPower = cMatSpecColor.a / 255.0;

        float3 finalColor = iVertexLight * diffColor.rgb;

        oColor = float4(GetFog(finalColor, fogFactor), 1.0);
        oAlbedo = fogFactor * float4(diffColor.rgb, specIntensity);
        oNormal = float4(normal * 0.5 + 0.5, specPower);
        oDepth = iWorldPos.w;
    #else
        // Ambient & per-vertex lighting
        float3 finalColor = iVertexLight * diffColor.rgb;

        #ifdef MATERIAL
            // Add light pre-pass accumulation result
            // Lights are accumulated at half intensity. Bring back to full intensity now
            float4 lightInput = 2.0 * tex2Dproj(sLightBuffer, iScreenPos);
            float3 lightSpecColor = lightInput.a * (lightInput.rgb / GetIntensity(lightInput.rgb));

            finalColor += lightInput.rgb * diffColor.rgb + lightSpecColor * specColor;
        #endif

        oColor = float4(GetFog(finalColor, fogFactor), diffColor.a);
    #endif
}
