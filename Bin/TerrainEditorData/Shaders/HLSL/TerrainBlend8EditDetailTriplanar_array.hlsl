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

#ifndef D3D11
	float mipmapLevel(float2 uv, float textureSize)
	{
		float2 dx = ddx(uv * textureSize);
		float2 dy = ddy(uv * textureSize);
		float d = max(dot(dx, dx), dot(dy, dy));
		return 0.5 * log2(d);
	}
	#ifdef COMPILEPS
		sampler2D sWeightMap0 : register(S0);
		sampler2D sWeightMap1 : register(S1);
		sampler2D sDetailMap : register(S2);
		#ifdef BUMPMAP
			sampler2D sNormal : register(S3);
		#endif
		sampler2D sMask : register(S4);
	#endif
	
	#ifdef COMPILEVS
	
	#endif
	uniform float3 cDetailTiling;
	uniform float cBumpStrength;
	uniform float4 cPackTexFactors;
#else
	#ifdef COMPILEPS
		Texture2D tWeightMap0 : register(t0);
		Texture2D tWeightMap1 : register(t1);
		Texture2DArray tDetailMap : register(t2);
		SamplerState sWeightMap0 : register(s0);
		SamplerState sWeightMap1 : register(s1);
		SamplerState sDetailMap : register(s2);
		#ifdef BUMPMAP
			Texture2DArray tNormal : register(t3);
			SamplerState sNormal : register(s3);
		#endif
		Texture2D tMask : register(t4);
		SamplerState sMask : register(s4);
	
	#endif
	
	#ifdef COMPILEVS
	
		cbuffer CustomVS : register(b6)
		{
			float3 cDetailTiling;
		};
	#endif
#endif



#ifdef COMPILEPS
	#ifndef D3D11

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


	#endif
