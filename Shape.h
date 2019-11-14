#ifndef SHAPE_H
#define SHAPE_H

//Start of Point class ====================================
class Shape
{
protected:
	// Reference position
	double X;
	double Y;
	// Shape colours
	double R;
	double G;
	double B;
public:
	Shape();
	Shape(double x, double y);
	Shape(double x, double y, double r, double g, double b);
	virtual ~Shape(){};
	// Any other constructors
	// Getters and setters
	double GetX();
	double GetY();
	double GetR();
	double GetG();
	double GetB();
	void SetX(double x);
	void SetY(double y);
	void SetColour(double r, double g, double b);
	// Point class capabilities
	virtual void Draw() = 0;
	virtual void Move(double x, double y, double) = 0;
	//any other capabilities
};
#endif
