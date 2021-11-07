#include "Errors.h"

#include <cstdio>

#include <SDL/SDL.h>
#include <GL/glew.h>

namespace utils
{
	void checkErrorSDL(const char* error)
	{
		printf("\n%s failure: %s\n", error, SDL_GetError());
		SDL_Quit();
	}

	void checkErrorGLEW(const char* error, const GLenum errorId)
	{
		printf("\n%s failure: %s\n", error, glewGetErrorString(errorId));
		SDL_Quit();
	}

	void checkError(const char* error)
	{
		printf("\n%s\n", error);
		SDL_Quit();
	}
}