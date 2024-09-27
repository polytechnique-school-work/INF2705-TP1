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
  CHECK_GL_ERROR;
  // 3. Configurer les buffers et les attributs de vertex
  m_squareVao.specifyAttribute(m_squareBuffer, 0, 2, 2 * sizeof(float), 0 * sizeof(float));
  CHECK_GL_ERROR;
}

void SceneSquare::run(Window &w)
{
  CHECK_GL_ERROR;
  m_resources.basic.use();
  CHECK_GL_ERROR;
  m_squareDraw.draw();
  m_squareVao.unbind();
}