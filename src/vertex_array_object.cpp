#include "vertex_array_object.h"

VertexArrayObject::VertexArrayObject()
{
  // Davantage d'informations sur la page 19 du powerpoint 2
  glGenVertexArrays(1, &m_id);
}

VertexArrayObject::~VertexArrayObject()
{
  glDeleteVertexArrays(1, &m_id);
}

void VertexArrayObject::bind()
{
  glBindVertexArray(m_id);
}

void VertexArrayObject::unbind()
{
  // Page 21 du powerpoint 2
  glBindVertexArray(0);
}

void VertexArrayObject::specifyAttribute(BufferObject &buffer, GLuint index, GLint size, GLsizei stride, GLsizeiptr offset)
{
  bind();
  buffer.bind();
  glEnableVertexAttribArray(index);
  // Page #34 du powerpoint 2
  glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, (void *)offset);
}
