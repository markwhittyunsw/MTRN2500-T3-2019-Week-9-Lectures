#include <Shape.h>
#include <GL/glut.h>

Shape::Shape()
{
}

Shape::Shape(double x, double y)
{
	X = x;
	Y = y;
	R = 1.0;
	G = 1.0;
	B = 1.0;
}

Shape::Shape(double x, double y, double r, double g, double b)
{
	X = x;
	Y = y;
	R = r;
	G = g;
	B = b;
}


double Shape::GetX()
{
	return X;
}

double Shape::GetY()
{
	return Y;
}

double Shape::GetR()
{
	return R;
}

double Shape::GetG()
{
	return G;
}

double Shape::GetB()
{
	return B;
}

void Shape::SetX(double x)
{
	X = x;
}

void Shape::SetY(double y)
{
	Y = y;
}

void Shape::SetColour(double r, double g, double b)
{
	R = r;
	G = g;
	B = b;
}
// End of Shape class definition and the member function declaration ==========
