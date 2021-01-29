#version 400 core

precision highp float;

in vec2 pos;

out vec4 fragColor;

uniform vec3 color;

void main()
{
    vec2 uv = pos;
    
    float radius = 0.5;

    if(distance(vec2(0.5,0.5),uv) > radius)
        discard;

    fragColor = vec4(color,1.0);
}