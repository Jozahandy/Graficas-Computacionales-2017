/*********************************************************

Materia: Gráficas Computacionales
Fecha: 12 de Agosto del 2017
Autor: A01375042 Alumno Valeria Jozahandy Sánchez Álvarez

*********************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <iostream>


//Ejercicio 1
int PerimetroRectangulo(int base, int altura)
{
	return base*altura;
}


//Ejercicio 2
float AreaTriangulo(float base, float altura)
{
	return (base*altura) / 2;
}

//Ejercicio 3
int Mayor(int n1, int n2, int n3)
{
	if (n1 >= n2 && n1 >= n3)
	{
		return n1;
	}

	if (n2 >= n1 && n2 >= n3)
	{
		return n2;
	}

	else
	{
		return n3;
	}
}


//Ejercicio 4
int Menor(int n1, int n2, int n3)
{
	if (n1 <= n2 && n1 <= n3)
	{
		return n1;
	}

	if (n2 <= n1 && n2 <= n3)
	{
		return n2;
	}

	else
	{
		return n3;
	}
}


//Ejercicio 5
void FilaEstrellas(int n)
{
	for (int x = 0; x < n; x++)
	{
		std::cout << "*";
	}

	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
}


//Ejercicio 6
void MatrizEstrellas(int n)
{
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			std::cout << "*";
		}

		std::cout << "\n";
	}

	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
}


//Ejercicio 7
void PiramideEstrellas(int n)
{
	int x = 0;

	while (x < n)
	{
		for (int y = 0; y <= x; y++)
		{
			std::cout << "*";
		}

		std::cout << "\n";
		x = x + 1;
	}

	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
}


//Ejercicio 8
void FlechaEstrellas(int n)
{
	int x = 0;
	int z = n;


	while (x < n)
	{
		for (int y = 0; y <= x; y++)
		{
			std::cout << "*";
		}

		std::cout << "\n";
		x = x + 1;
	}

	while (z > 0)
	{
		for (int a = (z - 1); a > 0; a--)
		{
			std::cout << "*";
		}

		std::cout << "\n";
		z = z - 1;
	}
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";

}


//Ejercicio 9
void Fibonacci(int n)
{
	int a = 0;
	int b = 1;
	printf("%d \t ", b);


	for (int x = 1; x < n; x++) {
		int c = a + b;
		printf("%d \t ", c);
		a = b;
		b = c;
	}
}


//Ejercicio 10
bool EsPrimo(int numero) {
	int x = 0;

	for (int y = 1; y <= numero; y++) {
		int z = numero %y;

		if (z == 0) {
			x = x + 1;
		}

	}

	if (x <= 2) {
		return true;
	}

	else {
		return false;
	}

}




//MAIN
int main()
{
	int P = PerimetroRectangulo(2, 8);
	printf("El perimetro es: %d \n \n \n", P);

	float A = AreaTriangulo(5, 3);
	printf("El area es: %f \n \n \n", A);

	int M = Mayor(1, 2, 3);
	printf("El numero mayor es: %d \n \n \n", M);

	int m = Menor(1, 2, 3);
	printf("El numero menor es: %d \n \n \n", m);

	FilaEstrellas(5);

	MatrizEstrellas(5);

	PiramideEstrellas(5);

	FlechaEstrellas(3);

	Fibonacci(9);

	bool primo = EsPrimo(17);


	std::cin.get();
}
