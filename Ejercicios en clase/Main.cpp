#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Employee.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include<vector> //es una espeie de lista ligada--> esto es un vector en c++

#include <glm/glm.hpp> //libreria de matematicas


/**int main() {
	std::cout << "Hello World!" << std::endl;

	std::cout << "\n\nColor del circulo: " << std::endl;
	Circle circulo(2.0, "green");
	std::cout << circulo.GetColor() << std::endl;

	std::cout << "\n\nArea del rectangulo: " << std::endl;
	Rectangle rectangulo(5.0, 2.0);
	std::cout << rectangulo.GetArea() << std::endl;


	Employee employee(1375042, "Valeria", " Sanchez", 7000);
	std::cout << employee.Print() << std::endl;

	std::cin.get();
	return 0;
}
**/


//LIBRERIAS 

//iDENTIFICADOR DEL MANAGER AL QUE LE VAMOS A ASOCIAR TODOS LOS vboS
GLuint vao;

//en esta funcion voy a estar creando toda la memoria que el programa va a utilizar
void Initialize() {

	//Estamos trabajando en el cpu y ram de la computadora, aun no pasamos a la tarjeta de video.

	std::vector<glm::vec2> positions;  //Creacion del atributo de posiciones de los vertices, lista de vec 2--> x, y, vec3--> x,y,z
	positions.push_back(glm::vec2(0.5f, 0.5f));
	positions.push_back(glm::vec2(-0.5f, 0.5f));
	positions.push_back(glm::vec2(0.5f, -0.5f));
	positions.push_back(glm::vec2(-0.5f, -0.5f));

	//Queremos generar 1 manager
	glGenVertexArrays(1, &vao);
	//Utilizar el vao. A partir de este momento, todos los VBOs creados y configurados se van a asociar a este manager
	glBindVertexArray(vao);


	GLuint positionsVBO; //GLuint es un entero sin signo
	glGenBuffers(1, &positionsVBO); //Creacion del VBO de posiciones
	//Activamos el buffer de posiiciones para poder utilizarlo
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	//Creamos la memoria y la inicializamos con los daros del atributo de posiciones
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * positions.size(),positions.data(), GL_STATIC_DRAW );
	//Activamos el atributo en la tarjeta de video
	glEnableVertexAttribArray(0);
	//Configuramos los datos del atributo en la tarjeta de video (presentacion de la clase)
	glVertexAttribPointer(0, 2,GL_FLOAT, GL_FALSE, 0, nullptr);
	//Ya no vamos a utilizar este VBO en este momento
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//Desactivamos el manager

	glBindVertexArray(0);
}



void GameLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Limpiamos el buffer de color y el buffer de profundidad.
	//Siempre hacerlo al inicio del frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Activamos el manager, en este momento se activan todos los VBOs asociados automaticamente
	glBindVertexArray(vao);
	//Funcion de dibujado sin indices
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	//Terminamos de utilizar el manager
	glBindVertexArray(0);

	//Cuando terminamos de renderear, cambiamos los buffers.
	

	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	// Inicializar freeglut
	// Freeglut se encarga de crear una ventana
	// en donde podemos dibujar
	glutInit(&argc, argv);

	//solicitando una version específica de OpenGL

	glutInitContextVersion(4,4);
	// Iniciar el contexto de OpenGL. El contexto se refiere
	// a las capacidades que va a tener nuestra aplicación
	// gráfica.
	// En este caso estamos trabajando con el pipeline clásico.
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	// Freeglut nos permite configurar eventos que ocurren en la ventana.
	// Un evento que nos interesa es cuando alguien cierra la ventana.
	// En este caso, simplemente dejamos de renderear la esscena y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	// Configuramos el framebuffer. En este caso estamos solicitando un buffer
	// true color RGBA, un buffer de profundidad y un segundo buffer para renderear.
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	// Iniciar las dimensiones de la ventana (en pixeles)
	glutInitWindowSize(400, 400);
	// Creamos la ventana y le damos un título.
	glutCreateWindow("Hello World GL");
	// Asociamos una función de render. Esta función se mandará a llamar para dibujar un frame.
	glutDisplayFunc(GameLoop);

	// Inicializar GLEW. Esta librería se encarga de obtener el API de OpenGL de
	// nuestra tarjeta de video. SHAME ON YOU MICROSOFT.
	glewInit();

	// Configurar OpenGL. Este es el color por default del buffer de color
	// en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;

	//Configuración inicial de nuestro programa
	Initialize();


	// Iniciar la aplicación. El main se pausará en esta línea hasta que se cierre
	// la venta de OpenGL.
	glutMainLoop();

	return 0;
}