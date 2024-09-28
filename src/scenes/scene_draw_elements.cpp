#include "scene_draw_elements.h"

#include "vertices_data.h"
#include "utils.h"
#include <iostream>

SceneDrawElements::SceneDrawElements(Resources &res)
    : Scene(res),
      m_coloredSquareReduceDraw(m_coloredSquareReduceVao, 6)
{
  m_coloredSquareReduceVao.bind();

  m_resources.coloredSquareReduceBuffer.allocate(GL_ARRAY_BUFFER, sizeof(colorSquareVerticesReduced), colorSquareVerticesReduced, GL_STATIC_DRAW);
  CHECK_GL_ERROR;
  m_resources.coloredSquareReduceIndicesBuffer.allocate(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes, GL_STATIC_DRAW);
  CHECK_GL_ERROR;

  m_coloredSquareReduceVao.specifyAttribute(m_resources.coloredSquareReduceBuffer, 0, 2, 5 * sizeof(float), 0 * sizeof(float));
  CHECK_GL_ERROR;

  m_coloredSquareReduceVao.specifyAttribute(m_resources.coloredSquareReduceBuffer, 1, 3, 5 * sizeof(float), 2 * sizeof(float));
  CHECK_GL_ERROR;
}

void SceneDrawElements::run(Window &w)
{


    m_coloredSquareReduceVao.bind();

    m_resources.coloredSquareReduceBuffer.bind();
    m_resources.coloredSquareReduceIndicesBuffer.bind();
    CHECK_GL_ERROR;
    m_resources.color.use();
    CHECK_GL_ERROR;


  m_coloredSquareReduceDraw.draw();
  CHECK_GL_ERROR;
}
