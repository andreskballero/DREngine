#ifndef H_VERTEX
#define H_VERTEX

#include <GL/glew.h>

struct Position
{
	float x;
	float y;
};

struct Color
{
	GLubyte r;
	GLubyte g;
	GLubyte b;
};

struct Vertex
{
	Position position;
	Color color;
	
	GLubyte padding; // To make the struct size a multiple of 4; alignment issues.
};

#endif
