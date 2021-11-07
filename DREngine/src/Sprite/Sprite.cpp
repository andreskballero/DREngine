#include "Sprite.h"

namespace sprite
{
	Sprite::Sprite() : 
		_x{0},
		_y{0},
		_width{0},
		_height{0},
		_vboID{0}
	{

	}

	Sprite::~Sprite()
	{
		// Free the buffer to liberate the used VRAM for the VBO.
		if (_vboID != 0)
		{
			glDeleteBuffers(1, &_vboID);
		}
	}

	void Sprite::init(float x, float y, float width, float height)
	{
		// Assign arguments for later constructing vertex definitions.
		_x = x;
		_y = y;
		_width = width;
		_height = height;

		// Generate VBO.
		if (_vboID == 0)
		{
			glGenBuffers(1, &_vboID);
		}

		float vertexData[12]; // 6 vertices and 2 coordinates (z isn't used now).
		// Set the upper right vertex of the first triangle.
		vertexData[0] = x + width;
		vertexData[1] = y + height;
		// Set the upper left vertex of the first triangle.
		vertexData[2] = x;
		vertexData[3] = y + height;
		// Set the bottom left vertex of the first triangle.
		vertexData[4] = x;
		vertexData[5] = y;

		// Set the bottom left vertex of the second triangle.
		vertexData[6] = x;
		vertexData[7] = y;
		// Set the bottom right vertex of the second triangle.
		vertexData[8] = x + width;
		vertexData[9] = y;
		// Set the top right vertex of the second triangle.
		vertexData[10] = x + width;
		vertexData[11] = y + height;

		// Tell OpenGl we want this buffer to be active.
		glBindBuffer(GL_ARRAY_BUFFER, _vboID);
		// Upload the data.
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
		// Unbind the buffer.
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Sprite::draw()
	{
		// We can only have one VBO active at one time.
		glBindBuffer(GL_ARRAY_BUFFER, _vboID);
		// Tell OpenGL the attributes.
		glEnableVertexAttribArray(0); 

		// Do the drawing and tell OpenGL where the vertex data is in the _vboID.

		// Point OpenGL to the start of our data.
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0); // 2 is x/y coordinates.
		// Actually draw data.
		glDrawArrays(GL_TRIANGLES, 0, 6); // Not QUADS because GPUs work with triangles.

		// Disable attributes.
		glDisableVertexAttribArray(0);
		// Unbind the buffer.
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}