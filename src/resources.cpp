#include "resources.h"

#include "utils.h"

#include "shader_object.h"

#include "vertices_data.h"

Resources::Resources()
{
  initShaderProgram(basic, "./shaders/basic.vs.glsl", "./shaders/basic.fs.glsl");
  initShaderProgram(color, "./shaders/color.vs.glsl", "./shaders/color.fs.glsl");

  initShaderProgram(transformColorAttrib, "./shaders/transform.vs.glsl", "./shaders/transform.fs.glsl");
  initShaderProgram(transformSolidColor, "./shaders/model.vs.glsl", "./shaders/model.fs.glsl");
}

void Resources::initShaderProgram(ShaderProgram &program, const char *vertexSrcPath, const char *fragmentSrcPath)
{

  std::string vertexShaderCode = readFile(vertexSrcPath);
  std::string fragmentShaderCode = readFile(fragmentSrcPath);

  ShaderObject vertexShader(GL_VERTEX_SHADER, vertexShaderCode.c_str());
  ShaderObject fragmentShader(GL_FRAGMENT_SHADER, fragmentShaderCode.c_str());

  program.attachShaderObject(vertexShader);
  program.attachShaderObject(fragmentShader);

  program.link();
  program.use();
}
