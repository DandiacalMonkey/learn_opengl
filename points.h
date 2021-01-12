#pragma once

#include "GLTools.h"
#include "GLShaderManager.h"
#include <GL/freeglut.h>

namespace points {
void DrawPoints();
void ChangeSize(int w, int h);
void SetupRC();
void RenderScene();
};

