#include "Uniforms.hlsl"
#include "Samplers.hlsl"
#include "Transform.hlsl"
#include "ScreenPos.hlsl"
#include "Fog.hlsl"

#ifndef D3D11

// D3D9 uniforms
uniform float2 cNoiseSpeed;
uniform float cNoiseTiling;
uniform float cNoiseStrength;
uniform float cFresnelPower;
uniform float3 cWaterTint;

#else

// D3D11 constant buffers
#ifdef COMPILEVS
cbuffer CustomVS : register(b6)
{
    float2 cNoiseSpeed;
    float cNoiseTiling;
}
#else
cbuffer CustomPS : register(b6)
{
    float cNoiseStrength;
    float cFresnelPower;
    float3 cWaterTint;
}
#endif

#endif

#ifdef COMPILEPS
	Texture2D tFlowMap2 : register(t2);
	SamplerState sFlowMap2 : register(s2);
	Texture2D tFoam3 : register(t3);
	SamplerState sFoam3 : register(s3);
#endif

void VS(float4 iPos : POSITION,
    float3 iNormal: NORMAL,
    float2 iTexCoord : TEXCOORD0,
    #ifdef INSTANCED
        float4x3 iModelInstance : TEXCOORD4,
    #endif
    out float4 oScreenPos : TEXCOORD0,
    out float2 oReflectUV : TEXCOORD1,
    out float2 oWaterUV : TEXCOORD2,
    out float3 oNormal : TEXCOORD3,
    out float4 oEyeVec : TEXCOORD4,
	out float2 oFlowUV : TEXCOORD5,
    #if defined(D3D11) && defined(CLIPPLANE)
        out float oClip : SV_CLIPDISTANCE0,
    #endif
    out float4 oPos : OUTPOSITION)
{
    float4x3 modelMatrix = iModelMatrix;
    float3 worldPos = GetWorldPos(modelMatrix);
    oPos = GetClipPos(worldPos);

    oScreenPos = GetScreenPos(oPos);
    // GetQuadTexCoord() returns a float2 that is OK for quad rendering; multiply it with output W
    // coordinate to make it work with arbitrary meshes such as the water plane (perform divide in pixel shader)
    oReflectUV = GetQuadTexCoord(oPos) * oPos.w;
    oWaterUV = iTexCoord * cNoiseTiling + cElapsedTime * cNoiseSpeed;
    oNormal = GetWorldNormal(modelMatrix);
    oEyeVec = float4(cCameraPos - worldPos, GetDepth(oPos));
	oFlowUV = GetTexCoord(iTexCoord);

    #if defined(D3D11) && defined(CLIPPLANE)
        oClip = dot(oPos, cClipPlane);
    #endif
}

void PS(
    float4 iScreenPos : TEXCOORD0,
    float2 iReflectUV : TEXCOORD1,
    float2 iWaterUV : TEXCOORD2,
    float3 iNormal : TEXCOORD3,
    float4 iEyeVec : TEXCOORD4,
	float2 iFlowUV : TEXCOORD5,
    #if defined(D3D11) && defined(CLIPPLANE)
        float iClip : SV_CLIPDISTANCE0,
    #endif
    out float4 oColor : OUTCOLOR0)
{
    float2 refractUV = iScreenPos.xy / iScreenPos.w;
    float2 reflectUV = iReflectUV.xy / iScreenPos.w;

    float2 noise = (Sample2D(NormalMap, iWaterUV).rg - 0.5) * cNoiseStrength;
    refractUV += noise;
    // Do not shift reflect UV coordinate upward, because it will reveal the clipping of geometry below water
    if (noise.y < 0.0)
        noise.y = 0.0;
    reflectUV += noise;

    float fresnel = pow(1.0 - saturate(dot(normalize(iEyeVec.xyz), iNormal)), cFresnelPower);
	float3 backColor = Sample2D(EnvMap, refractUV).rgb;
    float3 refractColor = backColor * cWaterTint;
    //float3 reflectColor = Sample2D(DiffMap, reflectUV).rgb;
	float3 reflectColor = cFogColor.rgb;
    float3 finalColor = lerp(refractColor, reflectColor, fresnel);

	float3 foamColor = tFoam3.Sample(sFoam3, iWaterUV.xy).rgb;
	float depthValue = (1.0-tFlowMap2.Sample(sFlowMap2, iFlowUV.xy).r);

	finalColor = finalColor + foamColor*depthValue;// mix(foamColor, finalColor, depthValue.r);
	finalColor = lerp(finalColor, backColor, depthValue*depthValue-0.01);

    oColor = float4(GetFog(finalColor, GetFogFactor(iEyeVec.w)), 1.0);
}
