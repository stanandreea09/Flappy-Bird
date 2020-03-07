#include "Object2D.h"

#include <Core/Engine.h>

Mesh* Object2D::CreateBird(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(length, 0, 0), color),
		VertexFormat(corner + glm::vec3(length, length, 0), color),
		VertexFormat(corner + glm::vec3(0, length, 0), color),
		VertexFormat(corner + glm::vec3((3*length)/2, (3 * length) / 2, 0), color),
		VertexFormat(corner+ glm::vec3((3 * length) / 2, length / 2, 0), color),
		VertexFormat(corner + glm::vec3((3 * length) / 2, (7 * length) / 8, 0), glm::vec3(1.00,0.67,0.00)),
		VertexFormat(corner + glm::vec3((3 * length) / 2, (9*length) / 8, 0), glm::vec3(1.00,0.67,0.00)),
		VertexFormat(corner + glm::vec3((4 * length) / 2, length, 0), glm::vec3(1.00,0.67,0.00)),
		
		VertexFormat(corner + glm::vec3((3 * length) / 2 - 30, length, 0), glm::vec3(0.0,0.8,0.80)),
		VertexFormat(corner + glm::vec3(((3 * length) / 2) - 10, length, 0), glm::vec3(0.0, 0.8, 0.80)),
		VertexFormat(corner + glm::vec3(((3 * length) / 2) - 15, (6 * length) / 5, 0), glm::vec3(0.0, 0.8, 0.80)),


	};

	Mesh* square = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2,
											2, 3, 0,
											9, 10, 11,
											2, 5, 4,
											8, 7, 6,
											};
	
	if (!fill) {
		square->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		indices.push_back(0);
		indices.push_back(2);
	
	}

	square->InitFromData(vertices, indices);
	return square;
}

Mesh* Object2D::CreateObs(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill) {
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(length, 0, 0), color),
		VertexFormat(corner + glm::vec3(length, 4 *length, 0), color),
		VertexFormat(corner + glm::vec3(0, 4*length, 0), color),
		
		VertexFormat(corner+glm::vec3(-5, 4*length, 0 ), glm::vec3(0.9, 0.0, 0.27)),
		VertexFormat(corner + glm::vec3(-5, 4 * length +15, 0),  glm::vec3(0.9, 0.0, 0.27)),
		VertexFormat(corner + glm::vec3(length+5, 4 * length, 0),  glm::vec3(0.9, 0.0, 0.27)),
		VertexFormat(corner + glm::vec3(length + 5, 4 * length+15, 0),  glm::vec3(0.9, 0.0, 0.27)),
	};

	Mesh* obs = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2,
											2, 3, 0,
											4, 5, 6,
											4, 6, 7};

	if (!fill) {
		obs->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		indices.push_back(0);
		indices.push_back(2);
	}

	obs->InitFromData(vertices, indices);
	return obs;
}


Mesh* Object2D::CreateTriangle(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner + glm::vec3((3 * length) / 2 -30, length, 0), glm::vec3(0.41,0.63,1.00)),
		VertexFormat(corner + glm::vec3(((3 * length) / 2)-10, length, 0), glm::vec3(0.41, 0.63, 1.00)),
		VertexFormat(corner + glm::vec3(((3 * length) / 2)-15, (6 * length) / 5, 0), glm::vec3(0.41, 0.63, 1.00)),
	};

	Mesh* triangle = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2};

	if (!fill) {
		triangle->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		indices.push_back(0);
	}

	triangle->InitFromData(vertices, indices);
	return triangle;
}
