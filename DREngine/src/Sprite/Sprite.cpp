#include "Sprite.h"
#include "../Shaders/Vertex.h"

#include <cstddef>

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

		Vertex vertexData[6]; // 6 vertices.
		// Set the upper right vertex of the first triangle.
		vertexData[0].position.x = x + width;
		vertexData[0].position.y = y + height;
		// Set the upper left vertex of the first triangle.
		vertexData[1].position.x = x;
		vertexData[1].position.y = y + height;
		// Set the bottom left vertex of the first triangle.
		vertexData[2].position.x = x;
		vertexData[2].position.y = y;

		// Set the bottom left vertex of the second triangle.
		vertexData[3].position.x = x;
		vertexData[3].position.y = y;
		// Set the bottom right vertex of the second triangle.
		vertexData[4].position.x = x + width;
		vertexData[4].position.y = y;
		// Set the top right vertex of the second triangle.
		vertexData[5].position.x = x + width;
		vertexData[5].position.y = y + height;

		// Set the color.
		for (int i = 0; i < 6; ++i)
		{
			vertexData[i].color.r = 255;
			vertexData[i].color.g = 0;
			vertexData[i].color.b = 255;
		}

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
		// This is the position attribute pointer.
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
		// Now the color attribute pointer.
		glVertexAttribPointer(1, 3, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));

		// Actually draw data.
		glDrawArrays(GL_TRIANGLES, 0, 6); // Not QUADS because GPUs work with triangles.

		// Disable attributes.
		glDisableVertexAttribArray(0);
		// Unbind the buffer.
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}