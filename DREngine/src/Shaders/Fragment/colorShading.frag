#version 130
// The fragment shader operates on each pixel in a given polygon.

in vec2 fragmentPosition;
in vec3 fragmentColor;

// This is the three component float vector that gets outputted to the
// screen for each pixel.
out vec3 color;

// Global variable.
uniform float time;

void main()
{
	color = vec3(fragmentColor.x * (cos(fragmentPosition.x * 8.0 + time) + 1.0) * 0.5,
				 fragmentColor.y * (cos(fragmentPosition.y * 4.0 + time) + 1.0) * 0.5,
				 fragmentColor.z * (cos(fragmentPosition.x * 2.0 + time) + 1.0) * 0.5);
}