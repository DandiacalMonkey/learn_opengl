#include <iostream>
#include <GL/glew.h>
#ifdef WIN32
#include <GL/freeglut.h>
#elif __APPLE__
#include <glut.h>
#endif
#include "GLTools.h"
#include "triangle.h"
#include "points.h"
#include "receptacle.h"

using namespace std;

int main(int argc, char *argv[])
{
	gltSetWorkingDirectory(argv[0]);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	glutInitWindowSize(800, 600);
	receptacle::DrawPoints();
	glutMainLoop();
    return 0;
}
