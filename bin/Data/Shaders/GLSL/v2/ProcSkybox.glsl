

/*
Procedural Sky Shader adapted to rbfx, based on code from

https://github.com/shff/opengl_sky

MIT License

Copyright (c) 2019 Silvio Henrique Ferreira

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef UNLIT
    #define UNLIT
#endif

#define URHO3D_CUSTOM_MATERIAL_UNIFORMS

#define SIMPLEX_NOISE_FUNCTION

#include "_Config.glsl"
#include "_Uniforms.glsl"

UNIFORM_BUFFER_BEGIN(4, Material)
    DEFAULT_MATERIAL_UNIFORMS
    UNIFORM(float cTimeOfDay)
	UNIFORM(float cCloudTime)
	UNIFORM(float cCirrus)
	UNIFORM(float cCumulus)
	UNIFORM(float cCumulusBrightness)
	UNIFORM(float cBr)
	UNIFORM(float cBm)
	UNIFORM(float cG)
UNIFORM_BUFFER_END(4, Material)

#include "_Samplers.glsl"
#include "_VertexLayout.glsl"

#include "_VertexTransform.glsl"
#include "_GammaCorrection.glsl"

VERTEX_OUTPUT_HIGHP(vec3 vTexCoord)
VERTEX_OUTPUT_HIGHP(vec3 vSun)



#ifdef URHO3D_VERTEX_SHADER
void main()
{
    mat4 modelMatrix = GetModelMatrix();
    vec4 worldPos = vec4(iPos.xyz, 0.0) * modelMatrix;
    worldPos.xyz += cCameraPos;
    worldPos.w = 1.0;
    gl_Position = worldPos * cViewProj;
    gl_Position.z = gl_Position.w;
    vTexCoord = normalize(iPos.xyz);
	vSun = vec3(0.0, sin(cTimeOfDay * 0.2617993875), cos(cTimeOfDay * 0.2617993875));
}
#endif

#ifdef URHO3D_PIXEL_SHADER

#include "noise3D.glsl"

const mat3 m = mat3(0.0, 1.60,  1.20, -1.6, 0.72, -0.96, -1.2, -0.96, 1.28);
float fbm(vec3 p)
{
	float f = 0.0;
	f += snoise(p) / 2; p = m * p * 1.0;
	f += snoise(p) / 4; p = m * p * 1.1;
	f += snoise(p) / 6; p = m * p * 1.2;
	f += snoise(p) / 12; p = m * p * 1.3;
	f += snoise(p) / 24;
	return f;
}
  
  
void main()
{
    // gl_FragColor = GammaToLightSpaceAlpha(cMatDiffColor) * DiffMap_ToLight(textureCube(sDiffCubeMap, vTexCoord));
	vec3 pos=normalize(vTexCoord);
	vec3 fsun=vSun;
	const vec3 nitrogen = vec3(0.650, 0.570, 0.475);
	float Br=cBr;
	float Bm=cBm;
	float g=cG;
	float cirrus=cCirrus;
	float cumulus=cCumulus;
	
    vec3 Kr = Br / pow(nitrogen, vec3(4.0));
    vec3 Km = Bm / pow(nitrogen, vec3(0.84));
	
	vec4 color;
	
	if (pos.y < 0) pos.y=0;

    // Atmosphere Scattering
    float mu = dot(normalize(pos), normalize(fsun));
    float rayleigh = 3.0 / (8.0 * 3.14) * (1.0 + mu * mu);
    vec3 mie = (Kr + Km * (1.0 - g * g) / (2.0 + g * g) / pow(1.0 + g * g - 2.0 * g * mu, 1.5)) / (Br + Bm);

    vec3 day_extinction = exp(-exp(-((pos.y + fsun.y * 4.0) * (exp(-pos.y * 16.0) + 0.1) / 80.0) / Br) * (exp(-pos.y * 16.0) + 0.1) * Kr / Br) * exp(-pos.y * exp(-pos.y * 8.0 ) * 4.0) * exp(-pos.y * 2.0) * 4.0;
    vec3 night_extinction = vec3(1.0 - exp(fsun.y)) * 0.2;
    vec3 extinction = mix(day_extinction, night_extinction, -fsun.y * 0.2 + 0.5);
    color.rgb = rayleigh * mie * extinction;

    // Cirrus Clouds
    float density = smoothstep(1.0 - cirrus, 1.0, fbm(pos.xyz / pos.y * 2.0 + cCloudTime * 0.05)) * 0.3;
    color.rgb = mix(color.rgb, extinction * 4.0, density * max(pos.y, 0.0));

    // Cumulus Clouds
    for (int i = 0; i < 3; i++)
    {
      float density = smoothstep(1.0 - cumulus, 1.0, fbm((0.7 + float(i) * 0.01) * pos.xyz / pos.y + cCloudTime * 0.3));
      color.rgb = mix(color.rgb, extinction * density * cCumulusBrightness, min(density*1.5, 1.0) * max(pos.y, 0.0));
    }

    // Dithering Noise
    color.rgb += snoise(pos * 1000) * 0.01;
	color.a=1;
	
	gl_FragColor=GammaToLightSpaceAlpha(color);
}
#endif
