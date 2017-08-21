#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Employee.h"

int main() {

	std::cout << "Hello World!" << std::endl;

	Circle circulo(2.0, "Color: green");
	std::cout << circulo.GetColor() << std::endl;

	Rectangle rectangulo(5.0, 2.0);
	std::cout <<rectangulo.GetArea() << std::endl;
	

	Employee employee(1375042, "Valeria", " Sanchez", 7000);
	std::cout << employee.Print() << std::endl;

	std::cin.get();
	return 0;
}