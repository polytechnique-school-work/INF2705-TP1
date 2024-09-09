#include "draw_commands.h"

DrawArraysCommand::DrawArraysCommand(VertexArrayObject &vao, GLsizei count)
    : m_vao(vao), m_count(count)
{
}

void DrawArraysCommand::draw()
{
  m_vao.bind();
  // P.32 du powerpoint 2
  glDrawArrays(GL_TRIANGLES, 0, m_count);
}

void DrawArraysCommand::setCount(GLsizei count)
{
  m_count = count;
}

DrawElementsCommand::DrawElementsCommand(VertexArrayObject &vao, GLsizei count, GLenum type)
    : m_vao(vao), m_count(count), m_type(type)
{
}

void DrawElementsCommand::draw()
{
  m_vao.bind();
  // P.33 du powerpoint 2
  glDrawElements(GL_TRIANGLES, m_count, m_type, nullptr);
}

void DrawElementsCommand::setCount(GLsizei count)
{
  m_count = count;
}
