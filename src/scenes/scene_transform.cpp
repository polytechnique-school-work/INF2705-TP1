#include "scene_transform.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

SceneTransform::SceneTransform(Resources &res, bool &isMouseMotionEnabled, bool &isThirdPerson, bool &isOrtho)
    : Scene(res),
      m_isMouseMotionEnabled(isMouseMotionEnabled),
      m_isThirdPerson(isThirdPerson),
      m_isOrtho(isOrtho)
{

   // TODO

}

void SceneTransform::run(Window &w)
{
  updateInput(w);

    // TODO
    const float SCREEN_SIZE_ORTHO = 5.0f;

    GLdouble left = -SCREEN_SIZE_ORTHO/2.0;
    GLdouble right = SCREEN_SIZE_ORTHO/2.0f;
    GLdouble bottom = -SCREEN_SIZE_ORTHO/2.0f;
    GLdouble top = SCREEN_SIZE_ORTHO/2;
    GLdouble near = 0.1f; //near plane
    GLdouble far = 100.0f; //far plane

    //matrice de projection orthographique
    glm::mat4 projectionOrtho = glm::ortho(left, right, bottom, top, near, far);

    //matrice de projection de perspective
    float aspectRatio = static_cast<float>(w.getWidth()) / static_cast<float>(w.getHeight());
    glm::mat4 projectionPersp = glm::perspective(glm::radians(70.0f), aspectRatio, 0.1f, 100.0f);

    //TODO
    //matrice de vue en première personne
    glm::mat4 cameraFirstPerson = getCameraFirstPerson();

    //Il faudra faire des rotations selon l’orientation de la caméra et une translation selon la positio de la caméra (glm::lookAt ne sera pas accepté).

    //TODO
    //matrice de vue en troisième personne
    glm::mat4 cameraThirdPerson = getCameraThirdPerson();
    //L’utilisation de glm::lookAt et des coordonnées sphériques sera utile. On utilisera un rayon de 6 pour la position de la caméra. 
    //Puisqu’on voudra initialement avoir la caméra au niveau du sol, un décalement de π/2 sera appliqué sur l’orientation en x et y. 
    //La caméra fixe l’origine de la scène.

    //TODO
    //matrice de modèle de la base du carrousel
    glm::mat4 baseModel = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -0.1f, 0.0f));

    //TODO
    //matrice modèle du groupe de pôle et cheval
    //est à une hauteur de 1 en y, un rayon de 1.7 en x et à un angle multiple de 2π/N_HORSES. 
    //Vous ne devriez pas avoir de trigonométrie dans le code des transformations.

    //TODO
    //matrice d’animation de rotation pour le groupe de pôle et cheval pour faire tourner le carrousel
    //L’angle est m_carouselAngleRad

    //TODO
    //matrice d’animation de translation pour le cheval pour l’animé de haut en bas
    //Un cheval sur deux à une translation positive de carouselHorseTranslation, l’autre est négative.  
    //Pensez à la réutilisation des matrices et essayer de minimiser le nombre de multiplication en mémorisant les matrices dans des variables.


  float carouselHorseTranslation = sin(m_carouselAngleRad * 2.0f) / 6.0f;
  const int N_HORSES = 5;
  for (int i = 0; i < N_HORSES; i++)
  {
    // TODO
  }
  m_carouselAngleRad -= 0.01f;
}

void SceneTransform::updateInput(Window &w)
{
  int x = 0, y = 0;
  if (m_isMouseMotionEnabled)
    w.getMouseMotion(x, y);
  m_cameraOrientation.y -= x * 0.01f;
  m_cameraOrientation.x -= y * 0.01f;

  glm::vec3 positionOffset = glm::vec3(0.0);
  const float SPEED = 0.1f;
  if (w.getKeyHold(Window::Key::W))
    positionOffset.z -= SPEED;
  if (w.getKeyHold(Window::Key::S))
    positionOffset.z += SPEED;
  if (w.getKeyHold(Window::Key::A))
    positionOffset.x -= SPEED;
  if (w.getKeyHold(Window::Key::D))
    positionOffset.x += SPEED;

  if (w.getKeyHold(Window::Key::Q))
    positionOffset.y -= SPEED;
  if (w.getKeyHold(Window::Key::E))
    positionOffset.y += SPEED;

  positionOffset = glm::rotate(glm::mat4(1.0f), m_cameraOrientation.y, glm::vec3(0.0, 1.0, 0.0)) * glm::vec4(positionOffset, 1);
  m_cameraPosition += positionOffset;
}

glm::mat4 SceneTransform::getCameraFirstPerson()
{
  // TODO
}

glm::mat4 SceneTransform::getCameraThirdPerson()
{
  // TODO
}
