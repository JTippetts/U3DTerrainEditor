#include "Uniforms.glsl"
#include "Samplers.glsl"
#include "Transform.glsl"

varying vec3 vTexCoord;
uniform vec4 cHeightData;  // terrain width, terrain height, spacing.x, spacing.y
uniform sampler2D sHeightMap1;
uniform sampler2D sCoverMap2;

void VS()
{
    mat4 modelMatrix = iModelMatrix;
    vec3 worldPos = GetWorldPos(modelMatrix);
	// Convert world coords to UV coords
	float tu=worldPos.x / cHeightData.z;
	float tv=worldPos.z / cHeightData.z;

	vec2 htuv=vec2((tu/cHeightData.x)+0.5, 1.0-((tv/cHeightData.y)+0.5));
	vec4 htt=textureLod(sHeightMap1, htuv, 0.0);
	vec4 cov=textureLod(sCoverMap2, htuv, 0.0);

	float vx=cov.r*2.0-1.0;
	float vz=cov.b*2.0-1.0;
	worldPos.x=worldPos.x+vx*cHeightData.w;
	worldPos.z=worldPos.z+vz*cHeightData.w;
	float htscale=cHeightData.w*255.0;
	float ht=htt.r*htscale*cov.g + htt.g*cHeightData.w;

	float dx=worldPos.x - cCameraPos.x;
	float dz=worldPos.z - cCameraPos.z;
	float dist=sqrt(dx*dx+dz*dz);
	dist=(dist-30.0)/(0.7*30.0-30.0);
	dist=clamp(dist,0.0,1.0);
	worldPos.y=worldPos.y*dist*cov.g + ht;
    gl_Position = GetClipPos(worldPos);
    vTexCoord = vec3(GetTexCoord(iTexCoord), GetDepth(gl_Position));
}

void PS()
{
    #ifdef ALPHAMASK
        float alpha = texture2D(sDiffMap, vTexCoord.xy).a;
        if (alpha < 0.5)
            discard;
    #endif

    gl_FragColor = vec4(EncodeDepth(vTexCoord.z), 1.0);
}
