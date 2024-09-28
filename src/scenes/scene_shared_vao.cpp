#include "scene_shared_vao.h"

#include "vertices_data.h"
#include <utils.h>

SceneSharedVao::SceneSharedVao(Resources &res)
    : Scene(res),
    m_coloredTriangleSharedDraw(m_sharedVao, 3),
    m_coloredSquareSharedDraw(m_sharedVao, 6)

{
    m_sharedVao.bind();
    CHECK_GL_ERROR;
    
    m_resources.coloredTriangleBuffer.allocate(GL_ARRAY_BUFFER, sizeof(colorTriVertices), colorTriVertices, GL_STATIC_DRAW);
    CHECK_GL_ERROR;

    m_sharedVao.specifyAttribute(m_resources.coloredTriangleBuffer, 0, 2, 5 * sizeof(float), 0 * sizeof(float));
    CHECK_GL_ERROR;

    m_sharedVao.specifyAttribute(m_resources.coloredTriangleBuffer, 1, 3, 5 * sizeof(float), 2 * sizeof(float));
    CHECK_GL_ERROR;


    m_resources.coloredSquareReduceBuffer.allocate(GL_ARRAY_BUFFER, sizeof(colorSquareVertices), colorSquareVertices, GL_STATIC_DRAW);
    CHECK_GL_ERROR;

    m_resources.coloredSquareReduceIndicesBuffer.allocate(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes, GL_STATIC_DRAW);
    CHECK_GL_ERROR;

    m_sharedVao.specifyAttribute(m_resources.coloredSquareReduceBuffer, 2, 2, 5 * sizeof(float), 0 * sizeof(float));
    CHECK_GL_ERROR;

    m_sharedVao.specifyAttribute(m_resources.coloredSquareReduceBuffer, 3, 3, 5 * sizeof(float), 2 * sizeof(float));
    CHECK_GL_ERROR;
}

void SceneSharedVao::run(Window &w)
{
  // Exceptionnellement, cette méthode n'est pas utilisée
}

void SceneSharedVao::runTriangle()
{
    //m_sharedVao.bind();
    CHECK_GL_ERROR;
    m_resources.coloredTriangleBuffer.bind();
    CHECK_GL_ERROR;
    m_resources.color.use();
    CHECK_GL_ERROR;

    m_coloredTriangleSharedDraw.draw();
    CHECK_GL_ERROR;
}

void SceneSharedVao::runSquare()
{
    //m_sharedVao.bind();
    CHECK_GL_ERROR;
    m_resources.coloredSquareReduceBuffer.bind();
    CHECK_GL_ERROR;
    m_resources.coloredSquareReduceIndicesBuffer.bind();
    CHECK_GL_ERROR;
    m_resources.color.use();
    CHECK_GL_ERROR;

    m_coloredSquareSharedDraw.draw();
    CHECK_GL_ERROR;
}
