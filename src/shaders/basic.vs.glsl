#version 330 core

// TODO

layout(location = 0) in vec3 position;

vec3 position;

void main() {
    gl_Position = position;

}

//L’entrée du vertex shader est un vec3
//à la location 0 pour la position. 

L’implémentation du main du programme est simplement d’assigner la valeur de gl_Position 
//à la valeur de l’entrée. 