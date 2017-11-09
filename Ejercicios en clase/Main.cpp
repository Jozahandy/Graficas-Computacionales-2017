/********************************************************
Materia: Gráficas Computacionales
Fecha: 13 de noviembre del 2017
Autores: A01375042 Valeria Jozahandy Sánchez Álvarez
		 A01375351 Diana Isabel Hernández María
*********************************************************/


#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
#include "Camera.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include "Texture2D.h"
#include "Dephtbuffer.h"


Mesh _mesh;
ShaderProgram _shaderProgramDepth;
ShaderProgram _shaderProgram;
ShaderProgram _shaderProgramMix;
Transform _transform;
Transform _transform2;
Camera _camera;
Camera _lightCamera;
Texture2D _myTexture;
Texture2D _myTexture2;
Texture2D _myTexture3;
Dephtbuffer _depthBuffer;



void Initialize()

{

	std::vector<glm::vec3> positions;
	//Cara Frente 
	positions.push_back(glm::vec3(-1.0f, -1.0f, 1.0f)); //0
	positions.push_back(glm::vec3(1.0f, -1.0f, 1.0f)); //1
	positions.push_back(glm::vec3(1.0f, 1.0f, 1.0f)); //2
	positions.push_back(glm::vec3(-1.0, 1.0f, 1.0f)); //3

	//Cara Derecha
	positions.push_back(glm::vec3(1.0f, -1.0f, 1.0f)); //4
	positions.push_back(glm::vec3(1.0f, -1.0f, -1.0f)); //5
	positions.push_back(glm::vec3(1.0f, 1.0f, -1.0f)); //6
	positions.push_back(glm::vec3(1.0f, 1.0f, 1.0f)); //7

	//Cara Izquierda 
	positions.push_back(glm::vec3(-1.0f, -1.0f, -1.0f)); //8
	positions.push_back(glm::vec3(-1.0f, -1.0f, 1.0f)); //9
	positions.push_back(glm::vec3(-1.0f, 1.0f, 1.0f)); //10
	positions.push_back(glm::vec3(-1.0f, 1.0f, -1.0f)); //11

	//Cara Atras 
	positions.push_back(glm::vec3(1.0f, -1.0f, -1.0f)); //12
	positions.push_back(glm::vec3(-1.0f, -1.0f, -1.0f)); //13
	positions.push_back(glm::vec3(-1.0f, 1.0f, -1.0f)); //14
	positions.push_back(glm::vec3(1.0f, 1.0f, -1.0f)); //15

	//Cara Arriba 
	positions.push_back(glm::vec3(-1.0f, 1.0f, 1.0f)); //16
	positions.push_back(glm::vec3(1.0f, 1.0f, 1.0f)); //17
	positions.push_back(glm::vec3(1.0f, 1.0f, -1.0f)); //18
	positions.push_back(glm::vec3(-1.0f, 1.0f, -1.0f)); //19

	//Cara Abajo
	positions.push_back(glm::vec3(-1.0f, -1.0f, -1.0f)); //20
	positions.push_back(glm::vec3(1.0f, -1.0f, -1.0f)); //21
	positions.push_back(glm::vec3(1.0f, -1.0f, 1.0f)); //22
	positions.push_back(glm::vec3(-1.0f, -1.0f, 1.0f)); //23


	std::vector<glm::vec3> colors;

	//Cara Frente 
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));

	//Cara Derecha
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

	//Cara Izquierda 
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));

	//Cara Atras
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));

	//Cara Arriba
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));

	//Cara Abajo
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));


	std::vector<unsigned int> indices;
	indices.push_back(0); indices.push_back(1); indices.push_back(2);
	indices.push_back(0); indices.push_back(2); indices.push_back(3);

	//Cara Derecha

	indices.push_back(4); indices.push_back(5); indices.push_back(6);
	indices.push_back(4); indices.push_back(6); indices.push_back(7);
	
	//Cara Izquierda
	indices.push_back(8); indices.push_back(9); indices.push_back(10);
	indices.push_back(8); indices.push_back(10); indices.push_back(11);

	//Cara Atras
	indices.push_back(12); indices.push_back(13); indices.push_back(14);
	indices.push_back(12); indices.push_back(14); indices.push_back(15);

	//Cara Arriba
	indices.push_back(16); indices.push_back(17); indices.push_back(18);
	indices.push_back(16); indices.push_back(18); indices.push_back(19);

	//Cara Abajo
	indices.push_back(20); indices.push_back(21); indices.push_back(22);
	indices.push_back(20); indices.push_back(22); indices.push_back(23);


	std::vector<glm::vec3>Normal;

	//Cara Frente 
	Normal.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, 1.0f));

	//Cara Derecha 
	Normal.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

	//Cara Izquierda 
	Normal.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));

	//Cara Atras
	Normal.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, -1.0f));

	//Cara Arriba 
	Normal.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, 1.0f, 0.0f));

	//Cara Abajo 
	Normal.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, -1.0f, 0.0f));

	std::vector<glm::vec2>Textura;

	//Cara Frente 
	Textura.push_back(glm::vec2(0.0f, 0.0f));
	Textura.push_back(glm::vec2(1.0f, 0.0f));
	Textura.push_back(glm::vec2(1.0f, 1.0f));
	Textura.push_back(glm::vec2(0.0f, 1.0f));

	//Cara Derecha
	Textura.push_back(glm::vec2(0.0f, 0.0f));
	Textura.push_back(glm::vec2(1.0f, 0.0f));
	Textura.push_back(glm::vec2(1.0f, 1.0f));
	Textura.push_back(glm::vec2(0.0f, 1.0f));

	//Cara Izquierda 
	Textura.push_back(glm::vec2(0.0f, 0.0f));
	Textura.push_back(glm::vec2(1.0f, 0.0f));
	Textura.push_back(glm::vec2(1.0f, 1.0f));
	Textura.push_back(glm::vec2(0.0f, 1.0f));

	//Cara Atras
	Textura.push_back(glm::vec2(0.0f, 0.0f));
	Textura.push_back(glm::vec2(1.0f, 0.0f));
	Textura.push_back(glm::vec2(1.0f, 1.0f));
	Textura.push_back(glm::vec2(0.0f, 1.0f));

	//Cara Arriba 
	Textura.push_back(glm::vec2(0.0f, 0.0f));
	Textura.push_back(glm::vec2(1.0f, 0.0f));
	Textura.push_back(glm::vec2(1.0f, 1.0f));
	Textura.push_back(glm::vec2(0.0f, 1.0f));

	//Cara Abajo 
	Textura.push_back(glm::vec2(0.0f, 0.0f));
	Textura.push_back(glm::vec2(1.0f, 0.0f));
	Textura.push_back(glm::vec2(1.0f, 1.0f));
	Textura.push_back(glm::vec2(0.0f, 1.0f));


	_mesh.CreateMesh(24);
	_mesh.SetIndices(indices, GL_STATIC_DRAW);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetNormalAttribute(Normal, GL_STATIC_DRAW, 1);
	_mesh.SetTexCoordAttribute(Textura, GL_STATIC_DRAW, 2);



	//Configuracion de camara y buffer de profundidad 

	_depthBuffer.Create(2048);
	_lightCamera.SetPosition(-5.0f, 5.0f, 5.0f);
	_lightCamera.SetRotation(-30.0f, 0.0f, 0.0f);
	_lightCamera.SetOrthographic(20.0f, 1.0f);


	_shaderProgramDepth.CreateProgram();
	_shaderProgramDepth.AttachShader("Depth.vert", GL_VERTEX_SHADER);
	_shaderProgramDepth.AttachShader("Depth.frag", GL_FRAGMENT_SHADER);
	_shaderProgramDepth.SetAttribute(0, "VertexPosition");

	_shaderProgramDepth.LinkProgram();

	//Shader ShadowMapping 2 texturas 
	_shaderProgram.CreateProgram();
	_shaderProgram.AttachShader("ShadowMapping.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("ShadowMapping.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexNormal");
	_shaderProgram.SetAttribute(2, "VertexTexCoord");
	_shaderProgram.LinkProgram();



	_shaderProgram.Activate();
	_shaderProgram.SetUniformf("LightColor", glm::vec3(1.0f, 1.0f, 1.0f));
	_shaderProgram.SetUniformf("LightPosition", _lightCamera.GetPosition());
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("ShadowMap", 1);
	_shaderProgram.Deactivate();

	_myTexture.LoadTexture("Caja.jpg");
	_myTexture2.LoadTexture("Dante.png");



	//Shader ShadowMapping 1 textura

	_shaderProgramMix.CreateProgram();
	_shaderProgramMix.AttachShader("ShadowMappingMix.vert", GL_VERTEX_SHADER);
	_shaderProgramMix.AttachShader("ShadowMappingMix.frag", GL_FRAGMENT_SHADER);
	_shaderProgramMix.SetAttribute(0, "VertexPosition");
	_shaderProgramMix.SetAttribute(1, "VertexNormal");
	_shaderProgramMix.SetAttribute(2, "VertexTexCoord");
	_shaderProgramMix.LinkProgram();



	_shaderProgramMix.Activate();
	_shaderProgramMix.SetUniformf("LightColor", glm::vec3(1.0f, 1.0f, 1.0f));
	_shaderProgramMix.SetUniformf("LightPosition", _lightCamera.GetPosition());
	_shaderProgramMix.SetUniformi("DiffuseTexture", 0);
	_shaderProgramMix.SetUniformi("DiffuseTexture2", 1);
	_shaderProgramMix.SetUniformi("ShadowMap", 2);
	_shaderProgramMix.Deactivate();


	_myTexture3.LoadTexture("Piso.jpg");

	_transform.SetPosition(0.0f, -1.0f, 0.0f);
	_transform.SetScale(15.0f, 0.5f, 15.0f);
	_transform2.SetPosition(0.0f, 1.25f, 0.0f);

}



