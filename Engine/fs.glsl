#version 330 core

in vec2 fragmentUvCoord;

out vec4 color;

//uniform sampler2D fragmentTexture;

void main()
{
	color = vec4(1.0, 0.0, 0.0, 0.0);
	//color = texture(fragmentTexture, fragmentUvCoord);
}