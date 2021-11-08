#include "Errors.h"

#include <cstdio>
#include <cstdlib>

#include <SDL/SDL.h>
#include <GL/glew.h>

namespace utils
{
	void checkErrorSDL(const char* error)
	{
		printf("\n%s failure: %s\n", error, SDL_GetError());
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	void checkErrorGLEW(const char* error, const GLenum errorId)
	{
		printf("\n%s failure: %s\n", error, glewGetErrorString(errorId));
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	void checkError(const char* error)
	{
		printf("\n%s\n", error);
		SDL_Quit();
		exit(EXIT_FAILURE);
	}
}