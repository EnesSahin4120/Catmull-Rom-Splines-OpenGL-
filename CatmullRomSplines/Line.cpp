#include "Line.h"



Line::Line()
{
	VAO = 0;
	VBO = 0;
}

void Line::CreateLine(GLfloat *vertices, unsigned numofVertices)
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * numofVertices, vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Line::RenderLine()
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_LINES, 0, 2);
}

void Line::ClearLine()
{
	if (VBO != 0)
	{
		glDeleteBuffers(1, &VBO);
		VBO = 0;
	}
	if (VAO != 0)
	{
		glDeleteBuffers(1, &VAO);
		VAO = 0;
	}
}


Line::~Line()
{
	ClearLine();
}
