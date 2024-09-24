#include "scene_triangle.h"

#include "vertices_data.h"

#include "utils.h"

SceneTriangle::SceneTriangle(Resources &res)
    : Scene(res),
        m_triangleBuffer(GL_ARRAY_BUFFER),
        m_triangleDraw(m_triangleVao, 3)
{
  // 1. Initialiser les shaders dans resource

  // 2. Utiliser les vertices
  m_triangleBuffer.allocate(GL_ARRAY_BUFFER, sizeof(triVertices), triVertices, GL_STATIC_DRAW);
  CHECK_GL_ERROR;
  // 3. Configurer les buffers et les attributs de vertex
  m_triangleVao.specifyAttribute(m_triangleBuffer, 0, 2, 2 * sizeof(float), 0 * sizeof(float));
  CHECK_GL_ERROR;
}

void SceneTriangle::run(Window &w)
{
  // 4. Dessiner le triangle
  CHECK_GL_ERROR;
  m_resources.basic.use();
  CHECK_GL_ERROR;
  m_triangleDraw.draw();
  m_triangleVao.unbind();
}
