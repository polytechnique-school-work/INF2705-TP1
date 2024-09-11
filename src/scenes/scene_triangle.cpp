#include "scene_triangle.h"

#include "vertices_data.h"

SceneTriangle::SceneTriangle(Resources &res)
    : Scene(res)
{
  // TODO

  // 1. Initialiser les shaders
  m_resources.initShaderProgram(m_resources.basic, "shaders/basic.vs.glsl", "shaders/basic.fs.glsl");

  // 2. Utiliser les vertices
  m_resources.coloredTriangleBuffer.allocate(GL_ARRAY_BUFFER, sizeof(triVertices), triVertices, GL_STATIC_DRAW);

  // 3. Configurer les buffers et les attributs de vertex

  // 4. Dessiner le triangle
  m_triangleDraw.draw();
}

void SceneTriangle::run(Window &w)
{
  // TODO
}
