// Example to show how a pointer to an abstract class can be used to 
// point to any derived class
#include <Windows.h>
#include <GL/glut.h>
#include <math.h>
#include <Shape.h>
#include <point.h>
#include <circle.h>
#include <line.h>
#include <link.h>

#define PI 3.14159265358979323846

//Global data Declaration
// Check out this shape pointer and how it is used 
Shape* ShPtr = NULL;
	

//Shape* ShPtr2 = new Link(0.0,-100.0,200.0, PI/4, 35.0, 0.0, 1.0, 0.0);
//Shape* ShPtr3 = new Line(0.0,-100.0,200.0, 0, 1.0, 1.0, 1.0);
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
			if(ShPtr != NULL)
				delete ShPtr;
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
	ShPtr->Draw(); // Draw circle (or whatever is in the Shape pointed to)
	//ShPtr2->Draw();  // Draw Link
	//ShPtr3->Draw(); // Draw Line

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
	// Make this shape pointer point to a circle object.
	ShPtr = new Circle(0.0,-100.0,40.0, 1.0, 1.0, 0.0);
	if(ShPtr == NULL)
		return -1;
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
