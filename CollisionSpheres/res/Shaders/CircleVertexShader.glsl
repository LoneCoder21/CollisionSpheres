#version 400 core

precision highp float;

layout (location = 0) in vec3 aPos;

uniform mat4 trans;

out vec2 pos;

void main()
{
    vec4 cPos = trans * vec4(aPos,1.0);
    
    gl_Position = cPos;
    pos = .5*aPos.xy+.5;
}