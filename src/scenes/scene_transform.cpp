#include "scene_transform.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <utils.h>

SceneTransform::SceneTransform(Resources &res, bool &isMouseMotionEnabled, bool &isThirdPerson, bool &isOrtho)
    : Scene(res),
      m_isMouseMotionEnabled(isMouseMotionEnabled),
      m_isThirdPerson(isThirdPerson),
      m_isOrtho(isOrtho),
      m_carouselFrame("../models/carousel_frame.obj"),
      m_carouselPole("../models/carousel_pole.obj"),
      m_carouselHorse("../models/carousel_horse.obj")
{
  m_resources.mvpLocationTransformSolidColor = m_resources.transformSolidColor.getUniformLoc("mvp");

  m_resources.colorLocationTransformSolidColor = m_resources.transformSolidColor.getUniformLoc("vertexColor");
}

void SceneTransform::run(Window &w)
{
  updateInput(w);

  // TODO
  const float SCREEN_SIZE_ORTHO = 5.0f;

  GLdouble left = -SCREEN_SIZE_ORTHO / 2.0;
  GLdouble right = SCREEN_SIZE_ORTHO / 2.0f;
  GLdouble bottom = -SCREEN_SIZE_ORTHO / 2.0f;
  GLdouble top = SCREEN_SIZE_ORTHO / 2;
  GLdouble near = 0.1f;  // near plane
  GLdouble far = 100.0f; // far plane

  // matrice de projection orthographique
  glm::mat4 projectionOrtho = glm::ortho(left, right, bottom, top, near, far);

  // matrice de projection de perspective
  float aspectRatio = static_cast<float>(w.getWidth()) / static_cast<float>(w.getHeight());
  glm::mat4 projectionPersp = glm::perspective(glm::radians(70.0f), aspectRatio, 0.1f, 100.0f);

  glm::mat4 projection = m_isOrtho ? projectionOrtho : projectionPersp;

  glm::mat4 view = m_isThirdPerson ? getCameraThirdPerson() : getCameraFirstPerson();

  // matrice de modèle de la base du carrousel
  glm::mat4 baseModel = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -0.1f, 0.0f));

  // TODO
  // matrice modèle du groupe de pôle et cheval
  // est à une hauteur de 1 en y, un rayon de 1.7 en x et à un angle multiple de 2π/N_HORSES.
  // Vous ne devriez pas avoir de trigonométrie dans le code des transformations.

  m_resources.transformSolidColor.use();

  glEnable(GL_DEPTH_TEST);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  float carouselHorseTranslation = sin(m_carouselAngleRad * 2.0f) / 6.0f;
  const int N_HORSES = 5;
  for (int i = 0; i < N_HORSES; i++)
  {
    glm::mat4 horsePoleGroup = glm::mat4(1.0f);

    // animation: (carrousel tourne)
    horsePoleGroup = glm::rotate(horsePoleGroup, m_carouselAngleRad, glm::vec3(0.0f, 1.0f, 0.0f)); // rotation en y

    // animation: la direction et la translation sont en y, les chevaux bougent de haut en bas
    float directiony = (i % 2 == 0) ? 1.0f : -1.0f;
    horsePoleGroup = glm::translate(horsePoleGroup, glm::vec3(0.0f, directiony * carouselHorseTranslation, 0.0f));

    // matrice de rotation pour placer les chevaux
    horsePoleGroup = glm::rotate(horsePoleGroup, 2 * glm::pi<float>() / N_HORSES * (float)(i), glm::vec3(0.0f, 1.0f, 0.0f));

    // éloigner les chevaux de l'origine
    horsePoleGroup = glm::translate(horsePoleGroup, glm::vec3(1.7f, 1.0f, 0.0f));

    glm::mat4 mvpHorsePoleGroup = projection * view * horsePoleGroup;

    glUniformMatrix4fv(m_resources.mvpLocationTransformSolidColor, 1, GL_FALSE, glm::value_ptr(mvpHorsePoleGroup));

    glUniform4f(m_resources.colorLocationTransformSolidColor, 0.0f, 0.0f, 1.0f, 1.0f);
    m_carouselHorse.draw();

    glUniform4f(m_resources.colorLocationTransformSolidColor, 0.0f, 1.0f, 0.0f, 1.0f);
    m_carouselPole.draw();
  }
  m_carouselAngleRad -= 0.01f;

  glm::mat4 mvpBase = projection * view * baseModel;

  glUniformMatrix4fv(m_resources.mvpLocationTransformSolidColor, 1, GL_FALSE, glm::value_ptr(mvpBase));

  glUniform4f(m_resources.colorLocationTransformSolidColor, 1.0f, 0.0f, 0.0f, 0.0f);
  m_carouselFrame.draw();
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
  // matrice de base
  glm::mat4 firstPers = glm::mat4(1.0f);

  // rotation en x
  firstPers = glm::rotate(firstPers, m_cameraOrientation.x, glm::vec3(1.0f, 0.0f, 0.0f));
  // rotation en y
  firstPers = glm::rotate(firstPers, m_cameraOrientation.y, glm::vec3(0.0f, 1.0f, 0.0f));
  firstPers = glm::translate(firstPers, -m_cameraPosition);

  return firstPers;
}

glm::mat4 SceneTransform::getCameraThirdPerson()
{
  // https://stackoverflow.com/questions/21830340/understanding-glmlookat
  //  rayon pour la position de la caméra
  float radius = 6.0f;

  // caméra avec un décalement de pi/2
  float rotationx = m_cameraOrientation.x + glm::radians(90.0f);
  float rotationy = m_cameraOrientation.y + glm::radians(90.0f);

  // coordonnées sphériques?
  float x = radius * cos(rotationx) * sin(rotationy);
  float y = radius * sin(rotationx);
  float z = radius * cos(rotationx) * cos(rotationy);

  // placer la caméra avec les coordonnées sphériques (eye)
  glm::vec3 camera = glm::vec3(x, y, z);

  // target est l'origine de la scène
  glm::vec3 target = glm::vec3(0.0f, 0.0f, 0.0f);

  // normale à la caméra? (up vectot)
  glm::vec3 normale = glm::vec3(0.0f, 1.0f, 0.0f);

  // générer la matrice
  glm::mat4 thirdPers = glm::lookAt(camera, target, normale);

  return thirdPers;
}
