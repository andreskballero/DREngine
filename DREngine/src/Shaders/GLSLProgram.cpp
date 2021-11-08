#include "GLSLProgram.h"
#include "../Utils/Errors.h"

#include <cstdio>

#include <vector>
#include <string>
#include <fstream>

namespace glsl
{
	GLSLProgram::GLSLProgram() :
		_numAttributes{0},
		_programID{0},
		_vertexShaderID{0},
		_fragmentShaderID{0}
	{

	}

	GLSLProgram::~GLSLProgram()
	{

	}

	void GLSLProgram::compileShaders(const char* vertexShaderFilePath, const char* framentShaderFilePath)
	{
		// Vertex and fragment shaders are successfully compiled.
		// Get a program object.
		_programID = glCreateProgram();

		// Create the vertex shader.
		_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		if (_vertexShaderID == 0)
		{
			utils::checkError("Vertex shader failed to be created.");
		}

		// Create the fragment shader.
		_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
		if (_fragmentShaderID == 0)
		{
			utils::checkError("Fragment shader failed to be created.");
		}

		// Compile the vertex shader.
		compileShader(vertexShaderFilePath, _vertexShaderID);
		// Compile the fragment shader.
		compileShader(framentShaderFilePath, _fragmentShaderID);


	}

	void GLSLProgram::linkShaders()
	{
		// Attach the shaders to our program.
		glAttachShader(_programID, _vertexShaderID);
		glAttachShader(_programID, _fragmentShaderID);

		// Link our program.
		glLinkProgram(_programID);

		// Error checking.
		GLint success = 0;
		glGetProgramiv(_programID, GL_LINK_STATUS, (int*)&success);
		if (success == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> errorLog(maxLength);
			glGetProgramInfoLog(_programID, maxLength, &maxLength, &errorLog[0]);

			glDeleteProgram(_programID); // Don't need the program anymore.
			glDeleteShader(_vertexShaderID); // Don't need the vertex shader anymore. Don't leak it.
			glDeleteShader(_fragmentShaderID); // Don't need the fragment shader anymore. Don't leak it.

			printf("%s\n", &(errorLog[0]));
			utils::checkError("Shaders failed to be linked.");
		}

		// Always detach shaders after a successful link.
		glDetachShader(_programID, _vertexShaderID);
		glDetachShader(_programID, _fragmentShaderID);
		glDeleteShader(_vertexShaderID);
		glDeleteShader(_fragmentShaderID);
	}

	void GLSLProgram::addAttribute(const char* attributeName)
	{
		glBindAttribLocation(_programID, _numAttributes++, attributeName);
	}

	GLuint GLSLProgram::getUniformLocation(const char* uniformName)
	{
		GLuint location = glGetUniformLocation(_programID, uniformName);

		if (location == GL_INVALID_INDEX)
		{
			utils::checkError("Uniform variable not found in shader.");
		}

		return location;
	}

	void GLSLProgram::use()
	{
		glUseProgram(_programID);
		
		// Enable each vertex attribute bound.
		for (int i = 0; i < _numAttributes; ++i)
		{
			glEnableVertexAttribArray(i);
		}
	}

	void GLSLProgram::unuse()
	{
		glUseProgram(0);

		// Disable each vertex attribute bound.
		for (int i = 0; i < _numAttributes; ++i)
		{
			glDisableVertexAttribArray(i);
		}
	}

	void GLSLProgram::compileShader(const char* filePath, const GLuint id)
	{
		// Load the code from the shader file.
		std::ifstream vertexFile(filePath);
		if (vertexFile.fail())
		{
			utils::checkError("Failed to open the vertex shader file path.");
		}

		// Put the content of the shader file into a string.
		std::string fileContents = "";
		std::string line;

		while (std::getline(vertexFile, line))
		{
			fileContents += line + "\n";
		}

		vertexFile.close();

		// Provide the actual text string representing the GLSL source code.
		const char* contentsPtr = fileContents.c_str();
		glShaderSource(id, 1, &contentsPtr, nullptr);

		// Now we compile the shader.
		glCompileShader(id);

		// Error checking for the shader.
		GLint success = 0;
		glGetShaderiv(id, GL_COMPILE_STATUS, &success);

		if (success == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character.
			std::vector<char> errorLog(maxLength);
			glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

			glDeleteShader(id); // Don't leak the shader.

			printf("%s\n", &(errorLog[0])); // Print the error log.
			utils::checkError("Shader failed to compile.");
		}
	}
}