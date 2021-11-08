#version 130
// The fragment shader operates on each pixel in a given polygon.

in vec3 fragmentColor;

// This is the three component float vector that gets outputted to the
// screen for each pixel.
out vec3 color;

void main()
{
	color = fragmentColor;
}