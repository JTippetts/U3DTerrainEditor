#include "Uniforms.glsl"
#include "Samplers.glsl"
#include "Transform.glsl"

#ifdef VSM_SHADOW
    varying vec4 vTexCoord;
#else
    varying vec2 vTexCoord;
#endif

uniform vec4 cHeightData;  // terrain width, terrain height, spacing.x, spacing.y
uniform sampler2D sHeightMap1;
uniform sampler2D sCoverMap2;

void VS()
{
    mat4 modelMatrix = iModelMatrix;
    vec3 worldPos = GetWorldPos(modelMatrix);

	vec2 htuv=vec2(worldPos.x/(cHeightData.x)+0.5, 1.0-(worldPos.z/(cHeightData.y)+0.5));

	vec4 htt=textureLod(sHeightMap1, htuv, 0.0);
	vec4 cov=textureLod(sCoverMap2, htuv, 0.0);
	float vx=cov.r*2.0-1.0;
	float vz=cov.b*2.0-1.0;
	worldPos.x=worldPos.x+vx*cHeightData.w;
	worldPos.z=worldPos.z+vz*cHeightData.w;
	float htscale=cHeightData.w*255.0;
	float ht=htt.r*htscale + htt.g;

	float dx=worldPos.x - cCameraPos.x;
	float dz=worldPos.z - cCameraPos.z;
	float dist=sqrt(dx*dx+dz*dz);
	dist=(dist-30.0)/(0.7*30.0-30.0);
	dist=clamp(dist,0.0,1.0);
	worldPos.y=worldPos.y*dist*cov.g + ht;

    gl_Position = GetClipPos(worldPos);
    #ifdef VSM_SHADOW
        vTexCoord = vec4(GetTexCoord(iTexCoord), gl_Position.z, gl_Position.w);
    #else
        vTexCoord = GetTexCoord(iTexCoord);
    #endif
}

void PS()
{
    #ifdef ALPHAMASK
        float alpha = texture2D(sDiffMap, vTexCoord.xy).a;
        if (alpha < 0.5)
            discard;
    #endif

    #ifdef VSM_SHADOW
        float depth = vTexCoord.z / vTexCoord.w * 0.5 + 0.5;
        gl_FragColor = vec4(depth, depth * depth, 1.0, 1.0);
    #else
        gl_FragColor = vec4(1.0);
    #endif
}
