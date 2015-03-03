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

float2 blendfactors(float4 texture1, float a1, float4 texture2, float a2)
{
	float depth = 0.2;
    float ma = max(texture1.a + a1, texture2.a + a2) - depth;

    float b1 = max(texture1.a + a1 - ma, 0);
    float b2 = max(texture2.a + a2 - ma, 0);
	return float2(b1,b2);
}

float4 blend(float4 texture1, float a1, float4 texture2, float a2)
{
    float2 b=blendfactors(texture1, a1, texture2, a2);

    return (texture1.rgba * b.x + texture2.rgba * b.y) / (b.x + b.y);
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
    float sumWeights = weights0.r + weights0.g + weights0.b + weights0.a + weights1.r + weights1.g + weights1.b + weights1.a;
    weights0 /= sumWeights;
	weights1 /= sumWeights;
	
	// Calculate lod
	float lod = mipmapLevel(iDetailTexCoord, cPackTexFactors.z);
	lod = clamp(lod, 0.0, cPackTexFactors.w);
	
	float4 tex1=sampleTerrain(sDetailMap1, iDetailTexCoord, float2(0,0),lod);
	float4 tex2=sampleTerrain(sDetailMap1, iDetailTexCoord, float2(1,0),lod);
	float4 tex3=sampleTerrain(sDetailMap1, iDetailTexCoord, float2(0,1),lod);
	float4 tex4=sampleTerrain(sDetailMap1, iDetailTexCoord, float2(1,1),lod);
	
	float4 tex5=sampleTerrain(sDetailMap2, iDetailTexCoord, float2(0,0),lod);
	float4 tex6=sampleTerrain(sDetailMap2, iDetailTexCoord, float2(1,0),lod);
	float4 tex7=sampleTerrain(sDetailMap2, iDetailTexCoord, float2(0,1),lod);
	float4 tex8=sampleTerrain(sDetailMap2, iDetailTexCoord, float2(1,1),lod);
	
	
	float2 b1=blendfactors(tex1,weights0.r,tex2,weights0.g);
	float2 b2=blendfactors(tex3,weights0.b,tex4,weights0.a);
	float2 b3=blendfactors(tex5,weights1.r,tex6,weights1.g);
	float2 b4=blendfactors(tex7,weights1.b,tex8,weights1.a);
	
	
	float4 c1=(tex1*b1.x + tex2*b1.y) / (b1.x+b1.y);
	float a1=weights0.r+weights0.g;
	float4 c2=(tex3*b2.x + tex4*b2.y) / (b2.x+b2.y);
	float a2=weights0.b+weights0.a;
	float4 c3=(tex5*b3.x + tex6*b3.y) / (b3.x+b3.y);
	float a3=weights1.r+weights1.g;
	float4 c4=(tex7*b4.x + tex8*b4.y) / (b4.x+b4.y);
	float a4=weights1.b+weights1.a;
	
	float2 b5=blendfactors(c1,a1,c2,a2);
	float4 c5=(c1*b5.x+c2*b5.y)/(b5.x+b5.y);
	float2 b6=blendfactors(c3,a3,c4,a4);
	float4 c6=(c3*b6.x+c4*b6.y)/(b6.x+b6.y);
	
	
	float2 b7=blendfactors(c5,a1+a2,c6,a3+a4);
	float4 diffColor=cMatDiffColor * ((c5*b7.x + c6*b7.y)/(b7.x+b7.y));
	//float4 diffColor=float4(0.5,0.5,0.5,1);
    
	#ifdef USEMASKTEXTURE
	diffColor=lerp(float4(1,0.5,0.3, diffColor.a), diffColor, mask);
	#endif

    // Get material specular albedo
    float3 specColor = cMatSpecColor.rgb;

    // Get normal
    #ifdef BUMPMAP
        float3x3 tbn = float3x3(iTangent.xyz, float3(iTexCoord.zw, iTangent.w), iNormal);
        
		float3 bump1=bump(sDetailMap1, iDetailTexCoord, tex1.a, float2(0,0),lod);
		float3 bump2=bump(sDetailMap1, iDetailTexCoord, tex2.a,float2(1,0),lod);
		float3 bump3=bump(sDetailMap1, iDetailTexCoord, tex3.a,float2(0,1),lod);
		float3 bump4=bump(sDetailMap1, iDetailTexCoord, tex4.a,float2(1,1),lod);
		
		float3 bump5=bump(sDetailMap2, iDetailTexCoord, tex5.a,float2(0,0),lod);
		float3 bump6=bump(sDetailMap2, iDetailTexCoord, tex6.a,float2(1,0),lod);
		float3 bump7=bump(sDetailMap2, iDetailTexCoord, tex7.a,float2(0,1),lod);
		float3 bump8=bump(sDetailMap2, iDetailTexCoord, tex8.a,float2(1,1),lod);
		
		float3 nc1=(bump1*b1.x + bump2*b1.y) / (b1.x+b1.y);
		float3 nc2=(bump3*b2.x + bump4*b2.y) / (b2.x+b2.y);
		float3 nc3=(bump5*b3.x + bump6*b3.y) / (b3.x+b3.y);
		float3 nc4=(bump7*b4.x + bump8*b4.y) / (b4.x+b4.y);
		float3 nc5=(nc1*b5.x + nc2*b5.y) / (b5.x+b5.y);
		float3 nc6=(nc3*b6.x + nc4*b6.y) / (b6.x+b6.y);
		float3 normal=normalize(mul((nc5*b7.x+nc6*b7.y)/(b7.x+b7.y),tbn));
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
