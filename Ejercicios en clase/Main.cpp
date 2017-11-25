/********************************************************
Materia: Gráficas Computacionales
Fecha: 24 de noviembre de 2017
Autores:
A01375351 Diana Isabel Hernández María
A01375042 Valeria Jozahandy Sánchez Álvarez
*********************************************************/
//	.8 .2. .6 

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

Mesh _meshPalma;
Mesh _meshPiso;
Mesh _meshDedo;
ShaderProgram _shaderProgramDepth;
ShaderProgram _shaderProgram;
ShaderProgram _shaderProgramMix;
Transform _Piso;
Transform _Palma;
Transform _JoinPulBase;
Transform _JoinInBase;
Transform _JoinMedBase;
Transform _JoinAnBase;
Transform _PulgarBase;
Transform _IndiceBase;
Transform _MedioBase;
Transform _AnularBase;
Transform _JoinPul;
Transform _JoinIn;
Transform _JoinMed;
Transform _JoinAn;
Transform _Pulgar;
Transform _Indice;
Transform _Medio;
Transform _Anular;
Camera _camera;
Camera _lightCamera;
Texture2D _myTexture;
Texture2D _myTexture2;
Texture2D _myTexture3;
Dephtbuffer _depthBuffer;
float contador = 0.0f;
float contador2 = 0.0f;
float contador3 = 0.0f;
float contador4 = 0.0f;
float contadorAnular = 0.0f;
float contadorMed = 0.0f;
float contadorIn = 0.0f;
float contadorPul = 0.0f;

