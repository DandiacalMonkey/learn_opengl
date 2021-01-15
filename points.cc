#include "points.h"
#include <GL/glew.h>
#ifdef WIN32
#include <GL/freeglut.h>
#elif __APPLE__
#include <glut.h>
#endif
#include "GLTools.h"
#include "GLShaderManager.h"

static GLBatch point_batch;
static GLShaderManager shader_manager;
static GLfloat verts[] = { -0.5f, 0.0f, 0.0f,
					   0.5f, 0.0f, 0.0f,
					   0.0f, 0.5f, 0.0f };

void points::DrawPoints() {
	glutCreateWindow("Points");
	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glPointSize(5);
	glLineWidth(10);
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		printf("error");
	}
	SetupRC();

	GLfloat sizes[2];
	GLfloat step;
	glGetFloatv(GL_POINT_SIZE_RANGE, sizes);
	glGetFloatv(GL_POINT_SIZE_GRANULARITY, &step);
	printf("%f %f\n", sizes[0], sizes[1]);
	printf("%f\n", step);
}

void points::ChangeSize(int w, int h) {
	glViewport(0, 0, w, h);
}

void points::SetupRC() {
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	shader_manager.InitializeStockShaders();
	point_batch.Begin(GL_LINE_LOOP, 3);
	point_batch.CopyVertexData3f(verts);
	point_batch.End();
}

void points::RenderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	GLfloat red[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	shader_manager.UseStockShader(GLT_SHADER_IDENTITY, red);
	point_batch.Draw();
	glutSwapBuffers();
}