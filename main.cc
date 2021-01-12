#include <iostream>
#include "triangle.h"
#include "points.h"

using namespace std;

int main(int argc, char *argv[])
{
	gltSetWorkingDirectory(argv[0]);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	glutInitWindowSize(800, 600);
	points::DrawPoints();
	glutMainLoop();
    return 0;
}
