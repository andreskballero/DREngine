#ifndef H_IMAGELOADER
#define H_IMAGELOADER

#include "../../../OpenGL/Texture/GLTexture.h"

#include <string>

namespace loader
{
	/**
	* Class that loads a PNG into an OpenGL texture.
	*/
	class ImageLoader
	{
	public:
		gl::GLTexture loadPNG(std::string filePath);
	};
}

#endif