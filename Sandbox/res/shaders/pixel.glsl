#version 420 core

in vec3 v_Color;
in vec2 v_TexCoord;

out vec4 FragColor;

uniform sampler2D ourTexture;

void main()
{
    vec4 texColor = texture(ourTexture, v_TexCoord);
    FragColor = texColor * vec4(v_Color, 1.0);
}