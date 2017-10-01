#include "ShaderProgram.h"
#include "Shader.h"
#include "memory"

ShaderProgram::ShaderProgram()
{
	_programHandle = 0;
	_attachedShaders;
}

ShaderProgram::~ShaderProgram()
{
	DeleteProgram();
}

void ShaderProgram::CreateProgram()
{
	_programHandle = glCreateProgram();
}

void ShaderProgram::AttachShader(std::string path, GLenum type)
{
	std::unique_ptr<Shader> shader(new Shader);
	shader->CreateShader(path, type);
	_attachedShaders.push_back(std::move(shader));
}

void ShaderProgram::LinkProgram()
{

	glAttachShader(_programHandle, _attachedShaders.push_back); //Adjuntamos el vertex shader al manager 

	glLinkProgram(_programHandle); // Aseguramos que el vertex y fragment son compatibles por medio del proceso de linker 

	DeleteAndDetachShaders();
}

void ShaderProgram::Activate()
{
	glBindVertexArray(_programHandle);

}

void ShaderProgram::Deactivate()
{

	glBindVertexArray(0);

}


void ShaderProgram::SetAttribute(GLuint locationIndex, std::string name)
{
	glBindAttribLocation(_programHandle, locationIndex, name); 
}
void ShaderProgram::SetUniformf(std::string name, float value)
{
	glBindAttribLocation(_programHandle, 0, "VertexPosition");
}

void ShaderProgram::SetUniformf(std::string name, float x, float y)
{
	glBindAttribLocation(_programHandle, 0, "VertexPosition");
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z)
{
	glBindAttribLocation(_programHandle, 0, "VertexPosition");
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z, float w)
{
	glBindAttribLocation(_programHandle, 0, "VertexPosition");
}

void ShaderProgram::DeleteAndDetachShaders()
{
	glDetachShader(_attachedShaders.push_back, 0);
}

void ShaderProgram::DeleteProgram()
{
	DeleteAndDetachShaders();
	glDeleteProgram(_programHandle);
}
