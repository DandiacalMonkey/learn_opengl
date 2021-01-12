#pragma once

#include "GLTools.h"
#include "GLShaderManager.h"
#include <GL/freeglut.h>

namespace triangle {
void DrawTriangle();
void ChangeSize(int w, int h);
void SetupRC();
void RenderScene();
void SpecialKeys(int key, int x, int y);
}