#include "model.h"
#include "obj_loader.h"

// Je l'initialise à 0 et après je le change avec la taille des indices
Model::Model(const char *path) : m_drawcall(m_vao, 0, GL_UNSIGNED_INT)
{
    m_vao.bind();

    std::vector<GLfloat> vertexData = {};
    std::vector<GLuint> indices = {};
    loadObj(path, vertexData, indices);

    m_vbo.allocate(GL_ARRAY_BUFFER, vertexData.size() * sizeof(GLfloat), vertexData.data(), GL_STATIC_DRAW);
    m_ebo.allocate(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
    m_vao.specifyAttribute(m_vbo, 0, 3, 3 * sizeof(float), 0 * sizeof(float));
    m_drawcall.setCount(indices.size());
}

void Model::loadObj(const char *path, std::vector<GLfloat> &vertexData, std::vector<GLuint> &indices)
{
    objl::Loader loader;
    bool loadout = loader.LoadFile(path);
    if (!loadout)
    {
        std::cout << "Unable to load model " << path << std::endl;
        return;
    }

    for (size_t i = 0; i < loader.LoadedVertices.size(); i++)
    {
        objl::Vector3 p = loader.LoadedVertices[i].Position;
        vertexData.push_back(p.X);
        vertexData.push_back(p.Y);
        vertexData.push_back(p.Z);
    }
    indices = loader.LoadedIndices;
}

void Model::draw()
{
    m_vao.bind();
    m_vbo.bind();
    m_ebo.bind();
    m_drawcall.draw();
}
