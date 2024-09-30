#include "scene_square.h"

#include "vertices_data.h"
#include <utils.h>

SceneSquare::SceneSquare(Resources &res)
    : Scene(res),
      m_squareBuffer(GL_ARRAY_BUFFER),
      m_squareDraw(m_squareVao, 6)
{
  // 1. Initialiser les shaders dans resource

  // 2. Utiliser les vertices
  m_squareBuffer.allocate(GL_ARRAY_BUFFER, sizeof(squareVertices), squareVertices, GL_STATIC_DRAW);

  // 3. Configurer les buffers et les attributs de vertex
  m_squareVao.specifyAttribute(m_squareBuffer, 0, 2, 2 * sizeof(float), 0 * sizeof(float));
}

void SceneSquare::run(Window &w)
{

  m_resources.basic.use();

  m_squareDraw.draw();
  m_squareVao.unbind();
}