#include <cstdio>

#include "MainGame.h"

namespace maingame
{
	MainGame::MainGame() :
		_window{nullptr},
		_screenWidth{1024},
		_screenHeight{768}
	{

	}

	MainGame::~MainGame()
	{

	}

	void MainGame::run()
	{
		initSystems();
	}

	void MainGame::initSystems()
	{
		// SDL must initialize correctly.
		if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
		{
			_window = SDL_CreateWindow("DREngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);

			// SDL must create the window correctly.
			if (_window != nullptr)
			{

			}
			else
			{
				// SDL has failed creating the window.
				printf("\nSDL_CreateWindow() failure: %s\n", SDL_GetError());
			}
		}
		else
		{
			// SDL has failed initializing.
			printf("\nSDL_Init() failure: %s\n", SDL_GetError());
		}
	}
}