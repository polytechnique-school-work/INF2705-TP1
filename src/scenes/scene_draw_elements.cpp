#include "scene_draw_elements.h"

#include "vertices_data.h"
#include "utils.h"

SceneDrawElements::SceneDrawElements(Resources &res)
    : Scene(res),
      m_coloredSquareReduceDraw(m_coloredSquareReduceVao, 4)
{
  // 1. Il utilisera le shader de couleur et les vertices possèdent l’attribut de position et de couleur.
  // On alloue le buffer avec les vertices du colorSquareVertices
  m_resources.coloredSquareReduceBuffer.allocate(GL_ARRAY_BUFFER, sizeof(colorSquareVerticesReduced), colorSquareVerticesReduced, GL_STATIC_DRAW);
  CHECK_GL_ERROR;
  m_coloredSquareReduceVao.specifyAttribute(m_resources.coloredSquareReduceBuffer, 0, 2, 5 * sizeof(float), 0 * sizeof(float));
  // CHECK_GL_ERROR;
  m_coloredSquareReduceVao.specifyAttribute(m_resources.coloredSquareReduceBuffer, 1, 3, 5 * sizeof(float), 2 * sizeof(float));
  // CHECK_GL_ERROR;
}

void SceneDrawElements::run(Window &w)
{
  // CHECK_GL_ERROR;
  m_resources.color.use();
  // CHECK_GL_ERROR;

  // Le DRAW provoque un segfault
  m_coloredSquareReduceDraw.draw();
  // CHECK_GL_ERROR;
}
