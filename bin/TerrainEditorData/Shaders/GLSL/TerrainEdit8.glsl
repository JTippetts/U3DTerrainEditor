#include "Uniforms.glsl"
#include "Samplers.glsl"
#include "Transform.glsl"
#include "ScreenPos.glsl"
#include "Lighting.glsl"
#include "Fog.glsl"

const int numblends=2;
const int numlayers=numblends*4;

#ifdef BUMPMAP
	varying vec4 vTexCoord;
    varying vec4 vTangent;
#else
    varying vec2 vTexCoord;
#endif

//varying vec2 vTexCoord;
varying vec3 vDetailTexCoord;
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
uniform sampler2DArray sDetailMap2;

#ifdef BUMPMAP
	uniform sampler2DArray sNormal3;
#endif

#ifdef USEMASKTEXTURE
	uniform sampler2D sMask4;
#endif

uniform vec3 cDetailTiling;
//uniform vec4 cLayerScaling1;
//uniform vec4 cLayerScaling2;
uniform float cLayerScaling[numlayers];

#ifdef COMPILEPS
vec4 SampleDiffuse(vec3 detailtexcoord, int layer, vec3 blend)
{
	return texture(sDetailMap2, vec3(detailtexcoord.zy*cLayerScaling[layer], layer))*blend.x +
		texture(sDetailMap2, vec3(detailtexcoord.xy*cLayerScaling[layer], layer))*blend.z +
		texture(sDetailMap2, vec3(detailtexcoord.xz*cLayerScaling[layer], layer))*blend.y;
}

#ifdef BUMPMAP
vec3 SampleBump(vec3 detailtexcoord, int layer, vec3 blend)
{
	return DecodeNormal(texture(sNormal3, vec3(detailtexcoord.zy*cLayerScaling[layer], layer)))*blend.x+
		DecodeNormal(texture(sNormal3, vec3(detailtexcoord.xy*cLayerScaling[layer], layer)))*blend.z+
		DecodeNormal(texture(sNormal3, vec3(detailtexcoord.xz*cLayerScaling[layer],layer)))*blend.y;
}
#endif
#endif

