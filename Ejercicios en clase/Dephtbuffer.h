#pragma once

#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>

class Dephtbuffer

{

public:
	Dephtbuffer();

	~Dephtbuffer();

	void Create(int resolution);
	void Bind();
	void Unbind();
	void BindDephtMap();
	void UnbindDephtMap();

private:

	GLuint _framebuffer;
	GLuint _depthmap;
	GLsizei _resolution;

};

