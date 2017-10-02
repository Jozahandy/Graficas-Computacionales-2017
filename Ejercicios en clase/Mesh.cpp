/*********************************************************
Materia:Gráficas computacionales
Fecha: 02/Octubre/2017
Autor: Valeria Jozahandy Sánchez álvarez
Matricula: A01375042
*********************************************************/
#include "Mesh.h"


GLuint vao;


Mesh::Mesh()
{
	_vertexArrayObject = 0;
	_positionsVertexBufferObject = 0;
	_colorsVertexBufferObject = 0;
	_vertexCount = 0;
}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &_positionsVertexBufferObject);
	glDeleteBuffers(1, &_colorsVertexBufferObject);
	glDeleteVertexArrays(1, &_vertexArrayObject);

}

void Mesh::CreateMesh(GLint vertexCount)
{
	_vertexCount = vertexCount;
	glCreateVertexArrays(1, &_vertexArrayObject);
}

void Mesh::Draw(GLenum primitive)
{
	glBindVertexArray(vao);
	glDrawArrays(primitive, 0, _vertexCount);
	glBindVertexArray(0);
}

void Mesh::SetPositionAttribute(std::vector<glm::vec2> positions, GLenum usage, GLuint locationIndex)
{
	const GLsizeiptr TamañoP = sizeof(glm::vec2)*positions.size();
	const void * Data = positions.data(); 

	if (positions.push_back = 0 && TamañoP != _vertexCount) {
	}
	else
		SetAttributeData(_positionsVertexBufferObject, TamañoP, Data, usage, locationIndex, 2);
	

}

void Mesh::SetColorAttribute(std::vector<glm::vec3> colors, GLenum usage, GLuint locationIndex)
{

	const GLsizeiptr TamañoP = sizeof(glm::vec2)*colors.size();
	const void * Data = colors.data();
	SetAttributeData(_positionsVertexBufferObject, TamañoP, Data, usage, locationIndex, 3);

	if(colors.push_back = 0 || TamañoP!= _vertexCount) {
	}
	else 
		SetAttributeData(_positionsVertexBufferObject, TamañoP, Data, usage, locationIndex, 3);
	
}

void Mesh::SetAttributeData(GLuint& buffer, const GLsizeiptr size, const void* data, GLenum usage, GLuint locationIndex, const GLint components)
{
	if (&buffer != 0) {
		glDeleteBuffers(1, &buffer);
	}
	else
		glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
	glEnableVertexAttribArray(locationIndex);
	glVertexAttribPointer(locationIndex, components, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}
