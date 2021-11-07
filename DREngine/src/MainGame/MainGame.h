#ifndef H_MAINGAME
#define H_MAINGAME

#include <SDL/SDL.h>
#include <GL/glew.h>

/**
* Namespace for the maingame tools.
*/
namespace maingame
{
	/**
	* Class that manages the SDL system initialization and the game loop and everyting related.
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
		* Function that.
		*/
		void run();
	private:
		/**
		* Function that.
		*/
		void initSystems();

		SDL_Window* _window;			// Pointer to the game window.
		int _screenWidth;				// Game screen width.
		int _screenHeight;				// Game screen height.
	};
}

#endif