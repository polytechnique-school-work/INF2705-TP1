#version 330 core

in uniform vertexColor;

out vec4 fragColor;

void main() {
    fragColor = vertexColor;
}