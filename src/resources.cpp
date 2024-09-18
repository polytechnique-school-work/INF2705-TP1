#include "resources.h"

#include "utils.h"

#include "shader_object.h"

#include "vertices_data.h"

Resources::Resources()
{
  initShaderProgram(basic, "shaders/basic.vs.glsl", "shaders/basic.fs.glsl");
}

void Resources::initShaderProgram(ShaderProgram &program, const char *vertexSrcPath, const char *fragmentSrcPath)
{
  ShaderObject vertexShader(GL_VERTEX_SHADER, vertexSrcPath);
  ShaderObject fragmentShader(GL_FRAGMENT_SHADER, fragmentSrcPath);

  program.attachShaderObject(vertexShader);
  program.attachShaderObject(fragmentShader);

  glCompileShader(vertexShader.id());
  glCompileShader(fragmentShader.id());
  program.use();
  program.link();
}