void Initialize()
{
	//PALMA 
	std::vector<glm::vec3> positionsPalma;
	//Cara Frente 
	positionsPalma.push_back(glm::vec3(-2.0f, -3.0f, 0.2f)); //0
	positionsPalma.push_back(glm::vec3(2.0f, -3.0f, 0.2f)); //1
	positionsPalma.push_back(glm::vec3(2.0f, 3.0f, 0.2f)); //2
	positionsPalma.push_back(glm::vec3(-2.0f, 3.0f, 0.2f)); //3
															//Cara Derecha1
	positionsPalma.push_back(glm::vec3(2.0f, -3.0f, 0.2f)); //4
	positionsPalma.push_back(glm::vec3(2.0f, -3.0f, -0.2f)); //5
	positionsPalma.push_back(glm::vec3(2.0f, 3.0f, -0.2f)); //6
	positionsPalma.push_back(glm::vec3(2.0f, 3.0f, 0.2f)); //7
														   //Cara Izquierda 
	positionsPalma.push_back(glm::vec3(-2.0f, -3.0f, -0.2f)); //8
	positionsPalma.push_back(glm::vec3(-2.0f, -3.0f, 0.2f)); //9
	positionsPalma.push_back(glm::vec3(-2.0f, 3.0f, 0.2f)); //10
	positionsPalma.push_back(glm::vec3(-2.0f, 3.0f, -0.2f)); //11
															 //Cara Atras 
	positionsPalma.push_back(glm::vec3(2.0f, -3.0f, -0.2f)); //12
	positionsPalma.push_back(glm::vec3(-2.0f, -3.0f, -0.2f)); //13
	positionsPalma.push_back(glm::vec3(-2.0f, 3.0f, -0.2f)); //14
	positionsPalma.push_back(glm::vec3(2.0f, 3.0f, -0.2f)); //15
															//Cara Arriba 
	positionsPalma.push_back(glm::vec3(-2.0f, 3.0f, 0.2f)); //16
	positionsPalma.push_back(glm::vec3(2.0f, 3.0f, 0.2f)); //17
	positionsPalma.push_back(glm::vec3(2.0f, 3.0f, -0.2f)); //18
	positionsPalma.push_back(glm::vec3(-2.0f, 3.0f, -0.2f)); //19
															 //Cara Abajo
	positionsPalma.push_back(glm::vec3(-2.0f, -3.0f, -0.2f)); //20
	positionsPalma.push_back(glm::vec3(2.0f, -3.0f, -0.2f)); //21
	positionsPalma.push_back(glm::vec3(2.0f, -3.0f, 0.2f)); //22
	positionsPalma.push_back(glm::vec3(-2.0f, -3.0f, 0.2f)); //23

															 //PISO 
	std::vector<glm::vec3> positionsPiso;
	//Cara Frente 
	positionsPiso.push_back(glm::vec3(-1.0f, -1.0f, 1.0f)); //0
	positionsPiso.push_back(glm::vec3(1.0f, -1.0f, 1.0f)); //1
	positionsPiso.push_back(glm::vec3(1.0f, 1.0f, 1.0f)); //2
	positionsPiso.push_back(glm::vec3(-1.0f, 1.0f, 1.0f)); //3
														   //Cara Derecha1
	positionsPiso.push_back(glm::vec3(1.0f, -1.0f, 1.0f)); //4
	positionsPiso.push_back(glm::vec3(1.0f, -1.0f, -1.0f)); //5
	positionsPiso.push_back(glm::vec3(1.0f, 1.0f, -1.0f)); //6
	positionsPiso.push_back(glm::vec3(1.0f, 1.0f, 1.0f)); //7
														  //Cara Izquierda 
	positionsPiso.push_back(glm::vec3(-1.0f, -1.0f, -1.0f)); //8
	positionsPiso.push_back(glm::vec3(-1.0f, -1.0f, 1.0f)); //9
	positionsPiso.push_back(glm::vec3(-1.0f, 1.0f, 1.0f)); //10
	positionsPiso.push_back(glm::vec3(-1.0f, 1.0f, -1.0f)); //11
															//Cara Atras 
	positionsPiso.push_back(glm::vec3(1.0f, -1.0f, -1.0f)); //12
	positionsPiso.push_back(glm::vec3(-1.0f, -1.0f, -1.0f)); //13
	positionsPiso.push_back(glm::vec3(-1.0f, 1.0f, -1.0f)); //14
	positionsPiso.push_back(glm::vec3(1.0f, 1.0f, -1.0f)); //15
														   //Cara Arriba 
	positionsPiso.push_back(glm::vec3(-1.0f, 1.0f, 1.0f)); //16
	positionsPiso.push_back(glm::vec3(1.0f, 1.0f, 1.0f)); //17
	positionsPiso.push_back(glm::vec3(1.0f, 1.0f, -1.0f)); //18
	positionsPiso.push_back(glm::vec3(-1.0f, 1.0f, -1.0f)); //19
															//Cara Abajo
	positionsPiso.push_back(glm::vec3(-1.0f, -1.0f, -1.0f)); //20
	positionsPiso.push_back(glm::vec3(1.0f, -1.0f, -1.0f)); //21
	positionsPiso.push_back(glm::vec3(1.0f, -1.0f, 1.0f)); //22
	positionsPiso.push_back(glm::vec3(-1.0f, -1.0f, 1.0f)); //23

															//DEDO														
	std::vector<glm::vec3> positionsDedo;
	//Cara Frente 
	positionsDedo.push_back(glm::vec3(-0.5f, -0.9f, 0.2f)); //0
	positionsDedo.push_back(glm::vec3(0.5f, -0.9f, 0.2f)); //1
	positionsDedo.push_back(glm::vec3(0.5f, 0.9f, 0.2f)); //2
	positionsDedo.push_back(glm::vec3(-0.5f, 0.9f, 0.2f)); //3
														   //Cara Derecha1
	positionsDedo.push_back(glm::vec3(0.5f, -0.9f, 0.2f)); //4
	positionsDedo.push_back(glm::vec3(0.5f, -0.9f, -0.2f)); //5
	positionsDedo.push_back(glm::vec3(0.5f, 0.9f, -0.2f)); //6
	positionsDedo.push_back(glm::vec3(0.5f, 0.9f, 0.2f)); //7
														  //Cara Izquierda 
	positionsDedo.push_back(glm::vec3(-0.5f, -0.9f, -0.2f)); //8
	positionsDedo.push_back(glm::vec3(-0.5f, -0.9f, 0.2f)); //9
	positionsDedo.push_back(glm::vec3(-0.5f, 0.9f, 0.2f)); //10
	positionsDedo.push_back(glm::vec3(-0.5f, 0.9f, -0.2f)); //11
															//Cara Atras 
	positionsDedo.push_back(glm::vec3(0.5f, -0.9f, -0.2f)); //12
	positionsDedo.push_back(glm::vec3(-0.5f, -0.9f, -0.2f)); //13
	positionsDedo.push_back(glm::vec3(-0.5f, 0.9f, -0.2f)); //14
	positionsDedo.push_back(glm::vec3(0.5f, 0.9f, -0.2f)); //15
														   //Cara Arriba 
	positionsDedo.push_back(glm::vec3(-0.5f, 0.9f, 0.2f)); //16
	positionsDedo.push_back(glm::vec3(0.5f, 0.9f, 0.2f)); //17
	positionsDedo.push_back(glm::vec3(0.5f, 0.9f, -0.2f)); //18
	positionsDedo.push_back(glm::vec3(-0.5f, 0.9f, -0.2f)); //19
															//Cara Abajo
	positionsDedo.push_back(glm::vec3(-0.5f, -0.9f, -0.2f)); //20
	positionsDedo.push_back(glm::vec3(0.5f, -0.9f, -0.2f)); //21
	positionsDedo.push_back(glm::vec3(0.5f, -0.9f, 0.2f)); //22
	positionsDedo.push_back(glm::vec3(-0.5f, -0.9f, 0.2f)); //23


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

	_meshPalma.CreateMesh(24);
	_meshPalma.SetIndices(indices, GL_STATIC_DRAW);
	_meshPalma.SetPositionAttribute(positionsPalma, GL_STATIC_DRAW, 0);
	_meshPalma.SetNormalAttribute(Normal, GL_STATIC_DRAW, 1);
	_meshPalma.SetTexCoordAttribute(Textura, GL_STATIC_DRAW, 2);

	_meshDedo.CreateMesh(24);
	_meshDedo.SetIndices(indices, GL_STATIC_DRAW);
	_meshDedo.SetPositionAttribute(positionsDedo, GL_STATIC_DRAW, 0);
	_meshDedo.SetNormalAttribute(Normal, GL_STATIC_DRAW, 1);
	_meshDedo.SetTexCoordAttribute(Textura, GL_STATIC_DRAW, 2);


	_meshPiso.CreateMesh(24);
	_meshPiso.SetIndices(indices, GL_STATIC_DRAW);
	_meshPiso.SetPositionAttribute(positionsPiso, GL_STATIC_DRAW, 0);
	_meshPiso.SetNormalAttribute(Normal, GL_STATIC_DRAW, 1);
	_meshPiso.SetTexCoordAttribute(Textura, GL_STATIC_DRAW, 2);

	//Configuracion de camara y buffer de profundidad 
	_depthBuffer.Create(2048);
	_lightCamera.SetPosition(-5.0f, 5.0f, 5.0f);
	_lightCamera.SetRotation(-30.0f, 0.0f, 0.0f);
	_lightCamera.SetOrthographic(40.0f, 1.0f);


	_shaderProgramDepth.CreateProgram();
	_shaderProgramDepth.AttachShader("Depth.vert", GL_VERTEX_SHADER);
	_shaderProgramDepth.AttachShader("Depth.frag", GL_FRAGMENT_SHADER);
	_shaderProgramDepth.SetAttribute(0, "VertexPosition");
	_shaderProgramDepth.LinkProgram();


	//Shader ShadowMapping 1 textura

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

	_myTexture3.LoadTexture("Piso.jpg");


	//Shader ShadowMapping 2 texturas
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

	_myTexture.LoadTexture("Piel.jpg");
	_myTexture2.LoadTexture("Diamante.png");



	_Piso.SetPosition(0.0f, -1.0f, 0.0f);
	_Piso.SetScale(30.0f, 0.5f, 30.0f);

	_Palma.SetPosition(0.0f, 2.0f, 0.0f);
	_Palma.SetRotation(-45.0f, 0.0f, 0.0f);

	_JoinAnBase.SetPosition(-1.5f, 3.0f, 0.0f);
	_AnularBase.SetPosition(0.0f, 1.2f, 0.0f);
	_JoinAn.SetPosition(0.0f, 0.9f, 0.0f);
	_Anular.SetPosition(0.0f, 1.2f, 0.0f);

	_JoinMedBase.SetPosition(0.0f, 3.0f, 0.0f);
	_MedioBase.SetPosition(0.0f, 1.2f, 0.0f);
	_JoinMed.SetPosition(0.0f, 0.9f, 0.0f);
	_Medio.SetPosition(0.0f, 1.2f, 0.0f);

	_JoinInBase.SetPosition(1.5f, 3.0f, 0.0f);
	_IndiceBase.SetPosition(0.0f, 1.2f, 0.0f);
	_JoinIn.SetPosition(0.0f, 0.9f, 0.0f);
	_Indice.SetPosition(0.0f, 1.2f, 0.0f);

	_JoinInBase.SetPosition(1.5f, 3.0f, 0.0f);
	_IndiceBase.SetPosition(0.0f, 1.2f, 0.0f);
	_JoinIn.SetPosition(0.0f, 0.9f, 0.0f);
	_Indice.SetPosition(0.0f, 1.2f, 0.0f);

	_JoinPulBase.SetPosition(2.0f, -1.0f, 0.0f);
	_PulgarBase.SetPosition(0.0f, 1.2f, 0.0f);
	_JoinPul.SetPosition(0.0f, 0.9f, 0.0f);
	_Pulgar.SetPosition(0.0f, 1.2f, 0.0f);

}

