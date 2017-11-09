#include "Dephtbuffer.h"

#include "Texture2D.h"

#include <IL/il.h>

#include <iostream>



Dephtbuffer::Dephtbuffer()

{

	_framebuffer = 0;

	_depthmap = 0;

	_resolution = 0;

}



Dephtbuffer::~Dephtbuffer()

{

	glDeleteFramebuffers(1, &_framebuffer);

	glDeleteTextures(1, &_depthmap);

}



void Dephtbuffer::Create(int resolution)

{

	_resolution = resolution;

	glGenTextures(1, &_depthmap);

	glBindTexture(GL_TEXTURE_2D, _depthmap);



	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);



	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, _resolution, _resolution, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);



	glGenFramebuffers(1, &_framebuffer);

	glBindFramebuffer(GL_FRAMEBUFFER, _framebuffer);



	glDrawBuffer(GL_NONE);

	glReadBuffer(GL_NONE);



	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, _depthmap, 0);



	glBindFramebuffer(GL_FRAMEBUFFER, 0);

}



void Dephtbuffer::Bind()

{

	glBindFramebuffer(GL_FRAMEBUFFER, _framebuffer);

	glViewport(0, 0, _resolution, _resolution);

}



void Dephtbuffer::Unbind()

{



	glBindFramebuffer(GL_FRAMEBUFFER, 0);



}



void Dephtbuffer::BindDephtMap()

{

	glBindTexture(GL_TEXTURE_2D, _depthmap);

}



void Dephtbuffer::UnbindDephtMap()

{

	glBindTexture(GL_TEXTURE_2D, 0);

}