#ifndef H_ERRORS
#define H_ERRORS

#include <GL/glew.h>

namespace utils
{
	// Function that prints an SDL error and quits the game.
	extern void checkErrorSDL(const char* error);

	// Function that prints a GLEW error and quits the game.
	extern void checkErrorGLEW(const char* error, const GLenum errorId);

	// Function that prints a generic error and quits the game.
	extern void checkError(const char* error);
}

#endif
