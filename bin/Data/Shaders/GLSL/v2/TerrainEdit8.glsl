#define URHO3D_CUSTOM_MATERIAL_UNIFORMS
#define URHO3D_DISABLE_DIFFUSE_SAMPLING
#define URHO3D_DISABLE_NORMAL_SAMPLING
#define URHO3D_DISABLE_SPECULAR_SAMPLING
#define URHO3D_DISABLE_EMISSIVE_SAMPLING

#ifdef NORMALMAP
	#define URHO3D_VERTEX_NEED_TANGENT
#endif

#include "_Config.glsl"
#include "_Uniforms.glsl"

UNIFORM_BUFFER_BEGIN(4, Material)
    DEFAULT_MATERIAL_UNIFORMS
    UNIFORM(vec3 cDetailTiling)
	UNIFORM(vec4 cLayerScaling1)
	UNIFORM(vec4 cLayerScaling2)
	UNIFORM(vec4 cCursor)
	UNIFORM(float cAngle)
UNIFORM_BUFFER_END(4, Material)

VERTEX_OUTPUT_HIGHP(vec2 vTexCoord)

#include "_Material.glsl"

VERTEX_OUTPUT_HIGHP(vec3 vDetailTexCoord)
VERTEX_OUTPUT_HIGHP(vec3 vWorldPos)

uniform sampler2D sWeightMap0;
uniform sampler2D sWeightMap1;
uniform sampler2DArray sDetailMap2;
#ifdef NORMALMAP
	uniform sampler2DArray sNormal3;
#endif

#ifdef USEMASKTEXTURE
	uniform sampler2D sMask4;
#endif

#ifdef EDITING
	uniform sampler2D sAlpha5;
#endif

#ifdef URHO3D_VERTEX_SHADER
void main()
{
    VertexTransform vertexTransform = GetVertexTransform();
    FillVertexOutputs(vertexTransform);
    vDetailTexCoord = vertexTransform.position.xyz * cDetailTiling;
	vWorldPos = vertexTransform.position.xyz;
}
#endif

#ifdef URHO3D_PIXEL_SHADER

#ifdef EDITING
	float calcCursor(vec4 cursor, vec3 worldpos)
	{
		// cursor format:
		// x,y : position
		// z   : radius
		// w   : hardness
		float dx=cursor.x-worldpos.x;
		float dy=cursor.y-worldpos.z;
		float len=sqrt(dx*dx+dy*dy);
		float i=(len-cursor.z)/(cursor.w*cursor.z-cursor.z);
		i=clamp(i,0.0,1.0);
		return i;
	};

	vec2 calcCursorUV(vec4 cursor, vec3 worldpos, float angle)
	{
		float dx=(cursor.x-worldpos.x)/cursor.z;
		float dy=(cursor.y-worldpos.z)/cursor.z;
		dx=clamp(dx,-1.0,1.0);
		dy=clamp(dy,-1.0,1.0);
		dx=-dx;

		float rx=dx*cos(angle) - dy*sin(angle);
		float ry=dy*cos(angle) + dx*sin(angle);
		rx=rx*0.5+0.5;
		ry=ry*0.5+0.5;
		return vec2(rx,ry);
	};
#endif

#ifdef TRIPLANAR
#ifndef REDUCETILING
	vec4 SampleDiffuse(vec3 detailtexcoord, int layer, float layerscaling, vec3 blend)
	{
		return texture(sDetailMap2, vec3(detailtexcoord.zy*layerscaling, layer))*blend.x +
			texture(sDetailMap2, vec3(detailtexcoord.xy*layerscaling, layer))*blend.z +
			texture(sDetailMap2, vec3(detailtexcoord.xz*layerscaling, layer))*blend.y;
	}

	#ifdef NORMALMAP
		vec3 SampleNormal(vec3 detailtexcoord, int layer, float layerscaling, vec3 blend)
		{
		return DecodeNormal(texture(sNormal3, vec3(detailtexcoord.zy*layerscaling, layer)))*blend.x+
			DecodeNormal(texture(sNormal3, vec3(detailtexcoord.xy*layerscaling, layer)))*blend.z+
			DecodeNormal(texture(sNormal3, vec3(detailtexcoord.xz*layerscaling,layer)))*blend.y;
	}
	#endif
