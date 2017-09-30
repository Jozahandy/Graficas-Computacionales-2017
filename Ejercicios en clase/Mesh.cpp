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
	positions.push_back(glm::vec2(0.0f, 1.0f));
	positions.push_back(glm::vec2(0.0f, 0.5f));
	positions.push_back(glm::vec2(0.95f, 0.3f));
	positions.push_back(glm::vec2(0.45f, 0.18f));
	positions.push_back(glm::vec2(0.6f, -0.8f));
	positions.push_back(glm::vec2(0.3f, -0.4f));
	positions.push_back(glm::vec2(-0.6f, -0.8f));
	positions.push_back(glm::vec2(-0.3f, -0.4f));
	positions.push_back(glm::vec2(-0.95f, 0.3f));
	positions.push_back(glm::vec2(-0.45f, 0.18f));
	positions.push_back(glm::vec2(0.0f, 1.0f));
	positions.push_back(glm::vec2(0.0f, 0.5f));

}

void Mesh::SetColorAttribute(std::vector<glm::vec3> colors, GLenum usage, GLuint locationIndex)
{
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
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