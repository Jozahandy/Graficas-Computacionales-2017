#include "Rectangle.h"

Rectangle::Rectangle()
{
	_width = 1.0;
	_heigth = 1.0;
}


Rectangle::Rectangle(float w, float h)
{
	_width = w;
	_heigth = h;
}

float Rectangle::GetWidth()
{
	return _width;
}

void Rectangle::SetWidth(float w)
{
	_width = w;
}

float Rectangle::GetHeigth()
{
	return _heigth;
}

void Rectangle::SetHeigth(float h)
{
	_heigth = h;
}

float Rectangle::GetArea()
{
	return _width * _heigth;
}

float Rectangle::GetPerimeter()
{
	return _width *2 + _heigth *2;
}
