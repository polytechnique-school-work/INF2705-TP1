#include "shader_object.h"

#include <iostream>

ShaderObject::ShaderObject(GLenum type, const char *code)
{
  // Création du shader (P.62 du powerpoint 2)
  m_id = glCreateShader(type);
  glShaderSource(m_id, 1, &code, NULL);
  glCompileShader(m_id);

  // TODO: Remove this
  checkCompilingError();
}

ShaderObject::~ShaderObject()
{
  // On supprime le shader
  glDeleteShader(m_id);
}

GLuint ShaderObject::id()
{
  return m_id;
}

void ShaderObject::checkCompilingError()
{
  GLint success;
  GLchar infoLog[1024];

  glGetShaderiv(m_id, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(m_id, 1024, NULL, infoLog);
    glDeleteShader(m_id);
    std::cout << "Shader compile error: " << infoLog << std::endl;
  }
}
