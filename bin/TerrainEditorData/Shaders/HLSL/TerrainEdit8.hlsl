#include "Uniforms.hlsl"
#include "Samplers.hlsl"
#include "Transform.hlsl"
#include "ScreenPos.hlsl"
#include "Lighting.hlsl"
#include "Fog.hlsl"

static const int numblends=2;
static const int numlayers=8;

#ifndef D3D11
	#error D3D9 Does not support texture arrays.
#endif

// Uniforms
#ifndef D3D11
	// D3D9 Uniforms
	#ifdef COMPILEVS
	
	#endif
	
	#ifdef COMPILEPS
	
	#endif
#else
	// D3D11 Uniforms
	#ifdef COMPILEVS
		cbuffer CustomVS : register(b6)
		{
			float3 cDetailTiling;
		};
	#endif
	
	#ifdef COMPILEPS
		cbuffer CustomPS : register(b6)
		{
			float cLayerScaling[numlayers];
		};
	#endif
#endif


// Samplers
#ifdef COMPILEPS
	#ifndef D3D11
		// D3D9 Samplers
		// D3D9 Does not support texture arrays.
		// TODO: Some sane alternative
	#else
		// D3D11 Samplers
		Texture2D tWeightMap0 : register(t0);
		Texture2D tWeightMap1 : register(t1);
		Texture2DArray tDetailMap2 : register(t2);
		SamplerState sWeightMap0 : register(s0);
		SamplerState sWeightMap1 : register(s1);
		SamplerState sDetailMap2 : register(s2);
		#ifdef BUMPMAP
			Texture2DArray tNormal3 : register(t3);
			SamplerState sNormal3 : register(s3);
		#endif
		
		#ifdef USEMASKTEXTURE
			Texture2D tMask4 : register(t4);
			SamplerState sMask4 : register(s4);
		#endif
	#endif
	
	// PS functions
	float4 SampleDiffuse(float3 detailtexcoord, int layer, float3 blend)
	{
		return tDetailMap2.Sample(sDetailMap2, float3(detailtexcoord.zy*cLayerScaling[layer], layer))*blend.x +
			tDetailMap2.Sample(sDetailMap2, float3(detailtexcoord.xy*cLayerScaling[layer], layer))*blend.z +
			tDetailMap2.Sample(sDetailMap2, float3(detailtexcoord.xz*cLayerScaling[layer], layer))*blend.y;
	}
	
	#ifdef BUMPMAP
	float3 SampleBump(float3 detailtexcoord, int layer, float3 blend)
	{
		return DecodeNormal(tNormal3.Sample(sNormal3, float3(detailtexcoord.zy*cLayerScaling[layer], layer)))*blend.x+
			DecodeNormal(tNormal3.Sample(sNormal3, float3(detailtexcoord.xy*cLayerScaling[layer], layer)))*blend.z+
			DecodeNormal(tNormal3.Sample(sNormal3, float3(detailtexcoord.xz*cLayerScaling[layer], layer)))*blend.y;
	}
	#endif

#endif

