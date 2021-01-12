#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
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
