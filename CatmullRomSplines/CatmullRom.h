#pragma once

#include <stdio.h>
#include <vector>

#include <GL\glew.h>
#include <glm\glm.hpp>

#include "Line.h"

class CatmullRom
{
public:
	CatmullRom(GLint segmentFrameCount, GLfloat points[4][3]);
	~CatmullRom();

	void UdateCurve(std::vector<Line*> &lines);
	glm::vec3 PositionOnCurve(glm::vec3 p0, glm::vec3 m0, glm::vec3 p1, glm::vec3 m1, GLfloat t);

private:
	GLint segmentFrameCount;
	GLfloat points[4][3];
};

