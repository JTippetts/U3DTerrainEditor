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
sampler2D sDetailMap : register(S2);
#ifdef BUMPMAP
sampler2D sNormal : register(S3);
#endif
sampler2D sMask : register(S12);

uniform float2 cDetailTiling;
uniform float cBumpStrength;
uniform float4 cPackTexFactors;

float mipmapLevel(float2 uv, float textureSize)
{
    float2 dx = ddx(uv * textureSize);
    float2 dy = ddy(uv * textureSize);
    float d = max(dot(dx, dx), dot(dy, dy));
    return 0.5 * log2(d);
}



float4 sampleTexturePackMipWrapped(sampler2D s, float2 uv, float2 tile, float lod)
{
 	/// estimate mipmap/LOD level
	//float lod = mipmapLevel(uv, cPackTexFactors.z);
	//lod = clamp(lod, 0.0, cPackTexFactors.w);

	/// get width/height of the whole pack texture for the current lod level
	float size = pow(2.0, cPackTexFactors.w - lod);
	float sizex = size / cPackTexFactors.x; // width in pixels
	float sizey = size / cPackTexFactors.y; // height in pixels

	/// perform tiling
	uv = frac(uv);

	/// tweak pixels for correct bilinear filtering, and add offset for the wanted tile
	uv.x = uv.x * ((sizex * cPackTexFactors.x - 1.0) / sizex) + 0.5 / sizex + cPackTexFactors.x * tile.x;
	uv.y = uv.y * ((sizey * cPackTexFactors.y - 1.0) / sizey) + 0.5 / sizey + cPackTexFactors.y * tile.y;

    //return(tex2Dlod(s, uv, lod));
	return(tex2Dlod(s, float4(uv.xy,0,lod)));
}


float4 sampleTerrain(sampler2D s, float2 uv, float2 tile, float lod)
{
	//return (tex2D(s,uv)*0.65+tex2D(s,uv*0.435)*0.35);
	//return tex2D(s,uv);
	return sampleTexturePackMipWrapped(s,uv,tile, lod);
}

float3 bump(sampler2D s, float2 uv, float currenta, float2 tile, float lod)
{
	float size = pow(2.0, cPackTexFactors.w - lod);
	float sizex = 1.0/(size / cPackTexFactors.x); // width in pixels
	float sizey = 1.0/(size / cPackTexFactors.y); // height in pixels
	
	float3 n=float3(
		(currenta - sampleTerrain(s,float2(uv.x+sizex, uv.y),tile,lod).a)/(sizex*cBumpStrength),
		(currenta - sampleTerrain(s,float2(uv.x,uv.y+sizey),tile,lod).a)/(sizey*cBumpStrength),
		1
	);
	return normalize(n);
}

