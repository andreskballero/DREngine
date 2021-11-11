#ifndef H_GLTEXTURE
#define H_GLTEXTURE

#include <GL/glew.h>

namespace gl
{
	/**
	* OpenGL texture.
	*/
	struct GLTexture
	{
		GLuint id;
		int width;
		int height;
	};
}

#endif