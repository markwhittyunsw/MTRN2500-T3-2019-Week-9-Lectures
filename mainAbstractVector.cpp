/* Class to show how a vector of shape pointers can be used to 
point to objects of derived type and the correct type inferred 
at run-time.
Secondly, use of dynamic_cast for casting between types of different classes
*/
#include <Windows.h>
#include <math.h>
#include <Shape.h>
#include <point.h>
#include <circle.h>
#include <vector>
#include <line.h>
#include <link.h>
#include <GL/glut.h>

#define PI 3.14159265358979323846

using namespace std;

//Global data Declaration
vector<Shape*> ShapePtrs;

double angle_pos = 0;

//OpenGL related functions 
void init(void) 
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) 
	{
	case 27:
		{
			exit(0);
		}
	}
}


void display (void) 
{
	double theta = 0;
	double Radius = 10.0;
	glClearColor (0.0,0.0,0.0,1.0);
	glClear (GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

// Draw
// Normal process for drawing all shapes
/*	for (vector<Shape*>::iterator it = ShapePtrs.begin(); it != ShapePtrs.end(); it++) {
		(*it)->Draw();
	}
	*/
	/* Try this code block instead of the above to see how
	dynamic casting works. Try static_cast instead to see the difference.
	This allows specific handling of different conditions according to 
	different classes, despite being pointed to by a base class
	*/
	
	for (vector<Shape*>::iterator it = ShapePtrs.begin(); it != ShapePtrs.end(); it++) {
		// (*it) will be of type Shape *
		Circle * possible_circle = dynamic_cast<Circle*>(*it);
		if (possible_circle != nullptr) {
			possible_circle->SetX(possible_circle->GetX() + 5);
			possible_circle->SetY(possible_circle->GetY() + 4);
			possible_circle->SetColour(1, 0, 0);
			possible_circle->DrawReverse();
		}
		else {
			(*it)->Draw();
		}
	}
	
		

/* 
// Move shapes around
	double circle_radius = 100;
	angle_pos += 0.1;
	double new_pos_x = circle_radius * cos(angle_pos);
	double new_pos_y = circle_radius * sin(angle_pos);

	for (vector<Shape*>::iterator it = ShapePtrs.begin(); it != ShapePtrs.end(); it++) {
		(*it)->Move(new_pos_x, new_pos_y, 0);
	}
	*/
	

// End of Draw
	glFlush();
	glutSwapBuffers();
	Sleep(100);
}


void reshape (int w, int h) 
{
	glViewport (0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D(-(GLdouble) w,(GLdouble) w,-(GLdouble) h,(GLdouble) h);
	glMatrixMode (GL_MODELVIEW);
}


int main (int argc, char **argv) 
{
	/* Make a whole lot of shapes of different types and push them into the vector of shapes. */
	Shape* ShPtr;
	ShPtr = new Link(0.0,-100.0,200.0, PI/4, 35.0, 0.0, 1.0, 0.0);
	if(ShPtr == NULL)
		return -1;	
	ShapePtrs.push_back(ShPtr);

	ShPtr = new Link(0.0,-150.0,200.0, PI/8, 35.0, 0.0, 1.0, 0.0);
	if(ShPtr == NULL)
		return -1;	
	ShapePtrs.push_back(ShPtr);

	ShPtr = new Link(0.0,-160.0,200.0, 0, 35.0, 0.0, 0.0, 1.0);
	if(ShPtr == NULL)
		return -1;	
	ShapePtrs.push_back(ShPtr);

	ShPtr = new Line(0.0,-100.0,200.0, 0, 1.0, 1.0, 1.0);
	if(ShPtr == NULL)
		return -1;	
	ShapePtrs.push_back(ShPtr);

	ShPtr = new Circle(0.0,-100.0,40.0, 1.0, 1.0, 0.0);
	if(ShPtr == NULL)
		return -1;	
	ShapePtrs.push_back(ShPtr);

	ShPtr = new Point(-100, -100);
	if (ShPtr == NULL)
		return -1;
	ShapePtrs.push_back(ShPtr);

	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("An OpenGL Example Window");
	init();
	glutKeyboardFunc(keyboard);
	glutDisplayFunc (display);
	glutReshapeFunc (reshape);
	glutIdleFunc(display);
	glutMainLoop ();
	return 0;
}
