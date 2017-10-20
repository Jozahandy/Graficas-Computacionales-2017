/*********************************************************
Materia:Gráficas computacionales
Fecha: 23/Octubre/2017
EXAMEN SEGUNDO PARCIAL 
Autor: Valeria Jozahandy Sánchez Álvarez
	   Diana Isabel Hernández María
Matricula: A01375042, A01375351
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

Mesh _mesh;
ShaderProgram _shaderProgram;
Transform _transform;
Transform _transform2;
Camera _camera;
float contador = 0.0f;
float contador2 = 0.0f;
float contador3 = 0.0;


void Initialize()
{
	std::vector<glm::vec3> positions;

	//Base 
	positions.push_back(glm::vec3(-1.0f, -1.0f, -1.0f)); //0
	positions.push_back(glm::vec3(1.0f, -1.0f, -1.0f)); //1
	positions.push_back(glm::vec3(1.0f, -1.0f, 1.0f)); //2
	positions.push_back(glm::vec3(-1.0f, -1.0f, 1.0f)); //3
														//Pico 
	positions.push_back(glm::vec3(0.0f, 1.0f, 0.0f)); //4

	std::vector<glm::vec3> colors;

	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f)); //0
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f)); //1
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f)); //2
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f)); //3
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f)); //4

	std::vector<unsigned int> indices;
	//Base 
	indices.push_back(0); indices.push_back(1); indices.push_back(2);
	indices.push_back(0); indices.push_back(2); indices.push_back(3);
	//Cara Frente
	indices.push_back(3); indices.push_back(2); indices.push_back(4);
	//Cara Derecha 
	indices.push_back(2); indices.push_back(1); indices.push_back(4);
	//Cara Izquierda
	indices.push_back(0); indices.push_back(3); indices.push_back(4);
	//Cara Atras 
	indices.push_back(1); indices.push_back(0); indices.push_back(4);

	_mesh.CreateMesh(5);
	_mesh.SetIndices(indices, GL_STATIC_DRAW);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);


	_shaderProgram.CreateProgram();
	_shaderProgram.AttachShader("Default.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("Default.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.LinkProgram();

	_transform.SetScale(3.0f, 3.0f, 3.0f); //Geometría 1

	_transform2.SetPosition(0.0f, 0.0f, 0.0f); //Geometría2
	_transform2.SetScale(0.5f, 0.5f, 0.5f); //Geometría2 


											//_camera.SetOrthographic(1.0f, 1.0f); Esto convierte la cámara en 2D
}

void GameLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpiamos el buffer de control y el de profundidad. Siempre hacerlo al inicio del frame

	_camera.SetPosition(0.0f, 0.0f, 25.0f);

	//Geometría 1
	_transform.Rotate(0.01f, 0.01f, 0.01f, true);
	float radio = 5.0f;
	float angulo = glm::radians(contador);
	float x = radio*(glm::cos(angulo));
	float y = radio*(glm::sin(angulo));
	float z = 0;

	_transform.SetPosition(x, y, z);
	contador = contador + 0.005f;


	//Geometría 2 
	_transform2.Rotate(-0.01f, -0.01f, -0.01f, true);

	float escala = 0.5f + contador2;

	if (escala <= 1.0f & contador3 == 0.0f) {
		_transform2.SetScale(escala, escala, escala);
		contador2 = contador2 + 0.00005f;
	}
	else if (escala >= 1.0f & contador3 == 0.0f) {
		contador3 = 1.0f;
	}
	else if (escala >= 0.25f & contador3 == 1.0f) {
		_transform2.SetScale(escala, escala, escala);
		contador2 = contador2 - 0.00005f;
	}
	else if (escala <= 0.25f & contador3 == 1.0f) {
		contador3 = 0.0f;
	}

	_shaderProgram.Activate();

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _transform.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES); //Geometría 1

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _transform2.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES); //Geometría 2

	_shaderProgram.Deactivate();

	glutSwapBuffers(); //Cuando terminamos de renderear cambiamos los buffers 
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
	Initialize();
	glutMainLoop();

	return 0;
}