void VS(float4 iPos : POSITION,
    float3 iNormal : NORMAL,
    float2 iTexCoord : TEXCOORD0,
	#ifdef BUMPMAP
        float4 iTangent : TANGENT,
    #endif
    #ifndef BUMPMAP
        out float2 oTexCoord : TEXCOORD0,
    #else
        out float4 oTexCoord : TEXCOORD0,
        out float4 oTangent : TEXCOORD3,
    #endif
    out float3 oNormal : TEXCOORD1,
    out float4 oWorldPos : TEXCOORD2,
    out float2 oDetailTexCoord : TEXCOORD10,
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
    #ifdef BUMPMAP
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
	#ifndef BUMPMAP
        float2 iTexCoord : TEXCOORD0,
    #else
        float4 iTexCoord : TEXCOORD0,
        float4 iTangent : TEXCOORD3,
    #endif
    float3 iNormal : TEXCOORD1,
    float4 iWorldPos : TEXCOORD2,
    float2 iDetailTexCoord : TEXCOORD10,
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
    float4 weights0 = tex2D(sWeightMap0, iTexCoord).rgba;
	float4 weights1 = tex2D(sWeightMap1, iTexCoord).rgba;
	#ifdef USEMASKTEXTURE
	float mask=tex2D(sMask, iTexCoord).r;
	#endif
	
	// Calculate lod
	float lod = mipmapLevel(iDetailTexCoord, cPackTexFactors.z);
	lod = clamp(lod, 0.0, cPackTexFactors.w);
	
	float4 tex1=sampleTerrain(sDetailMap, iDetailTexCoord, float2(0,0),lod);
	float4 tex2=sampleTerrain(sDetailMap, iDetailTexCoord, float2(1,0),lod);
	float4 tex3=sampleTerrain(sDetailMap, iDetailTexCoord, float2(2,0),lod);
	float4 tex4=sampleTerrain(sDetailMap, iDetailTexCoord, float2(3,0),lod);
	
	float4 tex5=sampleTerrain(sDetailMap, iDetailTexCoord, float2(0,1),lod);
	float4 tex6=sampleTerrain(sDetailMap, iDetailTexCoord, float2(1,1),lod);
	float4 tex7=sampleTerrain(sDetailMap, iDetailTexCoord, float2(2,1),lod);
	float4 tex8=sampleTerrain(sDetailMap, iDetailTexCoord, float2(3,1),lod);
	
	float ma=max(tex1.a+weights0.r, max(tex2.a+weights0.g, max(tex3.a+weights0.b, max(tex4.a+weights0.a, max(tex5.a+weights1.r, max(tex6.a+weights1.g, max(tex7.a+weights1.b, tex8.a+weights1.a)))))))-0.2;
	float b1=max(0, tex1.a+weights0.r-ma);
	float b2=max(0, tex2.a+weights0.g-ma);
	float b3=max(0, tex3.a+weights0.b-ma);
	float b4=max(0, tex4.a+weights0.a-ma);
	float b5=max(0, tex5.a+weights1.r-ma);
	float b6=max(0, tex6.a+weights1.g-ma);
	float b7=max(0, tex7.a+weights1.b-ma);
	float b8=max(0, tex8.a+weights1.a-ma);
	float bsum=b1+b2+b3+b4+b5+b6+b7+b8;
	float4 diffColor=(tex1*b1+tex2*b2+tex3*b3+tex4*b4+tex5*b5+tex6*b6+tex7*b7+tex8*b8)/bsum;
    
	#ifdef USEMASKTEXTURE
	diffColor=lerp(float4(1,0.5,0.3, diffColor.a), diffColor, mask);
	#endif

    // Get material specular albedo
    float3 specColor = cMatSpecColor.rgb;

    // Get normal
    #ifdef BUMPMAP
        float3x3 tbn = float3x3(iTangent.xyz, float3(iTexCoord.zw, iTangent.w), iNormal);
        
		//float3 bump1=bump(sDetailMap1, iDetailTexCoord, tex1.a, float2(0,0),lod);
		//float3 bump2=bump(sDetailMap1, iDetailTexCoord, tex2.a,float2(1,0),lod);
		//float3 bump3=bump(sDetailMap1, iDetailTexCoord, tex3.a,float2(0,1),lod);
		//float3 bump4=bump(sDetailMap1, iDetailTexCoord, tex4.a,float2(1,1),lod);
		
		//float3 bump5=bump(sDetailMap2, iDetailTexCoord, tex5.a,float2(0,0),lod);
		//float3 bump6=bump(sDetailMap2, iDetailTexCoord, tex6.a,float2(1,0),lod);
		//float3 bump7=bump(sDetailMap2, iDetailTexCoord, tex7.a,float2(0,1),lod);
		//float3 bump8=bump(sDetailMap2, iDetailTexCoord, tex8.a,float2(1,1),lod);
		
		float3 bump1=DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord, float2(0,0), lod));
		float3 bump2=DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord, float2(1,0), lod));
		float3 bump3=DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord, float2(2,0), lod));
		float3 bump4=DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord, float2(3,0), lod));
		
		float3 bump5=DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord, float2(0,1), lod));
		float3 bump6=DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord, float2(1,1), lod));
		float3 bump7=DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord, float2(2,1), lod));
		float3 bump8=DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord, float2(3,1), lod));
		
		float3 normal=normalize(mul((bump1*b1+bump2*b2+bump3*b3+bump4*b4+bump5*b5+bump6*b6+bump7*b7+bump8*b8)/bsum,tbn));
		
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
