#include "resources.h"

#include "utils.h"

#include "shader_object.h"

#include "vertices_data.h"

Resources::Resources()
{
  // TODO
  initShaderProgram(basic, "shaders/basic.vs.glsl", "shaders/basic.fs.glsl");
}

void Resources::initShaderProgram(ShaderProgram &program, const char *vertexSrcPath, const char *fragmentSrcPath)
{
  // TODO
}
