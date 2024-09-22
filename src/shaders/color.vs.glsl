#version 330 core

layout(location = 0) in vec3 position;

layout(location = 1) out vec3 color;

out vec3 fragColor;

void main() {
    gl_Position = position;

    fragColor = color;
}