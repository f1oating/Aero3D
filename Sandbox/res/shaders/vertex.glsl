#version 420 core

layout(std140, binding=0) uniform MyBlock {
    vec4 u_Color;
};

layout(location = 0) in vec2 a_Position;
layout(location = 1) in vec2 a_TexCoord;

out vec3 v_Color;
out vec2 v_TexCoord;

void main()
{
    gl_Position = vec4(a_Position, 0.0, 1.0);
    v_Color = u_Color.rgb;
    v_TexCoord = a_TexCoord;
}
