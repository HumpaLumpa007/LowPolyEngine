#version 450

#extension GL_ARB_separate_shader_objects : enable
#extension GL_ARB_shading_language_420pack : enable

layout (location = 0) in vec3 inPos;
layout (location = 1) in vec3 inColor;

layout (binding = 0) uniform UboView 
{
	mat4 projection;
	mat4 view;
} uboView;

layout (binding = 1) uniform UboInstance 
{
	mat4 model; 
} uboInstance;

layout (location = 0) out vec3 outColor;
layout (location = 1) out vec4 outPos;

out gl_PerVertex 
{
	vec4 gl_Position;   
};

void main() 
{
	outColor = inColor;
	mat4 modelView = uboView.view * uboInstance.model;
	outPos = modelView * vec4(inPos, 1.0);
	gl_Position = uboView.projection * modelView * vec4(inPos, 1.0);
}