void VS()
{
    mat4 modelMatrix = iModelMatrix;
    vec3 worldPos = GetWorldPos(modelMatrix);
    gl_Position = GetClipPos(worldPos);
    vNormal = GetWorldNormal(modelMatrix);
    vWorldPos = vec4(worldPos, GetDepth(gl_Position));
	
	#ifdef BUMPMAP
        vec4 tangent = GetWorldTangent(modelMatrix);
        vec3 bitangent = cross(tangent.xyz, vNormal) * tangent.w;
        vTexCoord = vec4(GetTexCoord(iTexCoord), bitangent.xy);
        vTangent = vec4(tangent.xyz, bitangent.z);
    #else
        vTexCoord = GetTexCoord(iTexCoord);
    #endif
	
    vDetailTexCoord = worldPos.xyz / cDetailTiling;

    #ifdef PERPIXEL
        // Per-pixel forward lighting
        vec4 projWorldPos = vec4(worldPos, 1.0);

        #ifdef SHADOW
            // Shadow projection: transform from world space to shadow space
            for (int i = 0; i < NUMCASCADES; i++)
                vShadowPos[i] = GetShadowPos(i, vNormal, projWorldPos);
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
    vec4 weights0 = texture(sWeightMap0, vTexCoord.xy);
	vec4 weights1 = texture(sWeightMap1, vTexCoord.xy);
	
	#ifdef USEMASKTEXTURE
		vec3 mask=texture(sMask4, vTexCoord.xy).rgb;
	#endif
	
	#ifdef TRIPLANAR
	
	vec3 nrm = normalize(vNormal);
	vec3 blending=abs(nrm);
	blending = normalize(max(blending, 0.00001));
	float b=blending.x+blending.y+blending.z;
	blending=blending/b;
	
	vec4 tex1=SampleDiffuse(vDetailTexCoord, 0, blending);
	vec4 tex2=SampleDiffuse(vDetailTexCoord, 1, blending);
	vec4 tex3=SampleDiffuse(vDetailTexCoord, 2, blending);
	vec4 tex4=SampleDiffuse(vDetailTexCoord, 3, blending);
	vec4 tex5=SampleDiffuse(vDetailTexCoord, 4, blending);
	vec4 tex6=SampleDiffuse(vDetailTexCoord, 5, blending);
	vec4 tex7=SampleDiffuse(vDetailTexCoord, 6, blending);
	vec4 tex8=SampleDiffuse(vDetailTexCoord, 7, blending);
	
	#else
		vec4 tex1=texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling[0], 0));
		vec4 tex2=texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling[1], 1));
		vec4 tex3=texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling[2], 2));
		vec4 tex4=texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling[3], 3));
		vec4 tex5=texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling[4], 4));
		vec4 tex6=texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling[5], 5));
		vec4 tex7=texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling[6], 6));
		vec4 tex8=texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling[7], 7));
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
	vec4 diffColor=(tex1*b1+tex2*b2+tex3*b3+tex4*b4+tex5*b5+tex6*b6+tex7*b7+tex8*b8)/bsum;
	//vec4 diffColor=tex1;
	
	#ifdef USEMASKTEXTURE
	diffColor.r=mix(1.0, diffColor.r, mask.r);
	diffColor.g=mix(1.0, diffColor.g, mask.g);
	diffColor.b=mix(1.0, diffColor.b, mask.b);
	#endif

    // Get material specular albedo
    vec3 specColor = cMatSpecColor.rgb;

    // Get normal
	#ifdef BUMPMAP
        mat3 tbn = mat3(vTangent.xyz, vec3(vTexCoord.zw, vTangent.w), vNormal);
		
		#ifdef TRIPLANAR
		vec3 bump1=SampleBump(vDetailTexCoord, 0, blending);
		vec3 bump2=SampleBump(vDetailTexCoord, 1, blending);
		vec3 bump3=SampleBump(vDetailTexCoord, 2, blending);
		vec3 bump4=SampleBump(vDetailTexCoord, 3, blending);
		vec3 bump5=SampleBump(vDetailTexCoord, 4, blending);
		vec3 bump6=SampleBump(vDetailTexCoord, 5, blending);
		vec3 bump7=SampleBump(vDetailTexCoord, 6, blending);
		vec3 bump8=SampleBump(vDetailTexCoord, 7, blending);
		#else
			vec3 bump1=DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling[0],0)));
			vec3 bump2=DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling[1],1)));
			vec3 bump3=DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling[2],2)));
			vec3 bump4=DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling[3],3)));
			vec3 bump5=DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling[4],4)));
			vec3 bump6=DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling[5],5)));
			vec3 bump7=DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling[6],6)));
			vec3 bump8=DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling[7],7)));
		#endif
		
		vec3 normal=tbn*normalize(((bump1*b1+bump2*b2+bump3*b3+bump4*b4+bump5*b5+bump6*b6+bump7*b7+bump8*b8)/bsum));
		
    #else
        vec3 normal = normalize(vNormal);
    #endif
    //vec3 normal = normalize(vNormal);
	

    #ifdef HEIGHTFOG
        float fogFactor = GetHeightFogFactor(vWorldPos.w, vWorldPos.y);
    #else
        float fogFactor = GetFogFactor(vWorldPos.w);
    #endif

    #if defined(PERPIXEL)
        // Per-pixel forward lighting
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
            finalColor += cAmbientColor.rgb * diffColor.rgb;
            finalColor += cMatEmissiveColor.rgb;
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

        vec3 finalColor = vVertexLight * diffColor.rgb;
        #ifdef AO
            // If using AO, the vertex light ambient is black, calculate occluded ambient here
            finalColor += texture2D(sEmissiveMap, vTexCoord2).rgb * cAmbientColor * diffColor.rgb;
        #endif

        #ifdef ENVCUBEMAP
            finalColor += cMatEnvMapColor * textureCube(sEnvCubeMap, reflect(vReflectionVec, normal)).rgb;
        #endif
        #ifdef LIGHTMAP
            finalColor += texture2D(sEmissiveMap, vTexCoord2).rgb * diffColor.rgb;
        #endif
        #ifdef EMISSIVEMAP
            finalColor += cMatEmissiveColor * texture2D(sEmissiveMap, vTexCoord.xy).rgb;
        #else
            finalColor += cMatEmissiveColor;
        #endif

        gl_FragData[0] = vec4(GetFog(finalColor, fogFactor), 1.0);
        gl_FragData[1] = fogFactor * vec4(diffColor.rgb, specIntensity);
        gl_FragData[2] = vec4(normal * 0.5 + 0.5, specPower);
        gl_FragData[3] = vec4(EncodeDepth(vWorldPos.w), 0.0);
    #else
        // Ambient & per-vertex lighting
        vec3 finalColor = vVertexLight * diffColor.rgb;
        #ifdef AO
            // If using AO, the vertex light ambient is black, calculate occluded ambient here
            finalColor += texture2D(sEmissiveMap, vTexCoord2).rgb * cAmbientColor.rgb * diffColor.rgb;
        #endif
        
        #ifdef MATERIAL
            // Add light pre-pass accumulation result
            // Lights are accumulated at half intensity. Bring back to full intensity now
            vec4 lightInput = 2.0 * texture2DProj(sLightBuffer, vScreenPos);
            vec3 lightSpecColor = lightInput.a * lightInput.rgb / max(GetIntensity(lightInput.rgb), 0.001);

            finalColor += lightInput.rgb * diffColor.rgb + lightSpecColor * specColor;
        #endif

        #ifdef ENVCUBEMAP
            finalColor += cMatEnvMapColor * textureCube(sEnvCubeMap, reflect(vReflectionVec, normal)).rgb;
        #endif
        #ifdef LIGHTMAP
            finalColor += texture2D(sEmissiveMap, vTexCoord2).rgb * diffColor.rgb;
        #endif
        #ifdef EMISSIVEMAP
            finalColor += cMatEmissiveColor * texture2D(sEmissiveMap, vTexCoord.xy).rgb;
        #else
            finalColor += cMatEmissiveColor;
        #endif

        gl_FragColor = vec4(GetFog(finalColor, fogFactor), diffColor.a);
    #endif
}
