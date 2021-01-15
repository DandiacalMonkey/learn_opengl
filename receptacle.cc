#include "receptacle.h"
#include <GL/glew.h>
#include <GLFrustum.h>
#ifdef WIN32
#include <GL/freeglut.h>
#elif __APPLE__
#include <glut.h>
#endif
#include "GLTools.h"
#include "StopWatch.h"
#include "math3d.h"
#include "GLTriangleBatch.h"

GLFrustum view_frustum;
static GLShaderManager shader_manager;
static GLTriangleBatch receptacle_batch;

void receptacle::DrawPoints() {
	glutCreateWindow("Triangle");
	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);
	glEnable(GL_MULTISAMPLE);
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		printf("error");
	}
	SetupRC();
}

void receptacle::ChangeSize(int w, int h) {
	if (h == 0) {
		h = 1;
	}
	glViewport(0, 0, w, h);
	view_frustum.SetPerspective(35.0f, float(w) / float(h), 1.0f, 1000.0f);
}

void receptacle::SetupRC() {
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	shader_manager.InitializeStockShaders();
	gltMakeTorus(receptacle_batch, 0.4f, 0.1f, 100, 100);
}

void receptacle::RenderScene() {
	static CStopWatch rotate_timer;
	float y_rotate = rotate_timer.GetElapsedSeconds() * 60.0f;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	M3DMatrix44f translate, rotate, model_view, model_view_projection;
	m3dTranslationMatrix44(translate, 0.0f, 0.0f, -2.5f);
	m3dRotationMatrix44(rotate, m3dDegToRad(y_rotate), 0.0f, 1.0f, 0.0f);
	m3dMatrixMultiply44(model_view, translate, rotate);
	m3dMatrixMultiply44(model_view_projection, view_frustum.GetProjectionMatrix(), model_view);
	GLfloat red[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	shader_manager.UseStockShader(GLT_SHADER_FLAT, model_view_projection, red);
	receptacle_batch.Draw();
	glutSwapBuffers();
	glutPostRedisplay();
}
