#ifndef H_SPRITE
#define H_SPRITE

#include <GL/glew.h>

namespace sprite
{
	/**
	* Class that 
	*/
	class Sprite
	{
	public:
		/**
		* Constructor.
		*/
		Sprite();

		/**
		* Destructor.
		*/
		~Sprite();

		/**
		* Function that initializes the sprite with the position and dimension.
		*/
		void init(float x, float y, float width, float height);

		/**
		* Function that renders the sprite on screen.
		*/
		void draw();

	public:
		float _x;					// Sprite X position.
		float _y;					// Sprite Y position.
		float _width;				// Sprite width.
		float _height;				// Sprite height.

		GLuint _vboID;				// Vertex Buffer Object - Unique ID.
	};
}

#endif