#else
	vec4 SampleDiffuse(vec3 detailtexcoord, int layer, float layerscaling, vec3 blend)
	{
		return (texture(sDetailMap2, vec3(detailtexcoord.zy*layerscaling, layer))+texture(sDetailMap2, vec3(detailtexcoord.zy*layerscaling*0.27, layer)))*blend.x*0.5 +
			(texture(sDetailMap2, vec3(detailtexcoord.xy*layerscaling, layer))+texture(sDetailMap2, vec3(detailtexcoord.xy*layerscaling*0.27, layer)))*blend.z*0.5 +
			(texture(sDetailMap2, vec3(detailtexcoord.xz*layerscaling, layer))+texture(sDetailMap2, vec3(detailtexcoord.xz*layerscaling*0.27, layer)))*blend.y*0.5;
	}

	#ifdef NORMALMAP
	vec3 SampleNormal(vec3 detailtexcoord, int layer, float layerscaling, vec3 blend)
	{
		return (DecodeNormal(texture(sNormal3, vec3(detailtexcoord.zy*layerscaling, layer)))+DecodeNormal(texture(sNormal3, vec3(detailtexcoord.zy*layerscaling*0.27, layer))))*blend.x*0.5+
			(DecodeNormal(texture(sNormal3, vec3(detailtexcoord.xy*layerscaling, layer)))+DecodeNormal(texture(sNormal3, vec3(detailtexcoord.xy*layerscaling*0.27, layer))))*blend.z*0.5+
			(DecodeNormal(texture(sNormal3, vec3(detailtexcoord.xz*layerscaling,layer)))+DecodeNormal(texture(sNormal3, vec3(detailtexcoord.xz*layerscaling*0.27,layer))))*blend.y*0.5;
	}
	#endif
#endif
#endif

