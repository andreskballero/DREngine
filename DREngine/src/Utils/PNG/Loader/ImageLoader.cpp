#include "ImageLoader.h"
#include "../../IO/IOManager.h"
#include "../picoPNG/picoPNG.h"
#include "../../Errors/Errors.h"

#include <vector>

namespace loader
{
	gl::GLTexture ImageLoader::loadPNG(std::string filePath)
	{
		gl::GLTexture texture = {}; // Initializes every member to zero.

		// Variables to pass to picoPNG.
		std::vector<unsigned char> in;
		std::vector<unsigned char> out;
		unsigned long width;
		unsigned long height;

		// Read a PNG to a buffer.
		if (!iomanager::IOManager::readFileToBuffer(filePath, in))
		{
			utils::checkError("Failed to load PNG file to buffer.");
		}

		// Decode the image.
		int errorCode = png::decodePNG(out, width, height, &(in[0]), in.size());
		if (errorCode != 0)
		{
			utils::checkError("decodePNG failed.");
		}

		// Create OpenGL texture.
		glGenTextures(1, &(texture.id));
		// Bind texture and upload data to it.
		glBindTexture(GL_TEXTURE_2D, texture.id);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(out[0]));
		// How the texture should be treated.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_MIPMAP);
		glGenerateMipmap(GL_TEXTURE_2D);
		// Unbind texture.
		glBindTexture(GL_TEXTURE_2D, 0);

		return texture;
	}
}