void GameLoop()

{

	_camera.SetPosition(0.0f, 3.0f, 10.0f);
	_camera.SetRotation(-20.0f, 0.0f, 0.0f);
	_transform2.Rotate(0.1f, 0.1f, 0.1f, true);



	//PRIMER RENDER 

	_depthBuffer.Bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_shaderProgramDepth.Activate();



	//Cubo 
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _lightCamera.GetViewProjection()* _transform2.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);

	//Piso
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _lightCamera.GetViewProjection()* _transform.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);


	_shaderProgramDepth.Deactivate();
	_depthBuffer.Unbind();

	glViewport(0, 0, 400, 400);

	//SEGUNDO RENDER 

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Cubo 
	_shaderProgramMix.Activate();
	_shaderProgramMix.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform2.GetModelMatrix()))));
	_shaderProgramMix.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _transform2.GetModelMatrix());
	_shaderProgramMix.SetUniformf("cameraPosition", _camera.GetPosition());
	_shaderProgramMix.SetUniformMatrix("ModelMatrix", _transform2.GetModelMatrix());
	_shaderProgramMix.SetUniformMatrix("LightVPMatrix", _lightCamera.GetViewProjection());


	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_myTexture2.Bind();
	glActiveTexture(GL_TEXTURE2);
	_depthBuffer.BindDephtMap();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE2);
	_depthBuffer.UnbindDephtMap();
	glActiveTexture(GL_TEXTURE1);
	_myTexture2.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_myTexture.Unbind();


	_shaderProgramMix.Deactivate();



	//Piso 
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _transform.GetModelMatrix());
	_shaderProgram.SetUniformf("cameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightCamera.GetViewProjection());

	glActiveTexture(GL_TEXTURE0);
	_myTexture3.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDephtMap();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDephtMap();
	glActiveTexture(GL_TEXTURE0);
	_myTexture3.Unbind();

	_shaderProgram.Deactivate();

	glutSwapBuffers();

}


void Idle()
{
	glutPostRedisplay();
}

void ReshapeWindow(int width, int height)
{
	glViewport(0, 0, width, height);
}


int main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	glutInitContextVersion(4, 4);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Hello World GL");
	glutDisplayFunc(GameLoop);
	glutReshapeFunc(ReshapeWindow);
	glutIdleFunc(Idle);
	glewInit();

	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);// la venta de OpenGL.
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	std::cout << glGetString(GL_VERSION) << std::endl;

	ilInit();
	ilEnable(IL_ORIGIN_SET);
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);

	Initialize();
	glutMainLoop();

	return 0;
}
