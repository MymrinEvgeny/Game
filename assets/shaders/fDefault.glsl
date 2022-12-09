#version 460 core

in vec3 colorF;
in vec2 texCoordF;

uniform float uTime;
uniform sampler2D TEXTURE0;
uniform sampler2D TEXTURE1;
uniform float interpolate;

out vec4 outColor;

void main() {

	outColor = mix(
		texture(TEXTURE0, texCoordF),
		texture(TEXTURE1, texCoordF),
		interpolate);
	
}