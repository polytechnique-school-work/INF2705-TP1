#include "buffer_object.h"

BufferObject::BufferObject()
{
  // P.14 du powerpoint 2
  glGenBuffers(1, &m_id);
}

BufferObject::BufferObject(GLenum type, GLsizeiptr dataSize, const void *data, GLenum usage)
    : BufferObject()
{
  glGenBuffers(1, &m_id);
  allocate(type, dataSize, data, usage);
}

BufferObject::~BufferObject()
{
  glDeleteBuffers(1, &m_id);
}

void BufferObject::bind()
{
  glBindBuffer(m_type, m_id);
}

void BufferObject::allocate(GLenum type, GLsizeiptr dataSize, const void *data, GLenum usage)
{
  // Selon mes recherches, il faut toujours bind avant d'utiliser un buffer pour s'assurer qu'on travaille avec le bon buffer.
  bind();
  glBufferData(type, dataSize, data, usage);
}

void BufferObject::update(GLsizeiptr dataSize, const void *data)
{
  bind();
  glBufferSubData(m_type, 0, dataSize, data);
}

void *BufferObject::mapBuffer()
{
  bind();
  return glMapBuffer(m_type, GL_WRITE_ONLY);
}

void BufferObject::unmapBuffer()
{
  bind();
  glUnmapBuffer(m_type);
}
