#include "MainGame.h"
#include "../Utils/Errors.h"

#include <cstdio>

namespace maingame
{
	MainGame::MainGame() :
		_window{nullptr},
		_screenWidth{1024},
		_screenHeight{768},
		_gameState{PLAY},
		_time{0.0f}
	{

	}

	MainGame::~MainGame()
	{

	}

	void MainGame::run()
	{
		// Initialize all systems.
		initSystems();

		_sprite.init(-1.0f, -1.0f, 1.0f, 1.0f); // Tmp for test.

		// Game loop.
		gameLoop();
	}

	void MainGame::initSystems()
	{
		// SDL must initialize correctly.
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			// SDL has failed initializing.
			utils::checkErrorSDL("SDL_Init()");
		}

		// SDL must create the window correctly.
		_window = SDL_CreateWindow("DREngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
		if (_window == nullptr)
		{
			// SDL has failed creating the window.
			utils::checkErrorSDL("SDL_CreateWindow()");
		}

		// Set OpenGL context so the program is able to use OpenGL.
		SDL_GLContext glContext = SDL_GL_CreateContext(_window);
		if (glContext == nullptr)
		{
			// Glew has failed initializing.
			utils::checkErrorSDL("SDL_GL_CreateContext()");
		}

		// Initialize Glew.
		GLenum glewInitCheck = glewInit();
		if (glewInitCheck != GLEW_OK)
		{
			// Glew has failed initializing.
			utils::checkErrorGLEW("glewInit()", glewInitCheck);
		}

		// Tell SDL that we want to double buffer: have two windows - (0) draw to while (1) is being cleared.
		// This prevents from flickering, it's much smoother.
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		// Every time we call GL_COLOR_BUFFER_BIT, this color is drawn on the screen.
		glClearColor(0.0f, 1.0f, 1.0f, 1.0f);

		// Initialize the shaders.
		initShaders();
	}

	void MainGame::initShaders()
	{
		_colorProgram.compileShaders("src/Shaders/Vertex/colorShading.vert", "src/Shaders/Fragment/colorShading.frag");
		_colorProgram.addAttribute("vertexPosition");
		_colorProgram.addAttribute("vertexColor");
		_colorProgram.linkShaders();
	}

	void MainGame::gameLoop()
	{
		while (_gameState != EXIT)
		{
			// (0) Process input.
			processInput();

			// Increment time;
			_time += 0.01f;

			// (1) Render.
			drawGame();
		}
	}

	void MainGame::processInput()
	{
		// Event object to keep track of the events in the event queue.
		SDL_Event evnt;

		// Ask OS what events need to be processed. All events in the queue.
		while (SDL_PollEvent(&evnt))
		{
			switch (evnt.type)
			{
			case SDL_QUIT:
				_gameState = EXIT;
				break;
			}
		}
	}

	void MainGame::drawGame()
	{
		// Set OpenGL depth.
		glClearDepth(1.0f);

		// Clear buffer (clear the screen).
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		_colorProgram.use();

		// Set uniforms before drawing.
		GLuint timeLocation = _colorProgram.getUniformLocation("time");
		// Send variable.
		glUniform1f(timeLocation, _time);

		_sprite.draw();

		_colorProgram.unuse();

		// A B - B A. Flush everything we draw to the screen.
		SDL_GL_SwapWindow(_window);
	}
}