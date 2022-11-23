#version 460 core

in vec3 colorF;

uniform double uTime;

out vec4 outColor;

void main() {

	outColor = vec4(colorF.r + abs(sin(float(uTime))) / 1.1 - 0.3,
					colorF.g + abs(sin(float(uTime))) / 1.1 - 0.3,
					colorF.b + abs(sin(float(uTime))) / 1.1 - 0.3,
					1.0f);
					
}