#include "IOManager.h"

#include <fstream>

namespace iomanager
{
	bool IOManager::readFileToBuffer(std::string filePath, std::vector<char>& buffer)
	{
		bool success = false;

		std::fstream file(filePath, std::ios::binary);

		if (file.fail())
		{
			perror(filePath.c_str());
		}
		else
		{
			// Put the reading pointer at the end of the file.
			file.seekg(0, std::ios::end);
			// Get the file size.
			int fileSize = file.tellg();
			// Back to the beginning.
			file.seekg(0, std::ios::beg);

			buffer.resize(fileSize);

			file.read(&(buffer[0]), fileSize);
			file.close();

			success = true;
		}

		return success;
	}
}