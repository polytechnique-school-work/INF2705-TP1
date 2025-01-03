#include "scene_colored_triangle.h"

#include "vertices_data.h"
#include <utils.h>

SceneColoredTriangle::SceneColoredTriangle(Resources &res)
    : Scene(res),
      m_coloredTriangleDraw(m_coloredTriangleVao, 3)
{
  // 1. Initialiser les shaders dans resource

  // 2. Utiliser les vertices

  res.coloredTriangleBuffer.allocate(GL_ARRAY_BUFFER, sizeof(colorTriVertices), colorTriVertices, GL_STATIC_DRAW);

  // 3. Configurer les buffers et les attributs de vertex
  m_coloredTriangleVao.specifyAttribute(res.coloredTriangleBuffer, 0, 2, 5 * sizeof(float), 0 * sizeof(float));

  m_coloredTriangleVao.specifyAttribute(res.coloredTriangleBuffer, 1, 3, 5 * sizeof(float), 2 * sizeof(float));
}

void SceneColoredTriangle::run(Window &w)
{
  // 4. Dessiner le triangle

  m_resources.color.use();

  m_coloredTriangleDraw.draw();
}