void GameLoop()
{
	_camera.SetPosition(0.0f, 7.0f, 20.0f);
	_camera.SetRotation(-20.0f, 0.0f, 0.0f);
	_Palma.Rotate(0.0f, 0.05f, 0.0f, true);

	float rotacionAnular = 0.0f + contadorAnular;
	float rotacionMed = 0.0f + contadorMed;
	float rotacionIn = 0.0f + contadorIn;
	float rotacionPul = 0.0f + contadorPul;

	if (contador == 0.0f && contador2 == 0.0f && contador3 == 0.0f  && contador4 == 0.0f) {

		if (rotacionAnular <= 90.0f) {
			_JoinAnBase.SetRotation(rotacionAnular, 0.0f, 0.0f);
			_JoinAn.SetRotation(rotacionAnular, 0.0f, 0.0f);
			contadorAnular = contadorAnular + 0.08f;
		}
		if (rotacionMed <= 90.0f) {
			_JoinMedBase.SetRotation(rotacionMed, 0.0f, 0.0f);
			_JoinMed.SetRotation(rotacionMed, 0.0f, 0.0f);
			contadorMed = contadorMed + 0.09f;
		}
		if (rotacionIn <= 90.0f) {
			_JoinInBase.SetRotation(rotacionIn, 0.0f, 0.0f);
			_JoinIn.SetRotation(rotacionIn, 0.0f, 0.0f);
			contadorIn = contadorIn + 0.11;
		}
		if (rotacionPul <= 90.0f) {
			_JoinPulBase.SetRotation(rotacionPul, 0.0f, -90.0f);
			_JoinPul.SetRotation(rotacionPul, 0.0f, 0.0f);
			contadorPul = contadorPul + 0.13f;
		}


	}

	if (rotacionAnular >= 90.0f && contador == 0.0f && rotacionMed >= 90.0f && contador2 == 0.0f && rotacionIn >= 90.0f && contador3 == 0.0f && rotacionPul >= 90.0f && contador4 == 0.0f) {
		contador = 1.0f;
		contador2 = 1.0f;
		contador3 = 1.0f;
		contador4 = 1.0f;
	}

	if (contador == 1.0f && contador2 == 1.0f && contador3 == 1.0f && contador4 == 1.0f) {
		if (rotacionAnular >= 0.0f) {
			_JoinAnBase.SetRotation(rotacionAnular, 0.0f, 0.0f);
			_JoinAn.SetRotation(rotacionAnular, 0.0f, 0.0f);
			contadorAnular = contadorAnular - 0.08f;
		}
		if (rotacionMed >= 0.0f) {
			_JoinMedBase.SetRotation(rotacionMed, 0.0f, 0.0f);
			_JoinMed.SetRotation(rotacionMed, 0.0f, 0.0f);
			contadorMed = contadorMed - 0.09f;
		}
		if (rotacionIn >= 0.0f) {
			_JoinInBase.SetRotation(rotacionIn, 0.0f, 0.0f);
			_JoinIn.SetRotation(rotacionIn, 0.0f, 0.0f);
			contadorIn = contadorIn - 0.11;
		}
		if (rotacionPul >= 0.0f) {
			_JoinPulBase.SetRotation(rotacionPul, 0.0f, -90.0f);
			_JoinPul.SetRotation(rotacionPul, 0.0f, 0.0f);
			contadorPul = contadorPul - 0.13f;
		}
	}
	if (rotacionAnular <= 0.0f && contador == 1.0f && rotacionMed <= 0.0f && contador2 == 1.0f && rotacionIn <= 0.0f && contador3 == 1.0f && rotacionPul <= 0.0f && contador4 == 1.0f) {
		contador = 0.0f;
		contador2 = 0.0f;
		contador3 = 0.0f;
		contador4 = 0.0;
	}





	//PRIMER RENDER 
	_depthBuffer.Bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_shaderProgramDepth.Activate();

	//Palma
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _lightCamera.GetViewProjection()* _Palma.GetModelMatrix());
	_meshPalma.Draw(GL_TRIANGLES);



	// Join Anular Base
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _lightCamera.GetViewProjection()* _Palma.GetModelMatrix()* _JoinAnBase.GetModelMatrix());
	//Anular Base
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _lightCamera.GetViewProjection() * _Palma.GetModelMatrix()*_JoinAnBase.GetModelMatrix() * _AnularBase.GetModelMatrix());
	_meshDedo.Draw(GL_TRIANGLES);
	// Join Anular 
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _lightCamera.GetViewProjection()* _Palma.GetModelMatrix()* _JoinAnBase.GetModelMatrix() * _AnularBase.GetModelMatrix() * _JoinAn.GetModelMatrix());
	//Anular
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _lightCamera.GetViewProjection()* _Palma.GetModelMatrix()* _JoinAnBase.GetModelMatrix() * _AnularBase.GetModelMatrix() * _JoinAn.GetModelMatrix()* _Anular.GetModelMatrix());
	_meshDedo.Draw(GL_TRIANGLES);



	// Join Medio Base
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _lightCamera.GetViewProjection()* _Palma.GetModelMatrix()* _JoinMedBase.GetModelMatrix());
	//Medio Base
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _lightCamera.GetViewProjection() * _Palma.GetModelMatrix()*_JoinMedBase.GetModelMatrix() * _MedioBase.GetModelMatrix());
	_meshDedo.Draw(GL_TRIANGLES);
	// Join Medio
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _lightCamera.GetViewProjection()* _Palma.GetModelMatrix()* _JoinMedBase.GetModelMatrix() * _MedioBase.GetModelMatrix() * _JoinMed.GetModelMatrix());
	//Medio
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _lightCamera.GetViewProjection()* _Palma.GetModelMatrix()* _JoinMedBase.GetModelMatrix() * _MedioBase.GetModelMatrix() * _JoinMed.GetModelMatrix()* _Medio.GetModelMatrix());
	_meshDedo.Draw(GL_TRIANGLES);



	// Join Indice Base
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _lightCamera.GetViewProjection()* _Palma.GetModelMatrix()* _JoinInBase.GetModelMatrix());
	//Indice Base
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _lightCamera.GetViewProjection() * _Palma.GetModelMatrix()*_JoinInBase.GetModelMatrix() * _IndiceBase.GetModelMatrix());
	_meshDedo.Draw(GL_TRIANGLES);
	// Join Indice
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _lightCamera.GetViewProjection()* _Palma.GetModelMatrix()* _JoinInBase.GetModelMatrix() * _IndiceBase.GetModelMatrix() * _JoinIn.GetModelMatrix());
	//Indice
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _lightCamera.GetViewProjection()* _Palma.GetModelMatrix()* _JoinInBase.GetModelMatrix() * _IndiceBase.GetModelMatrix() * _JoinIn.GetModelMatrix()* _Indice.GetModelMatrix());
	_meshDedo.Draw(GL_TRIANGLES);




	// Join Pulgar Base
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _lightCamera.GetViewProjection()* _Palma.GetModelMatrix()* _JoinPulBase.GetModelMatrix());
	//Pulgar Base
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _lightCamera.GetViewProjection() * _Palma.GetModelMatrix()*_JoinPulBase.GetModelMatrix() * _PulgarBase.GetModelMatrix());
	_meshDedo.Draw(GL_TRIANGLES);
	// Join Pulgar
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _lightCamera.GetViewProjection()* _Palma.GetModelMatrix()* _JoinPulBase.GetModelMatrix() * _PulgarBase.GetModelMatrix() * _JoinPul.GetModelMatrix());
	//Pulgar
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _lightCamera.GetViewProjection()* _Palma.GetModelMatrix()* _JoinPulBase.GetModelMatrix() * _PulgarBase.GetModelMatrix() * _JoinPul.GetModelMatrix()* _Pulgar.GetModelMatrix());
	_meshDedo.Draw(GL_TRIANGLES);




	//Piso
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _lightCamera.GetViewProjection()* _Piso.GetModelMatrix());
	_meshPiso.Draw(GL_TRIANGLES);

	_shaderProgramDepth.Deactivate();
	_depthBuffer.Unbind();
	glViewport(0, 0, 400, 400);

	//SEGUNDO RENDER 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//PALMA
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_Palma.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _Palma.GetModelMatrix());
	_shaderProgram.SetUniformf("cameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _Palma.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightCamera.GetViewProjection());

	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDephtMap();
	_meshPalma.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDephtMap();
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();
	_shaderProgram.Deactivate();





	//Join Anular Base 
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_Palma.GetModelMatrix() *_JoinAnBase.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _Palma.GetModelMatrix() *_JoinAnBase.GetModelMatrix());
	_shaderProgram.SetUniformf("cameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _Palma.GetModelMatrix() *_JoinAnBase.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightCamera.GetViewProjection());
	_shaderProgram.Deactivate();
	//Anular Base  
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_Palma.GetModelMatrix() *_JoinAnBase.GetModelMatrix() *_AnularBase.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _Palma.GetModelMatrix() * _JoinAnBase.GetModelMatrix()* _AnularBase.GetModelMatrix());
	_shaderProgram.SetUniformf("cameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _Palma.GetModelMatrix() *  _JoinAnBase.GetModelMatrix() * _AnularBase.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightCamera.GetViewProjection());

	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDephtMap();
	_meshDedo.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDephtMap();
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();
	_shaderProgram.Deactivate();

	//Join Anular 
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_Palma.GetModelMatrix() *_JoinAnBase.GetModelMatrix() *_AnularBase.GetModelMatrix()* _JoinAn.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _Palma.GetModelMatrix() * _JoinAnBase.GetModelMatrix()* _AnularBase.GetModelMatrix()* _JoinAn.GetModelMatrix());
	_shaderProgram.SetUniformf("cameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _Palma.GetModelMatrix() *  _JoinAnBase.GetModelMatrix() * _AnularBase.GetModelMatrix()* _JoinAn.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightCamera.GetViewProjection());
	_shaderProgram.Deactivate();
	//Anular 
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_Palma.GetModelMatrix() *_JoinAnBase.GetModelMatrix() *_AnularBase.GetModelMatrix()* _JoinAn.GetModelMatrix() *_Anular.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _Palma.GetModelMatrix() * _JoinAnBase.GetModelMatrix()* _AnularBase.GetModelMatrix()* _JoinAn.GetModelMatrix() * _Anular.GetModelMatrix());
	_shaderProgram.SetUniformf("cameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _Palma.GetModelMatrix() *  _JoinAnBase.GetModelMatrix() * _AnularBase.GetModelMatrix()* _JoinAn.GetModelMatrix() * _Anular.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightCamera.GetViewProjection());

	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDephtMap();
	_meshDedo.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDephtMap();
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();

	_shaderProgram.Deactivate();





	//Join Medio Base 
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_Palma.GetModelMatrix() *_JoinMedBase.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _Palma.GetModelMatrix() *_JoinMedBase.GetModelMatrix());
	_shaderProgram.SetUniformf("cameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _Palma.GetModelMatrix() *_JoinMedBase.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightCamera.GetViewProjection());
	_shaderProgram.Deactivate();
	//Medio Base  
	_shaderProgramMix.Activate();
	_shaderProgramMix.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_Palma.GetModelMatrix() *_JoinMedBase.GetModelMatrix() *_MedioBase.GetModelMatrix()))));
	_shaderProgramMix.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _Palma.GetModelMatrix() * _JoinMedBase.GetModelMatrix()* _MedioBase.GetModelMatrix());
	_shaderProgramMix.SetUniformf("cameraPosition", _camera.GetPosition());
	_shaderProgramMix.SetUniformMatrix("ModelMatrix", _Palma.GetModelMatrix() *  _JoinMedBase.GetModelMatrix() * _MedioBase.GetModelMatrix());
	_shaderProgramMix.SetUniformMatrix("LightVPMatrix", _lightCamera.GetViewProjection());

	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_myTexture2.Bind();
	glActiveTexture(GL_TEXTURE2);
	_depthBuffer.BindDephtMap();
	_meshDedo.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE2);
	_depthBuffer.UnbindDephtMap();
	glActiveTexture(GL_TEXTURE1);
	_myTexture2.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_myTexture.Unbind();
	_shaderProgramMix.Deactivate();

	//Join Medio 
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_Palma.GetModelMatrix() *_JoinMedBase.GetModelMatrix() *_MedioBase.GetModelMatrix()* _JoinMed.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _Palma.GetModelMatrix() * _JoinMedBase.GetModelMatrix()* _MedioBase.GetModelMatrix()* _JoinMed.GetModelMatrix());
	_shaderProgram.SetUniformf("cameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _Palma.GetModelMatrix() *  _JoinMedBase.GetModelMatrix() * _MedioBase.GetModelMatrix()* _JoinMed.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightCamera.GetViewProjection());
	_shaderProgram.Deactivate();
	//Medio
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_Palma.GetModelMatrix() *_JoinMedBase.GetModelMatrix() *_MedioBase.GetModelMatrix()* _JoinMed.GetModelMatrix() *_Medio.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _Palma.GetModelMatrix() * _JoinMedBase.GetModelMatrix()* _MedioBase.GetModelMatrix()* _JoinMed.GetModelMatrix() * _Medio.GetModelMatrix());
	_shaderProgram.SetUniformf("cameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _Palma.GetModelMatrix() *  _JoinMedBase.GetModelMatrix() * _MedioBase.GetModelMatrix()* _JoinMed.GetModelMatrix() * _Medio.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightCamera.GetViewProjection());

	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDephtMap();
	_meshDedo.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDephtMap();
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();

	_shaderProgram.Deactivate();




	//Join Indice Base 
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_Palma.GetModelMatrix() *_JoinInBase.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _Palma.GetModelMatrix() *_JoinInBase.GetModelMatrix());
	_shaderProgram.SetUniformf("cameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _Palma.GetModelMatrix() *_JoinInBase.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightCamera.GetViewProjection());
	_shaderProgram.Deactivate();
	//Indice Base  
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_Palma.GetModelMatrix() *_JoinInBase.GetModelMatrix() *_IndiceBase.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _Palma.GetModelMatrix() * _JoinInBase.GetModelMatrix()* _IndiceBase.GetModelMatrix());
	_shaderProgram.SetUniformf("cameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _Palma.GetModelMatrix() *  _JoinInBase.GetModelMatrix() * _IndiceBase.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightCamera.GetViewProjection());

	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDephtMap();
	_meshDedo.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDephtMap();
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();
	_shaderProgram.Deactivate();

	//Join Indice
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_Palma.GetModelMatrix() *_JoinInBase.GetModelMatrix() *_IndiceBase.GetModelMatrix()* _JoinIn.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _Palma.GetModelMatrix() * _JoinInBase.GetModelMatrix()* _IndiceBase.GetModelMatrix()* _JoinIn.GetModelMatrix());
	_shaderProgram.SetUniformf("cameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _Palma.GetModelMatrix() *  _JoinInBase.GetModelMatrix() * _IndiceBase.GetModelMatrix()* _JoinIn.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightCamera.GetViewProjection());
	_shaderProgram.Deactivate();
	//Indice
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_Palma.GetModelMatrix() *_JoinInBase.GetModelMatrix() *_IndiceBase.GetModelMatrix()* _JoinIn.GetModelMatrix() *_Indice.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _Palma.GetModelMatrix() * _JoinInBase.GetModelMatrix()* _IndiceBase.GetModelMatrix()* _JoinIn.GetModelMatrix() * _Indice.GetModelMatrix());
	_shaderProgram.SetUniformf("cameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _Palma.GetModelMatrix() *  _JoinInBase.GetModelMatrix() * _IndiceBase.GetModelMatrix()* _JoinIn.GetModelMatrix() * _Indice.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightCamera.GetViewProjection());

	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDephtMap();
	_meshDedo.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDephtMap();
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();

	_shaderProgram.Deactivate();





	//Join Pulgar Base 
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_Palma.GetModelMatrix() *_JoinPulBase.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _Palma.GetModelMatrix() *_JoinPulBase.GetModelMatrix());
	_shaderProgram.SetUniformf("cameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _Palma.GetModelMatrix() *_JoinPulBase.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightCamera.GetViewProjection());
	_shaderProgram.Deactivate();
	//Pulgar Base  
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_Palma.GetModelMatrix() *_JoinPulBase.GetModelMatrix() *_PulgarBase.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _Palma.GetModelMatrix() * _JoinPulBase.GetModelMatrix()* _PulgarBase.GetModelMatrix());
	_shaderProgram.SetUniformf("cameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _Palma.GetModelMatrix() *  _JoinPulBase.GetModelMatrix() * _PulgarBase.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightCamera.GetViewProjection());

	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDephtMap();
	_meshDedo.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDephtMap();
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();
	_shaderProgram.Deactivate();

	//Join Pulgar
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_Palma.GetModelMatrix() *_JoinPulBase.GetModelMatrix() *_PulgarBase.GetModelMatrix()* _JoinPul.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _Palma.GetModelMatrix() * _JoinPulBase.GetModelMatrix()* _PulgarBase.GetModelMatrix()* _JoinPul.GetModelMatrix());
	_shaderProgram.SetUniformf("cameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _Palma.GetModelMatrix() *  _JoinPulBase.GetModelMatrix() * _PulgarBase.GetModelMatrix()* _JoinPul.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightCamera.GetViewProjection());
	_shaderProgram.Deactivate();
	//Pulgar
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_Palma.GetModelMatrix() *_JoinPulBase.GetModelMatrix() *_PulgarBase.GetModelMatrix()* _JoinPul.GetModelMatrix() *_Pulgar.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _Palma.GetModelMatrix() * _JoinPulBase.GetModelMatrix()* _PulgarBase.GetModelMatrix()* _JoinPul.GetModelMatrix() * _Pulgar.GetModelMatrix());
	_shaderProgram.SetUniformf("cameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _Palma.GetModelMatrix() *  _JoinPulBase.GetModelMatrix() * _PulgarBase.GetModelMatrix()* _JoinPul.GetModelMatrix() * _Pulgar.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightCamera.GetViewProjection());

	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDephtMap();
	_meshDedo.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDephtMap();
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();

	_shaderProgram.Deactivate();







	//Piso 
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_Piso.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _Piso.GetModelMatrix());
	_shaderProgram.SetUniformf("cameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _Piso.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightCamera.GetViewProjection());

	glActiveTexture(GL_TEXTURE0);
	_myTexture3.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDephtMap();
	_meshPiso.Draw(GL_TRIANGLES);
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
	glutCreateWindow("Proyecto Final de Gráficas Computacionales");
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