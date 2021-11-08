#ifndef H_VERTEX
#define H_VERTEX

#include <GL/glew.h>

struct Vertex
{
	struct Position
	{
		float x;
		float y;
	} position;

	struct Color
	{
		GLubyte r;
		GLubyte g;
		GLubyte b;
	} color;
	
	GLubyte padding; // To make the struct size a multiple of 4; alignment issues.
};

#endif
