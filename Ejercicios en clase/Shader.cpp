/*********************************************************
Materia:Gráficas computacionales
Fecha: 02/Octubre/2017
Autor: Valeria Jozahandy Sánchez álvarez
Matricula: A01375042
*********************************************************/
#include "Shader.h"
#include "InputFile.h"

InputFile ifile;

Shader::Shader()
{
	_shaderHandle = 0;
}

Shader::~Shader()
{
	glDeleteShader(_shaderHandle);
}

void Shader::CreateShader(std::string path, GLenum type)
{
	ifile.Read(path);
	std::string vertexSource = ifile.GetContents();
	_shaderHandle = glCreateShader(type);
	const GLchar*vertexSource_c = (const GLchar*)vertexSource.c_str();
	glShaderSource(_shaderHandle, 1, &vertexSource_c, nullptr);
	glCompileShader(_shaderHandle);

}

GLuint Shader::GetHandle()
{
	return _shaderHandle;
}
