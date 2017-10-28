#version 330

in vec3 VertexPosition; 
in vec3 VertexColor; 
in vec3 VertexNormal;


out vec3 InterpolatedColor;
out vec3 PixelPosition;
out vec3 InterpolatedNormal;


uniform mat4 mvpMatrix;
uniform mat4 ModelMatrix;
uniform mat3 normalMatrix; // La matriz de normales es una matriz 3x3


void main()
{
	InterpolatedColor = VertexColor;
	gl_Position = mvpMatrix * vec4(VertexPosition, 1.0f);
	PixelPosition = vec3(ModelMatrix * vec4(VertexPosition, 1.0f));
	InterpolatedNormal = normalMatrix * VertexNormal;
}