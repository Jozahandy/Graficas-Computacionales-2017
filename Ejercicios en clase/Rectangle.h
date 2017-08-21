#pragma once

class Rectangle
{
public:
	Rectangle();
	Rectangle(float w, float h);
	
	float GetWidth();
	void SetWidth(float w);
	float GetHeigth();
	void SetHeigth(float h);
	float GetArea();
	float GetPerimeter();
	
private:

	float _width;
	float _heigth;
};
