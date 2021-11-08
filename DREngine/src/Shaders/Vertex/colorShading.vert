#version 130
// The vertex shader operates on each vertex.

// Input data from the VBO. Each vertex is two floats.
in vec2 vertexPosition;
in vec3 vertexColor;

out vec3 fragmentColor;

void main()
{
	// Set the x, y position on the screen.
	gl_Position.xy = vertexPosition;

	// The z position is zero since we are in 2D.
	gl_Position.z = 0.0;

	// Indicate that the coordinates are normalized.
	gl_Position.w = 1.0;

	// Set variable to the fragment shader.
	fragmentColor = vertexColor;
}