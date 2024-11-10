#version 330 core

out vec4 FragColor;

uniform vec3 rectangleColor;

void main()
{
	FragColor = vec4(rectangleColor, 1.0);
}
