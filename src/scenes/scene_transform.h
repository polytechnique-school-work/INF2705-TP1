#ifndef SCENE_TRANSFORM_H
#define SCENE_TRANSFORM_H

#include "scene.h"

#include <glm/glm.hpp>

#include "model.h"

class SceneTransform : public Scene
{
public:
    SceneTransform(Resources& res, bool& isMouseMotionEnabled, bool& isThirdPerson);

    virtual void run(Window& w);
    
    
private:
    void updateInput(Window& w);

    glm::mat4 getCameraFirstPerson();
    glm::mat4 getCameraThirdPerson();
    
private:
    bool& m_isMouseMotionEnabled;
    bool& m_isThirdPerson;

    glm::vec3 m_cameraPosition;
    glm::vec2 m_cameraOrientation;
    
    float m_carouselAngle;

    Model m_carouselFrame;
    Model m_carouselPole;
    Model m_carouselHorse;
};

#endif // SCENE_TRANSFORM_H
