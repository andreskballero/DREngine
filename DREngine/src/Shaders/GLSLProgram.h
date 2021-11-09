#ifndef H_GLSLPROGRAM
#define H_GLSLPROGRAM

#include <GL/glew.h>

/**
* Namespace for the shaders.
*/
namespace glsl
{
	/**
	* Class to control the shaders.
	*/
	class GLSLProgram
	{
	public:
		/**
		* Constructor().
		*/
		GLSLProgram();

		/**
		* Destructor().
		*/
		~GLSLProgram();

		/**
		* Function that reads from file and compiles to a format that the GPU can use.
		*/
		void compileShaders(const char* vertexShaderFilePath, const char* framentShaderFilePath);

		/**
		* Function that links shaders into the final program.
		*/
		void linkShaders();

		/**
		* Function to bind attributes to the shader.
		* @note Should be called between compiling and linking the shader.
		*/
		void addAttribute(const char* attributeName);

		/**
		* Function .
		*/
		GLuint getUniformLocation(const char* uniformName);

		/**
		* Function to use the program.
		*/
		void use();

		/**
		* Function to unbind the program.
		*/
		void unuse();
	private:
		/**
		* Function to compile the passed shader.
		*/
		void compileShader(const char* filePath, const GLuint id);

		int _numAttributes;				// Number of attributes we have.

		GLuint _programID;				// Id that holds onto the shader program.

		GLuint _vertexShaderID;			// Vertex shader Id.
		GLuint _fragmentShaderID;		// Fragment shader Id.
	};
}

#endif
