#include "scene_shared_vao.h"
#include "vertices_data.h"
#include <utils.h>

SceneSharedVao::SceneSharedVao(Resources &res)
    : Scene(res),
      m_coloredTriangleSharedDraw(m_sharedVao, 3),
      m_coloredSquareSharedDraw(m_sharedVao, 6)

{
  m_resources.coloredTriangleBuffer.bind();

  // m_sharedVao.bind();
  //

  // m_resources.coloredTriangleBuffer.allocate(GL_ARRAY_BUFFER, sizeof(colorTriVertices), colorTriVertices, GL_STATIC_DRAW);
  //

  // déjà alloué dans scene_colored_triangle

  // m_resources.coloredSquareReduceBuffer.allocate(GL_ARRAY_BUFFER, sizeof(colorSquareVertices), colorSquareVertices, GL_STATIC_DRAW);
  //

  // m_resources.coloredSquareReduceIndicesBuffer.allocate(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes, GL_STATIC_DRAW);
  //

  // déjà alloué dans scene_draw_elements
}

void SceneSharedVao::run(Window &w)
{
  // Exceptionnellement, cette méthode n'est pas utilisée
}

void SceneSharedVao::runTriangle()
{
  m_sharedVao.bind();

  m_sharedVao.specifyAttribute(m_resources.coloredTriangleBuffer, 0, 2, 5 * sizeof(float), 0 * sizeof(float));

  m_sharedVao.specifyAttribute(m_resources.coloredTriangleBuffer, 1, 3, 5 * sizeof(float), 2 * sizeof(float));

  m_resources.coloredTriangleBuffer.bind();

  m_resources.color.use();

  m_coloredTriangleSharedDraw.draw();

  m_sharedVao.unbind();
}

void SceneSharedVao::runSquare()
{
  m_sharedVao.bind();

  m_sharedVao.specifyAttribute(m_resources.coloredSquareReduceBuffer, 0, 2, 5 * sizeof(float), 0 * sizeof(float));

  m_sharedVao.specifyAttribute(m_resources.coloredSquareReduceBuffer, 1, 3, 5 * sizeof(float), 2 * sizeof(float));

  m_resources.coloredSquareReduceBuffer.bind();

  m_resources.coloredSquareReduceIndicesBuffer.bind();

  m_resources.color.use();

  m_coloredSquareSharedDraw.draw();

  m_sharedVao.unbind();
}
