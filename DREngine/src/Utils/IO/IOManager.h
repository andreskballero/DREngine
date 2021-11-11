#ifndef H_IOMANAGER
#define H_IOMANAGER

#include <string>
#include <vector>

namespace iomanager
{
	/**
	* Static class that manages the input and output for the game engine.
	*/
	class IOManager
	{
	public:
		/**
		* Function that reads a specific file to a buffer.
		*/
		static bool readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer);
	};
}

#endif