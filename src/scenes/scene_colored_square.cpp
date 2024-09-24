#include "scene_colored_square.h"

#include "vertices_data.h"
#include <utils.h>

SceneColoredSquare::SceneColoredSquare(Resources &res)
    : Scene(res),
    m_coloredSquareBuffer(GL_ARRAY_BUFFER),
    m_coloredSquareDraw(m_coloredSquareVao, 4)
{
    m_coloredSquareBuffer.allocate(GL_ARRAY_BUFFER, sizeof(colorSquareVertices), colorSquareVertices, GL_STATIC_DRAW);
    CHECK_GL_ERROR;
    m_coloredSquareVao.specifyAttribute(m_coloredSquareBuffer, 0, 2, 5 * sizeof(float), 0 * sizeof(float));
    CHECK_GL_ERROR;
    m_coloredSquareVao.specifyAttribute(m_coloredSquareBuffer, 1, 3, 5 * sizeof(float), 2 * sizeof(float));
    CHECK_GL_ERROR;
}

void SceneColoredSquare::run(Window &w)
{
    CHECK_GL_ERROR;
    m_resources.color.use();
    CHECK_GL_ERROR;
    m_coloredSquareDraw.draw();
}
