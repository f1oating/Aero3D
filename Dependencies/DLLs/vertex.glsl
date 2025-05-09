#version 330 core

layout(std140, binding = 0) uniform MyBlock {
    vec3 u_Color;
    float _padding;
};

layout(location = 0) in vec2 a_Position;
out vec3 v_Color;
void main()
{
    gl_Position = vec4(a_Position, 0.0, 1.0);
    v_Color = u_Color;
}