#include "scene_triangle.h"

#include "vertices_data.h"

SceneTriangle::SceneTriangle(Resources &res)
    : Scene(res),
      m_triangleDraw(m_triangleVao, 3)
{
  // 1. Initialiser les shaders dans resOURCE
  // m_resources.initShaderProgram(m_resources.basic, "shaders/basic.vs.glsl", "shaders/basic.fs.glsl");

  // 2. Utiliser les vertices
  m_triangleBuffer.allocate(GL_ARRAY_BUFFER, sizeof(triVertices), triVertices, GL_STATIC_DRAW);

  // 3. Configurer les buffers et les attributs de vertex
  m_triangleVao.specifyAttribute(m_triangleBuffer, 0, 3, 2 * sizeof(float), 2 * sizeof(float));
}

void SceneTriangle::run(Window &w)
{
  // 4. Dessiner le triangle
  m_resources.basic.use();
  m_triangleDraw.draw();
  m_triangleVao.unbind();
}
