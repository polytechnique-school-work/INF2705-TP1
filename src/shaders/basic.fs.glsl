#version 330 core

// TODO

out vec4 color;

void main() {
    color = vec4(1.0, 0.0, 0.0, 1.0); // Rouge opaque //couleur pris de chatGPT
}

//Le fragment shader fait simplement
//l’assignation d’une variable out de type vec4 pour la couleur de votre choix avec un alpha de 1
//(attention d’avoir une couleur différente du clearColor).
