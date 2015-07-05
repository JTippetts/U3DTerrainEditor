#include "Uniforms.glsl"
#include "Samplers.glsl"
#include "Transform.glsl"
#include "ScreenPos.glsl"
#include "Lighting.glsl"
#include "Fog.glsl"

#ifdef BUMPMAP
	varying vec4 vTexCoord;
    varying vec4 vTangent;
#else
    varying vec2 vTexCoord;
#endif

//varying vec2 vTexCoord;
varying vec2 vDetailTexCoord;
varying vec3 vNormal;
varying vec4 vWorldPos;
#ifdef PERPIXEL
    #ifdef SHADOW
        varying vec4 vShadowPos[NUMCASCADES];
    #endif
    #ifdef SPOTLIGHT
        varying vec4 vSpotPos;
    #endif
    #ifdef POINTLIGHT
        varying vec3 vCubeMaskVec;
    #endif
#else
    varying vec3 vVertexLight;
    varying vec4 vScreenPos;
    #ifdef ENVCUBEMAP
        varying vec3 vReflectionVec;
    #endif
    #if defined(LIGHTMAP) || defined(AO)
        varying vec2 vTexCoord2;
    #endif
#endif

uniform sampler2D sWeightMap0;
uniform sampler2D sWeightMap1;
uniform sampler2D sDetailMap2;

#ifdef BUMPMAP
	uniform sampler2D sNormal3;
#endif

#ifdef USEMASKTEXTURE
uniform sampler2D sMask4;
#endif

uniform vec2 cDetailTiling;
uniform vec4 cPackTexFactors;

#ifdef COMPILEPS
float mipmapLevel(vec2 uv, float textureSize)
{
    vec2 dx = dFdx(uv * textureSize);
    vec2 dy = dFdy(uv * textureSize);
    float d = max(dot(dx, dx), dot(dy, dy));
    return 0.5 * log2(d);
}

vec4 sampleTexturePackMipWrapped(sampler2D s, vec2 uv, vec2 tile, float lod)
{
 	/// estimate mipmap/LOD level
	//float lod = mipmapLevel(uv, cPackTexFactors.z);
	//lod = clamp(lod, 0.0, cPackTexFactors.w);

	/// get width/height of the whole pack texture for the current lod level
	float size = pow(2.0, cPackTexFactors.w - lod);
	float sizex = size / cPackTexFactors.x; // width in pixels
	float sizey = size / cPackTexFactors.y; // height in pixels

	/// perform tiling
	uv = fract(uv);

	/// tweak pixels for correct bilinear filtering, and add offset for the wanted tile
	uv.x = uv.x * ((sizex * cPackTexFactors.x - 1.0) / sizex) + 0.5 / sizex + cPackTexFactors.x * tile.x;
	uv.y = uv.y * ((sizey * cPackTexFactors.y - 1.0) / sizey) + 0.5 / sizey + cPackTexFactors.y * tile.y;

    //return(tex2Dlod(s, uv, lod));
	return(textureLod(s,uv, lod));
}

vec4 sampleTerrain(sampler2D s, vec2 uv, vec2 tile, float lod)
{
	//return (tex2D(s,uv)*0.65+tex2D(s,uv*0.435)*0.35);
	//return tex2D(s,uv);
	return sampleTexturePackMipWrapped(s,uv,tile, lod);
}
#endif

