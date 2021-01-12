#include "triangle.h"

static GLBatch triangle_batch;
static GLShaderManager shader_manager;
static GLfloat verts[] = { -0.5f, 0.0f, 0.0f,
					   0.5f, 0.0f, 0.0f,
					   0.0f, 0.5f, 0.0f };

void triangle::DrawTriangle() {
	glutCreateWindow("Triangle");
	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);
	glutSpecialFunc(SpecialKeys);
	glEnable(GL_MULTISAMPLE);
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		printf("error");
	}
	SetupRC();
}

void triangle::ChangeSize(int w, int h) {
	glViewport(0, 0, w, h);
}

void triangle::SetupRC() {
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	shader_manager.InitializeStockShaders();
	triangle_batch.Begin(GL_TRIANGLES, 3);
	triangle_batch.CopyVertexData3f(verts);
	triangle_batch.End();
}

void triangle::RenderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	GLfloat red[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	shader_manager.UseStockShader(GLT_SHADER_IDENTITY, red);
	triangle_batch.Draw();
	glutSwapBuffers();
}

void triangle::SpecialKeys(int key, int x, int y) {
	GLfloat step_size = 0.025f;
	GLfloat block_x = 0;
	GLfloat block_y = 0;
	switch (key)
	{
	case GLUT_KEY_UP:
		block_y = step_size;
		break;
	case GLUT_KEY_DOWN:
		block_y = -step_size;
		break;
	case GLUT_KEY_LEFT:
		block_x = -step_size;
		break;
	case GLUT_KEY_RIGHT:
		block_x = step_size;
		break;
	default:
		break;
	}
	verts[0] += block_x;
	verts[1] += block_y;

	verts[3] += block_x;
	verts[4] += block_y;

	verts[6] += block_x;
	verts[7] += block_y;

	triangle_batch.CopyVertexData3f(verts);
	glutPostRedisplay();
}