void VS(float4 iPos : POSITION,
    #if !defined(BILLBOARD) && !defined(TRAILFACECAM)
        float3 iNormal : NORMAL,
    #endif
	float2 iTexCoord : TEXCOORD0,
    #if (defined(BUMPMAP) || defined(TRAILFACECAM) || defined(TRAILBONE)) && !defined(BILLBOARD) && !defined(DIRBILLBOARD)
        float4 iTangent : TANGENT,
    #endif
    
    #ifdef INSTANCED
        float4x3 iModelInstance : TEXCOORD4,
    #endif
    #if defined(BILLBOARD) || defined(DIRBILLBOARD)
        float2 iSize : TEXCOORD1,
    #endif
    #ifndef BUMPMAP
        out float2 oTexCoord : TEXCOORD0,
    #else
        out float4 oTexCoord : TEXCOORD0,
        out float4 oTangent : TEXCOORD3,
    #endif
    out float3 oNormal : TEXCOORD1,
    out float4 oWorldPos : TEXCOORD2,
	out float3 oDetailTexCoord : TEXCOORD8,
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
        #ifdef ENVCUBEMAP
            out float3 oReflectionVec : TEXCOORD6,
        #endif
        #if defined(LIGHTMAP) || defined(AO)
            out float2 oTexCoord2 : TEXCOORD7,
        #endif
    #endif
    
    #if defined(D3D11) && defined(CLIPPLANE)
        out float oClip : SV_CLIPDISTANCE0,
    #endif
    out float4 oPos : OUTPOSITION)
{

    float4x3 modelMatrix = iModelMatrix;
    float3 worldPos = GetWorldPos(modelMatrix);
    oPos = GetClipPos(worldPos);
    oNormal = GetWorldNormal(modelMatrix);
    oWorldPos = float4(worldPos, GetDepth(oPos));
	oDetailTexCoord = worldPos.xyz / cDetailTiling;

    #if defined(D3D11) && defined(CLIPPLANE)
        oClip = dot(oPos, cClipPlane);
    #endif

    #ifdef BUMPMAP
        float4 tangent = GetWorldTangent(modelMatrix);
        float3 bitangent = cross(tangent.xyz, oNormal) * tangent.w;
        oTexCoord = float4(GetTexCoord(iTexCoord), bitangent.xy);
        oTangent = float4(tangent.xyz, bitangent.z);
    #else
        oTexCoord = GetTexCoord(iTexCoord);
    #endif

    #ifdef PERPIXEL
        // Per-pixel forward lighting
        float4 projWorldPos = float4(worldPos.xyz, 1.0);

        #ifdef SHADOW
            // Shadow projection: transform from world space to shadow space
            GetShadowPos(projWorldPos, oNormal, oShadowPos);
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
        #if defined(LIGHTMAP) || defined(AO)
            // If using lightmap, disregard zone ambient light
            // If using AO, calculate ambient in the PS
            oVertexLight = float3(0.0, 0.0, 0.0);
            oTexCoord2 = iTexCoord2;
        #else
            oVertexLight = GetAmbient(GetZonePos(worldPos));
        #endif

        #ifdef NUMVERTEXLIGHTS
            for (int i = 0; i < NUMVERTEXLIGHTS; ++i)
                oVertexLight += GetVertexLight(i, worldPos, oNormal) * cVertexLights[i * 3].rgb;
        #endif
        
        oScreenPos = GetScreenPos(oPos);

        #ifdef ENVCUBEMAP
            oReflectionVec = worldPos - cCameraPos;
        #endif
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
	float3 iDetailTexCoord : TEXCOORD8,
    #ifdef PERPIXEL
        #ifdef SHADOW
            float4 iShadowPos[NUMCASCADES] : TEXCOORD4,
        #endif
        #ifdef SPOTLIGHT
            float4 iSpotPos : TEXCOORD5,
        #endif
        #ifdef POINTLIGHT
            float3 iCubeMaskVec : TEXCOORD5,
        #endif
    #else
        float3 iVertexLight : TEXCOORD4,
        float4 iScreenPos : TEXCOORD5,
        #ifdef ENVCUBEMAP
            float3 iReflectionVec : TEXCOORD6,
        #endif
        #if defined(LIGHTMAP) || defined(AO)
            float2 iTexCoord2 : TEXCOORD7,
        #endif
    #endif
    #if defined(D3D11) && defined(CLIPPLANE)
        float iClip : SV_CLIPDISTANCE0,
    #endif
    #ifdef PREPASS
        out float4 oDepth : OUTCOLOR1,
    #endif
    #ifdef DEFERRED
        out float4 oAlbedo : OUTCOLOR1,
        out float4 oNormal : OUTCOLOR2,
        out float4 oDepth : OUTCOLOR3,
    #endif
    out float4 oColor : OUTCOLOR0)
{
	float4 weights0 = tWeightMap0.Sample(sWeightMap0, iTexCoord.xy);
	float4 weights1 = tWeightMap1.Sample(sWeightMap1, iTexCoord.xy);
	
	#ifdef USEMASKTEXTURE
		float3 mask=tMask4.Sample(sMask4, iTexCoord.xy).rgb;
	#endif
	
	#ifdef TRIPLANAR
		float3 nrm = normalize(iNormal);
		float3 blending=abs(nrm);
		blending = normalize(max(blending, 0.00001));
		float b=blending.x+blending.y+blending.z;
		blending=blending/b;
		
		float4 tex1=SampleDiffuse(iDetailTexCoord, 0, blending);
		float4 tex2=SampleDiffuse(iDetailTexCoord, 1, blending);
		float4 tex3=SampleDiffuse(iDetailTexCoord, 2, blending);
		float4 tex4=SampleDiffuse(iDetailTexCoord, 3, blending);
		float4 tex5=SampleDiffuse(iDetailTexCoord, 4, blending);
		float4 tex6=SampleDiffuse(iDetailTexCoord, 5, blending);
		float4 tex7=SampleDiffuse(iDetailTexCoord, 6, blending);
		float4 tex8=SampleDiffuse(iDetailTexCoord, 7, blending);
	
	#else
		float4 tex1=tDetailMap2.Sample(sDetailMap2, float3(iDetailTexCoord.xz*cLayerScaling[0], 0));
		float4 tex2=tDetailMap2.Sample(sDetailMap2, float3(iDetailTexCoord.xz*cLayerScaling[1], 1));
		float4 tex3=tDetailMap2.Sample(sDetailMap2, float3(iDetailTexCoord.xz*cLayerScaling[2], 2));
		float4 tex4=tDetailMap2.Sample(sDetailMap2, float3(iDetailTexCoord.xz*cLayerScaling[3], 3));
		float4 tex5=tDetailMap2.Sample(sDetailMap2, float3(iDetailTexCoord.xz*cLayerScaling[4], 4));
		float4 tex6=tDetailMap2.Sample(sDetailMap2, float3(iDetailTexCoord.xz*cLayerScaling[5], 5));
		float4 tex7=tDetailMap2.Sample(sDetailMap2, float3(iDetailTexCoord.xz*cLayerScaling[6], 6));
		float4 tex8=tDetailMap2.Sample(sDetailMap2, float3(iDetailTexCoord.xz*cLayerScaling[7], 7));
	#endif
	
	#ifndef SMOOTHBLEND
		float ma=max(tex1.a+weights0.r, max(tex2.a+weights0.g, max(tex3.a+weights0.b, max(tex4.a+weights0.a, max(tex5.a+weights1.r, max(tex6.a+weights1.g, max(tex7.a+weights1.b, tex8.a+weights1.a)))))))-0.2;
		float b1=max(0, tex1.a+weights0.r-ma);
		float b2=max(0, tex2.a+weights0.g-ma);
		float b3=max(0, tex3.a+weights0.b-ma);
		float b4=max(0, tex4.a+weights0.a-ma);
		float b5=max(0, tex5.a+weights1.r-ma);
		float b6=max(0, tex6.a+weights1.g-ma);
		float b7=max(0, tex7.a+weights1.b-ma);
		float b8=max(0, tex8.a+weights1.a-ma);
	#else
		float b1=weights0.r;
		float b2=weights0.g;
		float b3=weights0.b;
		float b4=weights0.a;
		float b5=weights1.r;
		float b6=weights1.g;
		float b7=weights1.b;
		float b8=weights1.a;
	#endif
	float bsum=b1+b2+b3+b4+b5+b6+b7+b8;
	float4 diffColor=(tex1*b1+tex2*b2+tex3*b3+tex4*b4+tex5*b5+tex6*b6+tex7*b7+tex8*b8)/bsum;
	
	#ifdef USEMASKTEXTURE
		diffColor.r=lerp(1.0, diffColor.r, mask.r);
		diffColor.g=lerp(1.0, diffColor.g, mask.g);
		diffColor.b=lerp(1.0, diffColor.b, mask.b);
	#endif

    // Get material specular albedo
    float3 specColor = cMatSpecColor.rgb;

    // Get normal
    #ifdef BUMPMAP
		float3x3 tbn = float3x3(iTangent.xyz, float3(iTexCoord.zw, iTangent.w), iNormal);
		#ifdef TRIPLANAR
		float3 bump1=SampleBump(iDetailTexCoord, 0, blending);
		float3 bump2=SampleBump(iDetailTexCoord, 1, blending);
		float3 bump3=SampleBump(iDetailTexCoord, 2, blending);
		float3 bump4=SampleBump(iDetailTexCoord, 3, blending);
		float3 bump5=SampleBump(iDetailTexCoord, 4, blending);
		float3 bump6=SampleBump(iDetailTexCoord, 5, blending);
		float3 bump7=SampleBump(iDetailTexCoord, 6, blending);
		float3 bump8=SampleBump(iDetailTexCoord, 7, blending);
		
		#else
			float3 bump1=DecodeNormal(tNormal3.Sample(sNormal3, float3(iDetailTexCoord.xz*cLayerScaling[0],0)));
			float3 bump2=DecodeNormal(tNormal3.Sample(sNormal3, float3(iDetailTexCoord.xz*cLayerScaling[1],1)));
			float3 bump3=DecodeNormal(tNormal3.Sample(sNormal3, float3(iDetailTexCoord.xz*cLayerScaling[2],2)));
			float3 bump4=DecodeNormal(tNormal3.Sample(sNormal3, float3(iDetailTexCoord.xz*cLayerScaling[3],3)));
			float3 bump5=DecodeNormal(tNormal3.Sample(sNormal3, float3(iDetailTexCoord.xz*cLayerScaling[4],4)));
			float3 bump6=DecodeNormal(tNormal3.Sample(sNormal3, float3(iDetailTexCoord.xz*cLayerScaling[5],5)));
			float3 bump7=DecodeNormal(tNormal3.Sample(sNormal3, float3(iDetailTexCoord.xz*cLayerScaling[6],6)));
			float3 bump8=DecodeNormal(tNormal3.Sample(sNormal3, float3(iDetailTexCoord.xz*cLayerScaling[7],7)));
		#endif
		
		
		float3 normal=mul(normalize(((bump1*b1+bump2*b2+bump3*b3+bump4*b4+bump5*b5+bump6*b6+bump7*b7+bump8*b8)/bsum)),tbn);
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
            lightColor = iSpotPos.w > 0.0 ? Sample2DProj(LightSpotMap, iSpotPos).rgb * cLightColor.rgb : 0.0;
        #elif defined(CUBEMASK)
            lightColor = SampleCube(LightCubeMap, iCubeMaskVec).rgb * cLightColor.rgb;
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
            finalColor += cAmbientColor.rgb * diffColor.rgb;
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
        #ifdef AO
            // If using AO, the vertex light ambient is black, calculate occluded ambient here
            finalColor += Sample2D(EmissiveMap, iTexCoord2).rgb * cAmbientColor.rgb * diffColor.rgb;
        #endif
        #ifdef ENVCUBEMAP
            finalColor += cMatEnvMapColor * SampleCube(EnvCubeMap, reflect(iReflectionVec, normal)).rgb;
        #endif
        #ifdef LIGHTMAP
            finalColor += Sample2D(EmissiveMap, iTexCoord2).rgb * diffColor.rgb;
        #endif
        #ifdef EMISSIVEMAP
            finalColor += cMatEmissiveColor * Sample2D(EmissiveMap, iTexCoord.xy).rgb;
        #else
            finalColor += cMatEmissiveColor;
        #endif

        oColor = float4(GetFog(finalColor, fogFactor), 1.0);
        oAlbedo = fogFactor * float4(diffColor.rgb, specIntensity);
        oNormal = float4(normal * 0.5 + 0.5, specPower);
        oDepth = iWorldPos.w;
    #else
        // Ambient & per-vertex lighting
        float3 finalColor = iVertexLight * diffColor.rgb;
        #ifdef AO
            // If using AO, the vertex light ambient is black, calculate occluded ambient here
            finalColor += Sample2D(EmissiveMap, iTexCoord2).rgb * cAmbientColor.rgb * diffColor.rgb;
        #endif

        #ifdef MATERIAL
            // Add light pre-pass accumulation result
            // Lights are accumulated at half intensity. Bring back to full intensity now
            float4 lightInput = 2.0 * Sample2DProj(LightBuffer, iScreenPos);
            float3 lightSpecColor = lightInput.a * lightInput.rgb / max(GetIntensity(lightInput.rgb), 0.001);

            finalColor += lightInput.rgb * diffColor.rgb + lightSpecColor * specColor;
        #endif

        #ifdef ENVCUBEMAP
            finalColor += cMatEnvMapColor * SampleCube(EnvCubeMap, reflect(iReflectionVec, normal)).rgb;
        #endif
        #ifdef LIGHTMAP
            finalColor += Sample2D(EmissiveMap, iTexCoord2).rgb * diffColor.rgb;
        #endif
        #ifdef EMISSIVEMAP
            finalColor += cMatEmissiveColor * Sample2D(EmissiveMap, iTexCoord.xy).rgb;
        #else
            finalColor += cMatEmissiveColor;
        #endif

        oColor = float4(GetFog(finalColor, fogFactor), diffColor.a);
    #endif
}
