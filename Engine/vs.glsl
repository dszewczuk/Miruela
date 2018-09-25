#version 330 core

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 uvCoord;

out vec2 fragmentUvCoord;

uniform mat4 trans;

void main()
{
	gl_Position = trans * vec4(vertexPosition, 1.0);
	fragmentUvCoord = uvCoord;
}