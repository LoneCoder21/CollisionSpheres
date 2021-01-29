#version 400 core

precision highp float;

in vec2 pos;

out vec4 fragColor;

uniform vec3 color;

void main()
{
    vec2 uv = pos;
 
    fragColor = vec4(color,1.0);
}