void VS()
{
    mat4 modelMatrix = iModelMatrix;
    vec3 worldPos = GetWorldPos(modelMatrix);
    gl_Position = GetClipPos(worldPos);
    vNormal = GetWorldNormal(modelMatrix);
    vWorldPos = vec4(worldPos, GetDepth(gl_Position));
	
	#ifdef BUMPMAP
        vec3 tangent = GetWorldTangent(modelMatrix);
        vec3 bitangent = cross(tangent, vNormal) * iTangent.w;
        vTexCoord = vec4(GetTexCoord(iTexCoord), bitangent.xy);
        vTangent = vec4(tangent, bitangent.z);
    #else
        vTexCoord = GetTexCoord(iTexCoord);
    #endif
    //vTexCoord = GetTexCoord(iTexCoord);
    vDetailTexCoord = cDetailTiling * vTexCoord.xy;

    #ifdef PERPIXEL
        // Per-pixel forward lighting
        vec4 projWorldPos = vec4(worldPos, 1.0);

        #ifdef SHADOW
            // Shadow projection: transform from world space to shadow space
            for (int i = 0; i < NUMCASCADES; i++)
                vShadowPos[i] = GetShadowPos(i, projWorldPos);
        #endif

        #ifdef SPOTLIGHT
            // Spotlight projection: transform from world space to projector texture coordinates
            vSpotPos = cLightMatrices[0] * projWorldPos;
        #endif
    
        #ifdef POINTLIGHT
            vCubeMaskVec = mat3(cLightMatrices[0][0].xyz, cLightMatrices[0][1].xyz, cLightMatrices[0][2].xyz) * (worldPos - cLightPos.xyz);
        #endif
    #else
        // Ambient & per-vertex lighting
        #if defined(LIGHTMAP) || defined(AO)
            // If using lightmap, disregard zone ambient light
            // If using AO, calculate ambient in the PS
            vVertexLight = vec3(0.0, 0.0, 0.0);
            vTexCoord2 = iTexCoord2;
        #else
            vVertexLight = GetAmbient(GetZonePos(worldPos));
        #endif
        
        #ifdef NUMVERTEXLIGHTS
            for (int i = 0; i < NUMVERTEXLIGHTS; ++i)
                vVertexLight += GetVertexLight(i, worldPos, vNormal) * cVertexLights[i * 3].rgb;
        #endif
        
        vScreenPos = GetScreenPos(gl_Position);

        #ifdef ENVCUBEMAP
            vReflectionVec = worldPos - cCameraPos;
        #endif
    #endif
}

