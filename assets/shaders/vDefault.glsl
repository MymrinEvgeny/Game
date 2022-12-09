#version 460 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 color;
layout(location = 2) in vec2 texCoord;

uniform float uTime;

out vec3 colorF;
out vec2 texCoordF;

void main() {
	
	colorF = color;
	texCoordF = texCoord;
	
	gl_Position = vec4(pos, 1.0);
	
}