void main()
{
    SurfaceData surfaceData;

    FillSurfaceCommon(surfaceData);
    FillSurfaceNormal(surfaceData);
    FillSurfaceMetallicRoughnessOcclusion(surfaceData);
    FillSurfaceReflectionColor(surfaceData);
    FillSurfaceBackground(surfaceData);
	
	#ifdef USEMASKTEXTURE
		vec3 mask=texture(sMask4, vTexCoord.xy).rgb;
	#endif
	
	vec4 weights0 = texture2D(sWeightMap0, vTexCoord);
	vec4 weights1 = texture2D(sWeightMap1, vTexCoord);
	
	#ifdef TRIPLANAR
		vec3 nrm = normalize(vNormal);
		vec3 blending=abs(nrm);
		blending = normalize(max(blending, 0.00001));
		float b=blending.x+blending.y+blending.z;
		blending=blending/b;

		vec4 tex1=SampleDiffuse(vDetailTexCoord, 0, cLayerScaling1.r, blending);
		vec4 tex2=SampleDiffuse(vDetailTexCoord, 1, cLayerScaling1.g, blending);
		vec4 tex3=SampleDiffuse(vDetailTexCoord, 2, cLayerScaling1.b, blending);
		vec4 tex4=SampleDiffuse(vDetailTexCoord, 3, cLayerScaling1.a, blending);
		vec4 tex5=SampleDiffuse(vDetailTexCoord, 4, cLayerScaling2.r, blending);
		vec4 tex6=SampleDiffuse(vDetailTexCoord, 5, cLayerScaling2.g, blending);
		vec4 tex7=SampleDiffuse(vDetailTexCoord, 6, cLayerScaling2.b, blending);
		vec4 tex8=SampleDiffuse(vDetailTexCoord, 7, cLayerScaling2.a, blending);
	#else
		#ifdef REDUCETILING
			vec4 tex1=(texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling1.r, 0))+texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling1.r*0.27, 0)))*0.5;
			vec4 tex2=(texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling1.g, 1))+texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling1.g*0.27, 1)))*0.5;
			vec4 tex3=(texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling1.b, 2))+texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling1.b*0.27, 2)))*0.5;
			vec4 tex4=(texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling1.a, 3))+texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling1.a*0.27, 3)))*0.5;
			vec4 tex5=(texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling2.r, 4))+texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling2.r*0.27, 4)))*0.5;
			vec4 tex6=(texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling2.g, 5))+texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling2.g*0.27, 5)))*0.5;
			vec4 tex7=(texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling2.b, 6))+texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling2.b*0.27, 6)))*0.5;
			vec4 tex8=(texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling2.a, 7))+texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling2.a*0.27, 7)))*0.5;
		#else
			vec4 tex1=texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling1.r, 0));
			vec4 tex2=texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling1.g, 1));
			vec4 tex3=texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling1.b, 2));
			vec4 tex4=texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling1.a, 3));
			vec4 tex5=texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling2.r, 4));
			vec4 tex6=texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling2.g, 5));
			vec4 tex7=texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling2.b, 6));
			vec4 tex8=texture(sDetailMap2, vec3(vDetailTexCoord.xz*cLayerScaling2.a, 7));
		#endif
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
	diffColor.a=1.0;
	
	#ifdef USEMASKTEXTURE
		diffColor.r=mix(1.0, diffColor.r, mask.r);
		diffColor.g=mix(1.0, diffColor.g, mask.g);
		diffColor.b=mix(1.0, diffColor.b, mask.b);
	#endif
	
	#ifdef NORMALMAP
        mediump mat3 tbn = mat3(vTangent.xyz, vec3(vBitangentXY.xy, vTangent.w), vNormal);
		#ifdef TRIPLANAR
		vec3 bump1=SampleNormal(vDetailTexCoord, 0, cLayerScaling1.r, blending);
		vec3 bump2=SampleNormal(vDetailTexCoord, 1, cLayerScaling1.g, blending);
		vec3 bump3=SampleNormal(vDetailTexCoord, 2, cLayerScaling1.b, blending);
		vec3 bump4=SampleNormal(vDetailTexCoord, 3, cLayerScaling1.a, blending);
		vec3 bump5=SampleNormal(vDetailTexCoord, 4, cLayerScaling2.r, blending);
		vec3 bump6=SampleNormal(vDetailTexCoord, 5, cLayerScaling2.g, blending);
		vec3 bump7=SampleNormal(vDetailTexCoord, 6, cLayerScaling2.b, blending);
		vec3 bump8=SampleNormal(vDetailTexCoord, 7, cLayerScaling2.a, blending);
		#else
			#ifdef REDUCETILING
				vec3 bump1=(DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling1.r,0)))+DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling1.r*0.27,0))))*0.5;
				vec3 bump2=(DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling1.g,1)))+DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling1.g*0.27,1))))*0.5;
				vec3 bump3=(DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling1.b,2)))+DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling1.b*0.27,2))))*0.5;
				vec3 bump4=(DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling1.a,3)))+DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling1.a*0.27,3))))*0.5;
				vec3 bump5=(DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling2.r,4)))+DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling2.r*0.27,4))))*0.5;
				vec3 bump6=(DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling2.g,5)))+DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling2.g*0.27,5))))*0.5;
				vec3 bump7=(DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling2.b,6)))+DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling2.b*0.27,6))))*0.5;
				vec3 bump8=(DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling2.a,7)))+DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling2.a*0.27,7))))*0.5;
			#else
				vec3 bump1=DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling1.r,0)));
				vec3 bump2=DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling1.g,1)));
				vec3 bump3=DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling1.b,2)));
				vec3 bump4=DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling1.a,3)));
				vec3 bump5=DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling2.r,4)));
				vec3 bump6=DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling2.g,5)));
				vec3 bump7=DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling2.b,6)));
				vec3 bump8=DecodeNormal(texture(sNormal3, vec3(vDetailTexCoord.xz*cLayerScaling2.a,7)));
			#endif
		#endif

		vec3 normal=tbn*normalize(((bump1*b1+bump2*b2+bump3*b3+bump4*b4+bump5*b5+bump6*b6+bump7*b7+bump8*b8)/bsum));

    #else
        vec3 normal = normalize(vNormal);
    #endif
	
	surfaceData.albedo = GammaToLightSpaceAlpha(cMatDiffColor) * GammaToLightSpaceAlpha(diffColor);
	surfaceData.normal = normal;
	
	#ifdef URHO3D_SURFACE_NEED_AMBIENT
		surfaceData.emission = GammaToLightSpace(cMatEmissiveColor);
	#endif
	
	//half3 finalColor = GetFinalColor(surfaceData);
	//gl_FragColor.rgb = ApplyFog(finalColor, surfaceData.fogFactor);
	//gl_FragColor.a = GetFinalAlpha(surfaceData);
	
	half3 surfaceColor = GetSurfaceColor(surfaceData);
    half surfaceAlpha = GetSurfaceAlpha(surfaceData);
    gl_FragColor = GetFragmentColorAlpha(surfaceColor, surfaceAlpha, surfaceData.fogFactor);
	
	#ifdef EDITING
		float j=calcCursor(cCursor, vWorldPos);
		float alpha=texture2D(sAlpha5, calcCursorUV(cCursor, vWorldPos, cAngle)).r;
		gl_FragColor = mix(gl_FragColor, vec4(1,1,1,1), j*0.75*alpha);
	#endif
}
#endif
