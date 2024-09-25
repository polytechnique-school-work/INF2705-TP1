#include "buffer_object.h"

BufferObject::BufferObject()
    : m_type(GL_ARRAY_BUFFER)
{
  // danger!!!
  // P.14 du powerpoint 2
  glGenBuffers(1, &m_id);
}

BufferObject::BufferObject(GLenum type)
    : m_type(type)
{
  // P.14 du powerpoint 2
  glGenBuffers(1, &m_id);
}

BufferObject::BufferObject(GLenum type, GLsizeiptr dataSize, const void *data, GLenum usage)
    : BufferObject(type)
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

/*
  Sert à allouer de la mémoire sur le GPU pour stocker des données de buffer tel que les vertices ou les indices.
  @param type Le type de buffer à allouer
  @param dataSize La taille des données à allouer
  @param data Les données à allouer
  @param usage Le mode d'utilisation des données allouées
*/
void BufferObject::allocate(GLenum type, GLsizeiptr dataSize, const void *data, GLenum usage)
{
  // Selon mes recherches, il faut toujours bind avant d'utiliser un buffer pour s'assurer qu'on travaille avec le bon buffer.
  bind();
  glBufferData(type, dataSize, data, usage);
}

/*
  Sert à mettre à jour une partie des données d'un buffer déjà alloué.
  @param dataSize La taille des données à mettre à jour
  @param data Les données à mettre à jour
*/
void BufferObject::update(GLsizeiptr dataSize, const void *data)
{
  bind();
  glBufferSubData(m_type, 0, dataSize, data);
}

/*
  Sert à mapper un buffer pour une opération de mapping.
  Mapper un buffer permet de faire des opérations sur les données du buffer directement dans la mémoire du GPU.
  @return Un pointeur sur les données du buffer
*/
void *BufferObject::mapBuffer()
{
  bind();
  return glMapBuffer(m_type, GL_WRITE_ONLY);
}

/*
  Sert à démapper un buffer après une opération de mapping.
*/
void BufferObject::unmapBuffer()
{
  bind();
  glUnmapBuffer(m_type);
}
