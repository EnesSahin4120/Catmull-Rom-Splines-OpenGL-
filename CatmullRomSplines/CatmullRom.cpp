#include "CatmullRom.h"



CatmullRom::CatmullRom(GLint segmentFrameCount, GLfloat targetPoints[4][3])
{
	this->segmentFrameCount = segmentFrameCount;
    std::copy(&targetPoints[0][0], &targetPoints[0][0] + 4 * 3, &points[0][0]);
}

void CatmullRom::UdateCurve(std::vector<Line*> &lines) 
{
	glm::vec3 p0;
	glm::vec3 m0;
	glm::vec3 p1;
	glm::vec3 m1;

	lines.clear();
	for (int i = 0; i < 3; i++)
	{
		p0 = glm::vec3(points[i][0], points[i][1], points[i][2]);
		p1 = glm::vec3(points[i + 1][0], points[i + 1][1], points[i + 1][2]);

		if (i > 0)
			m0 = 0.5f * (glm::vec3(points[i + 1][0], points[i + 1][1], points[i + 1][2]) - glm::vec3(points[i - 1][0], points[i - 1][1], points[i - 1][2]));
		else
			m0 = glm::vec3(points[i + 1][0], points[i + 1][1], points[i + 1][2]) - glm::vec3(points[i][0], points[i][1], points[i][2]);

		if (i < 2)
			m1 = 0.5f * (glm::vec3(points[i + 2][0], points[i + 2][1], points[i + 2][2]) - glm::vec3(points[i][0], points[i][1], points[i][2]));
		else
			m1 = glm::vec3(points[i + 1][0], points[i + 1][1], points[i + 1][2]) - glm::vec3(points[i][0], points[i][1], points[i][2]);

		glm::vec3 curvePos;
		glm::vec3 curvePos2;
		GLfloat t;
		GLfloat t2;
		GLfloat uStep = 1.0f / segmentFrameCount;

		if (i == 2)
			uStep = 1.0f / (segmentFrameCount - 1.0f);

		for (int j = 0; j < segmentFrameCount; j++)
		{
			t = j * uStep;
			t2 = (j + 1) * uStep;
			curvePos = glm::vec3(PositionOnCurve(p0, m0, p1, m1, t));
			curvePos2 = glm::vec3(PositionOnCurve(p0, m0, p1, m1, t2));

			Line *currentline = new Line();
			GLfloat vertices[] =
			{
				curvePos.x, curvePos.y, curvePos.z,
				curvePos2.x, curvePos2.y, curvePos2.z
			};
			currentline->CreateLine(vertices, 6);
			lines.push_back(currentline);
		}
	}
}

glm::vec3 CatmullRom::PositionOnCurve(glm::vec3 p0, glm::vec3 m0, glm::vec3 p1, glm::vec3 m1, GLfloat t) 
{
	glm::vec3 position = glm::vec3((2.0f * t * t * t - 3.0f * t * t + 1.0f) * p0
		+ (t * t * t - 2.0f * t * t + t) * m0
		+ (-2.0f * t * t * t + 3.0f * t * t) * p1
		+ (t * t * t - t * t) * m1);
	return position;
}


CatmullRom::~CatmullRom()
{
}
