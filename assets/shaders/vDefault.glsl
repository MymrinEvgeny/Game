#version 460 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 color;

uniform double uTime;

out vec3 colorF;

vec2 fun(vec2 pos) {
	float alpha = float(uTime) / 2;
	vec2 res = vec2(
		cos(alpha) * pos.x - sin(alpha) * pos.y,
		sin(alpha) * pos.x + cos(alpha) * pos.y
	);
	return res;
}

void main() {
	
	colorF = color;
	
	gl_Position = vec4(fun(vec2(pos.x, pos.y)), pos.z, 1.0);
	
}