void PS()
{
    // Get material diffuse albedo
    vec4 weights0 = texture(sWeightMap0, vTexCoord.xy).rgba;
	vec4 weights1 = texture(sWeightMap1, vTexCoord.xy).rgba;
	
	#ifdef USEMASKTEXTURE
	float mask=texture(sMask4, vTexCoord.xy).r;
	#endif
	
	float lod = mipmapLevel(vDetailTexCoord, cPackTexFactors.z);
	lod = clamp(lod, 0.0, cPackTexFactors.w);
	
    vec4 tex1=sampleTerrain(sDetailMap2, vDetailTexCoord, vec2(0,0),lod);
	vec4 tex2=sampleTerrain(sDetailMap2, vDetailTexCoord, vec2(1,0),lod);
	vec4 tex3=sampleTerrain(sDetailMap2, vDetailTexCoord, vec2(2,0),lod);
	vec4 tex4=sampleTerrain(sDetailMap2, vDetailTexCoord, vec2(3,0),lod);
	
	vec4 tex5=sampleTerrain(sDetailMap2, vDetailTexCoord, vec2(0,1),lod);
	vec4 tex6=sampleTerrain(sDetailMap2, vDetailTexCoord, vec2(1,1),lod);
	vec4 tex7=sampleTerrain(sDetailMap2, vDetailTexCoord, vec2(2,1),lod);
	vec4 tex8=sampleTerrain(sDetailMap2, vDetailTexCoord, vec2(3,1),lod);
	
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
	vec4 diffColor=(tex1*b1+tex2*b2+tex3*b3+tex4*b4+tex5*b5+tex6*b6+tex7*b7+tex8*b8)/bsum;
	//vec4 diffColor=tex1;
	
	#ifdef USEMASKTEXTURE
	diffColor=mix(vec4(1,0.5,0.3, diffColor.a), diffColor, mask);
	#endif

    // Get material specular albedo
    vec3 specColor = cMatSpecColor.rgb;

    // Get normal
	#ifdef BUMPMAP
        mat3 tbn = mat3(vTangent.xyz, vec3(vTexCoord.zw, vTangent.w), vNormal);
		
		vec3 bump1=DecodeNormal(sampleTerrain(sNormal3, vDetailTexCoord, vec2(0,0), lod));
		vec3 bump2=DecodeNormal(sampleTerrain(sNormal3, vDetailTexCoord, vec2(1,0), lod));
		vec3 bump3=DecodeNormal(sampleTerrain(sNormal3, vDetailTexCoord, vec2(2,0), lod));
		vec3 bump4=DecodeNormal(sampleTerrain(sNormal3, vDetailTexCoord, vec2(3,0), lod));
		
		vec3 bump5=DecodeNormal(sampleTerrain(sNormal3, vDetailTexCoord, vec2(0,1), lod));
		vec3 bump6=DecodeNormal(sampleTerrain(sNormal3, vDetailTexCoord, vec2(1,1), lod));
		vec3 bump7=DecodeNormal(sampleTerrain(sNormal3, vDetailTexCoord, vec2(2,1), lod));
		vec3 bump8=DecodeNormal(sampleTerrain(sNormal3, vDetailTexCoord, vec2(3,1), lod));
		
		vec3 normal=normalize(mul((bump1*b1+bump2*b2+bump3*b3+bump4*b4+bump5*b5+bump6*b6+bump7*b7+bump8*b8)/bsum,tbn));
		
    #else
        vec3 normal = normalize(vNormal);
    #endif
    //vec3 normal = normalize(vNormal);
	

    // Get fog factor
    #ifdef HEIGHTFOG
        float fogFactor = GetHeightFogFactor(vWorldPos.w, vWorldPos.y);
    #else
        float fogFactor = GetFogFactor(vWorldPos.w);
    #endif

    #if defined(PERPIXEL)
        // Per-pixel forward lighting
        vec3 lightColor;
        vec3 lightDir;
        vec3 finalColor;
        
        float diff = GetDiffuse(normal, vWorldPos.xyz, lightDir);

        #ifdef SHADOW
            diff *= GetShadow(vShadowPos, vWorldPos.w);
        #endif
    
        #if defined(SPOTLIGHT)
            lightColor = vSpotPos.w > 0.0 ? texture2DProj(sLightSpotMap, vSpotPos).rgb * cLightColor.rgb : vec3(0.0, 0.0, 0.0);
        #elif defined(CUBEMASK)
            lightColor = textureCube(sLightCubeMap, vCubeMaskVec).rgb * cLightColor.rgb;
        #else
            lightColor = cLightColor.rgb;
        #endif
    
        #ifdef SPECULAR
            float spec = GetSpecular(normal, cCameraPosPS - vWorldPos.xyz, lightDir, cMatSpecColor.a);
            finalColor = diff * lightColor * (diffColor.rgb + spec * specColor * cLightColor.a);
        #else
            finalColor = diff * lightColor * diffColor.rgb;
        #endif

        #ifdef AMBIENT
            finalColor += cAmbientColor * diffColor.rgb;
            finalColor += cMatEmissiveColor;
            gl_FragColor = vec4(GetFog(finalColor, fogFactor), diffColor.a);
        #else
            gl_FragColor = vec4(GetLitFog(finalColor, fogFactor), diffColor.a);
        #endif
    #elif defined(PREPASS)
        // Fill light pre-pass G-Buffer
        float specPower = cMatSpecColor.a / 255.0;

        gl_FragData[0] = vec4(normal * 0.5 + 0.5, specPower);
        gl_FragData[1] = vec4(EncodeDepth(vWorldPos.w), 0.0);
    #elif defined(DEFERRED)
        // Fill deferred G-buffer
        float specIntensity = specColor.g;
        float specPower = cMatSpecColor.a / 255.0;

        gl_FragData[0] = vec4(GetFog(vVertexLight * diffColor.rgb, fogFactor), 1.0);
        gl_FragData[1] = fogFactor * vec4(diffColor.rgb, specIntensity);
        gl_FragData[2] = vec4(normal * 0.5 + 0.5, specPower);
        gl_FragData[3] = vec4(EncodeDepth(vWorldPos.w), 0.0);
    #else
        // Ambient & per-vertex lighting
        vec3 finalColor = vVertexLight * diffColor.rgb;

        #ifdef MATERIAL
            // Add light pre-pass accumulation result
            // Lights are accumulated at half intensity. Bring back to full intensity now
            vec4 lightInput = 2.0 * texture2DProj(sLightBuffer, vScreenPos);
            vec3 lightSpecColor = lightInput.a * lightInput.rgb / max(GetIntensity(lightInput.rgb), 0.001);

            finalColor += lightInput.rgb * diffColor.rgb + lightSpecColor * specColor;
        #endif

        gl_FragColor = vec4(GetFog(finalColor, fogFactor), diffColor.a);
    #endif
}
