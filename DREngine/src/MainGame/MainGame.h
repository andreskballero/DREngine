#ifndef H_MAINGAME
#define H_MAINGAME

#include "../Sprite/Sprite.h"
#include "../Shaders/GLSLProgram.h"

#include <SDL/SDL.h>
#include <GL/glew.h>

/**
* Enum to keep track of the game states.
*/
enum GAME_STATE
{
	UNKNOWN = 0,
	PLAY,
	EXIT
};

/**
* Namespace for the maingame tools.
*/
namespace maingame
{
	/**
	* Class that manages the systems initialization and the game loop, and everyting related.
	*/
	class MainGame
	{
	public:
		/**
		* Constructor.
		*/
		MainGame();

		/**
		* Destructor.
		*/
		~MainGame();

		/**
		* Function that runs the game, initializing every needed system and running the
		* main game loop.
		*/
		void run();
	private:
		/**
		* Function that initializes the needed systems to run the game.
		*/
		void initSystems();

		/**
		* Function that initializes the shaders.
		*/
		void initShaders();

		/**
		* Function that keeps the game inside the main game loop.
		*/
		void gameLoop();

		/**
		* Function that processes the input logic.
		*/
		void processInput();

		/**
		* Function that renders the game.
		*/
		void drawGame();

		SDL_Window* _window;				// Pointer to the game window.
		int _screenWidth;					// Game screen width.
		int _screenHeight;					// Game screen height.

		GAME_STATE _gameState;				// Current game state.

		sprite::Sprite _sprite;				// Sprite.

		glsl::GLSLProgram _colorProgram;	// Object that controls the color shaders.

		float _time;						// Time.
	};
}

#endif