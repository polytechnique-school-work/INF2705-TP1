#version 330 core

uniform vec4 vertexColor;

out vec4 fragColor;

void main() {
    fragColor = vertexColor;
}