#endif



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
    out float3 oDetailTexCoord : TEXCOORD10,
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
    #ifdef BUMPMAP
        float3 tangent = GetWorldTangent(modelMatrix);
        float3 bitangent = cross(tangent, oNormal) * iTangent.w;
        oTexCoord = float4(GetTexCoord(iTexCoord), bitangent.xy);
        oTangent = float4(tangent, bitangent.z);
    #else
        oTexCoord = GetTexCoord(iTexCoord);
    #endif
    oDetailTexCoord = worldPos.xyz / cDetailTiling;
	//oDetailTexCoord=float2(64,64)*oTexCoord;
	#if defined(D3D11) && defined(CLIPPLANE)
        oClip = dot(oPos, cClipPlane);
    #endif

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
    float3 iDetailTexCoord : TEXCOORD10,
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
        out float4 oDepth : OUTCOLOR1,
    #endif
    #ifdef DEFERRED
        out float4 oAlbedo : OUTCOLOR1,
        out float4 oNormal : OUTCOLOR2,
        out float4 oDepth : OUTCOLOR3,
    #endif
    out float4 oColor : OUTCOLOR0)
{
    // Get material diffuse albedo
	#ifndef D3D11
		float4 weights0 = tex2D(sWeightMap0, iTexCoord).rgba;
		float4 weights1 = tex2D(sWeightMap1, iTexCoord).rgba;
	#else
		float4 weights0=tWeightMap0.Sample(sWeightMap0, iTexCoord);
		float4 weights1=tWeightMap1.Sample(sWeightMap1, iTexCoord);
	#endif
	#ifdef USEMASKTEXTURE
		#ifndef D3D11
			float mask=tex2D(sMask, iTexCoord).r;
		#else
			float mask=tMask.Sample(sMask, iTexCoord).r;
		#endif
	#endif
	
	float3 nrm = normalize(iNormal);
	float3 blending=abs(nrm);
	blending = normalize(max(blending, 0.00001));
	float b=blending.x+blending.y+blending.z;
	blending=blending/b;
	
	#ifndef D3D11
		// Calculate lod
		float lod1 = mipmapLevel(iDetailTexCoord.zy, cPackTexFactors.z);
		lod1 = clamp(lod1, 0.0, cPackTexFactors.w);
		float lod2 = mipmapLevel(iDetailTexCoord.xy, cPackTexFactors.z);
		lod2 = clamp(lod2, 0.0, cPackTexFactors.w);
		float lod3 = mipmapLevel(iDetailTexCoord.xz, cPackTexFactors.z);
		lod3 = clamp(lod3, 0.0, cPackTexFactors.w);
	
		float4 tex1=sampleTerrain(sDetailMap, iDetailTexCoord.zy, float2(0,0), lod1)*blending.x +
			sampleTerrain(sDetailMap, iDetailTexCoord.xy, float2(0,0), lod2)*blending.z +
			sampleTerrain(sDetailMap, iDetailTexCoord.xz, float2(0,0), lod3)*blending.y;
		float4 tex2=sampleTerrain(sDetailMap, iDetailTexCoord.zy, float2(1,0), lod1)*blending.x +
			sampleTerrain(sDetailMap, iDetailTexCoord.xy, float2(1,0), lod2)*blending.z +
			sampleTerrain(sDetailMap, iDetailTexCoord.xz, float2(1,0), lod3)*blending.y;
		float4 tex3=sampleTerrain(sDetailMap, iDetailTexCoord.zy, float2(2,0), lod1)*blending.x +
			sampleTerrain(sDetailMap, iDetailTexCoord.xy, float2(2,0), lod2)*blending.z +
			sampleTerrain(sDetailMap, iDetailTexCoord.xz, float2(2,0), lod3)*blending.y;
		float4 tex4=sampleTerrain(sDetailMap, iDetailTexCoord.zy, float2(3,0), lod1)*blending.x +
			sampleTerrain(sDetailMap, iDetailTexCoord.xy, float2(3,0), lod2)*blending.z +
			sampleTerrain(sDetailMap, iDetailTexCoord.xz, float2(3,0), lod3)*blending.y;
		
		float4 tex5=sampleTerrain(sDetailMap, iDetailTexCoord.zy, float2(0,1), lod1)*blending.x +
			sampleTerrain(sDetailMap, iDetailTexCoord.xy, float2(0,1), lod2)*blending.z +
			sampleTerrain(sDetailMap, iDetailTexCoord.xz, float2(0,1), lod3)*blending.y;
		float4 tex6=sampleTerrain(sDetailMap, iDetailTexCoord.zy, float2(1,1), lod1)*blending.x +
			sampleTerrain(sDetailMap, iDetailTexCoord.xy, float2(1,1), lod2)*blending.z +
			sampleTerrain(sDetailMap, iDetailTexCoord.xz, float2(1,1), lod3)*blending.y;
		float4 tex7=sampleTerrain(sDetailMap, iDetailTexCoord.zy, float2(2,1), lod1)*blending.x +
			sampleTerrain(sDetailMap, iDetailTexCoord.xy, float2(2,1), lod2)*blending.z +
			sampleTerrain(sDetailMap, iDetailTexCoord.xz, float2(2,1), lod3)*blending.y;
		float4 tex8=sampleTerrain(sDetailMap, iDetailTexCoord.zy, float2(3,1), lod1)*blending.x +
			sampleTerrain(sDetailMap, iDetailTexCoord.xy, float2(3,1), lod2)*blending.z +
			sampleTerrain(sDetailMap, iDetailTexCoord.xz, float2(3,1), lod3)*blending.y;
	
	#else
	
		float4 tex1=tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.zy, 0))*blending.x +
			tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.xy, 0))*blending.z +
			tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.xz, 0))*blending.y;
		float4 tex2=tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.zy, 1))*blending.x +
			tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.xy, 1))*blending.z +
			tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.xz, 1))*blending.y;
		float4 tex3=tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.zy, 2))*blending.x +
			tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.xy, 2))*blending.z +
			tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.xz, 2))*blending.y;
		float4 tex4=tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.zy, 3))*blending.x +
			tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.xy, 3))*blending.z +
			tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.xz, 3))*blending.y;
		float4 tex5=tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.zy, 4))*blending.x +
			tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.xy, 4))*blending.z +
			tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.xz, 4))*blending.y;
		float4 tex6=tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.zy, 5))*blending.x +
			tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.xy, 5))*blending.z +
			tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.xz, 5))*blending.y;
		float4 tex7=tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.zy, 6))*blending.x +
			tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.xy, 6))*blending.z +
			tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.xz, 6))*blending.y;
		float4 tex8=tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.zy, 7))*blending.x +
			tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.xy, 7))*blending.z +
			tDetailMap.Sample(sDetailMap, float3(iDetailTexCoord.xz, 7))*blending.y;

	#endif
	
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
        
		#ifndef D3D11
		
		float3 bump1=DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.zy, float2(0,0), lod1))*blending.x +
			DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.xy, float2(0,0), lod2))*blending.z +
			DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.xz, float2(0,0), lod3))*blending.y;
		float3 bump2=DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.zy, float2(1,0), lod1))*blending.x +
			DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.xy, float2(1,0), lod2))*blending.z +
			DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.xz, float2(1,0), lod3))*blending.y;
		float3 bump3=DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.zy, float2(2,0), lod1))*blending.x +
			DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.xy, float2(2,0), lod2))*blending.z +
			DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.xz, float2(2,0), lod3))*blending.y;
		float3 bump4=DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.zy, float2(3,0), lod1))*blending.x +
			DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.xy, float2(3,0), lod2))*blending.z +
			DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.xz, float2(3,0), lod3))*blending.y;
			
		float3 bump5=DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.zy, float2(0,1), lod1))*blending.x +
			DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.xy, float2(0,1), lod2))*blending.z +
			DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.xz, float2(0,1), lod3))*blending.y;
		float3 bump6=DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.zy, float2(1,1), lod1))*blending.x +
			DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.xy, float2(1,1), lod2))*blending.z +
			DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.xz, float2(1,1), lod3))*blending.y;
		float3 bump7=DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.zy, float2(2,1), lod1))*blending.x +
			DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.xy, float2(2,1), lod2))*blending.z +
			DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.xz, float2(2,1), lod3))*blending.y;
		float3 bump8=DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.zy, float2(3,1), lod1))*blending.x +
			DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.xy, float2(3,1), lod2))*blending.z +
			DecodeNormal(sampleTerrain(sNormal, iDetailTexCoord.xz, float2(3,1), lod3))*blending.y;
		
		#else
			float3 bump1=DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.zy, 0)))*blending.x +
				DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.xy, 0)))*blending.z +
				DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.xz, 0)))*blending.y;
			float3 bump2=DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.zy, 1)))*blending.x +
				DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.xy, 1)))*blending.z +
				DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.xz, 1)))*blending.y;
			float3 bump3=DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.zy, 2)))*blending.x +
				DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.xy, 2)))*blending.z +
				DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.xz, 2)))*blending.y;
			float3 bump4=DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.zy, 3)))*blending.x +
				DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.xy, 3)))*blending.z +
				DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.xz, 3)))*blending.y;
			float3 bump5=DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.zy, 4)))*blending.x +
				DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.xy, 4)))*blending.z +
				DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.xz, 4)))*blending.y;
			float3 bump6=DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.zy, 5)))*blending.x +
				DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.xy, 5)))*blending.z +
				DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.xz, 5)))*blending.y;
			float3 bump7=DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.zy, 6)))*blending.x +
				DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.xy, 6)))*blending.z +
				DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.xz, 6)))*blending.y;
			float3 bump8=DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.zy, 7)))*blending.x +
				DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.xy, 7)))*blending.z +
				DecodeNormal(tNormal.Sample(sNormal, float3(iDetailTexCoord.xz, 7)))*blending.y;
		#endif
		
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
