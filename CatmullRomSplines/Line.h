#pragma once

#include <GL\glew.h>

class Line
{
public:
	Line();

	void CreateLine(GLfloat *vertices, unsigned numofVertices);
	void RenderLine();
	void ClearLine();

	~Line();

private:
	GLuint VAO, VBO;
};

