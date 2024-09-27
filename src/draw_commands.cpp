#include "draw_commands.h"
#include <iostream>

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
  glDrawElements(GL_TRIANGLES, m_count, GL_UNSIGNED_BYTE, 0);
}

// void DrawElementsCommand::draw()
// {
//   m_vao.bind();  // Bind the VAO (which includes the index buffer)

//   Check for OpenGL errors before drawing
//   if (glGetError() != GL_NO_ERROR) {
//     std::cerr << "OpenGL Error before draw\n";
//   }

//   Call glDrawElements with the correct parameters
//   glDrawElements(GL_TRIANGLES, m_count, m_type, nullptr);

//   Check for OpenGL errors after drawing
//   GLenum err = glGetError();
//   if (err != GL_NO_ERROR) {
//     std::cerr << "OpenGL Error during glDrawElements: " << err << std::endl;
//   }
// }

void DrawElementsCommand::setCount(GLsizei count)
{
  m_count = count;
}
