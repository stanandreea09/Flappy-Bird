#include "Tema1.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>
#include "Transform2D.h"
#include "Object2D.h"

using namespace std;

Tema1::Tema1()
{
}

Tema1::~Tema1()
{
}



void Tema1::Init()
{
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);
	
	vecOY.push_back(100);
	vecOY.push_back(50);
	vecOY.push_back(70);
	vecOY.push_back(110);
	vecOY.push_back(130);

	vecOX.push_back(300);
	vecOX.push_back(580);
	vecOX.push_back(860);
	vecOX.push_back(1140);
	vecOX.push_back(1420);

	glm::vec3 corner = glm::vec3(0, 0, 0);
	float squareSide = 100;
	bool over = false; //true daca jocul s-a terminat
	int scor = 0;
	bool print = false;
	start = false; //jocul va incepe cand start == true
	space = false; 
	rad = 0; //unghiul de rotatie
	coordBird = 300; //coordonata pasarii pe axa OY;
	
	Mesh* birdd = Object2D::CreateBird("birdd", corner, squareSide, glm::vec3(0.6f, 0, 0.3f), true);
	AddMeshToList(birdd);

	Mesh* obstacle = Object2D::CreateObs("obstacle", corner, squareSide, glm::vec3(0.70, 0.52, 0.75), true);
	AddMeshToList(obstacle);
}

void Tema1::FrameStart()
{
	glClearColor(0.60, 0.80, 1.00, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glm::ivec2 resolution = window->GetResolution();
	glViewport(0, 0, resolution.x, resolution.y);
}


void Tema1::Update(float deltaTimeSeconds)
{
	//Bird
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(0, coordBird);
	modelMatrix *= Transform2D::Translate(50, 50);
	modelMatrix *= Transform2D::Rotate(rad);
	modelMatrix *= Transform2D::Translate(-50, -50);

	//daca pasarea ajunge la axa OX jocul se termina
	if (coordBird <= 0 ) { 
		over = true; 
		printScore(scor);
	}
	if (start == true) {
		if (over == false) {
			if (!space) {
				if (rad > (-0.785)) {
					coordBird -= deltaTimeSeconds * 100;
					rad -= deltaTimeSeconds * 0.5f;
				}
				else {
					coordBird -= deltaTimeSeconds * 100;
				}
			}

			if (space) {
				if (rad < 0.785) {
					coordBird += deltaTimeSeconds * 100;
					rad += deltaTimeSeconds * 0.5f;
				}
				else {
					coordBird += deltaTimeSeconds * 100;
				}
			}
		}
	}
	RenderMesh2D(meshes["birdd"], shaders["VertexColor"], modelMatrix);

	//creeam 5 obstacole inital in scena
	for (int i = 0; i < 5; i++) {

		//obstacolele de jos
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(vecOX[i], -200 - vecOY[i]);
		RenderMesh2D(meshes["obstacle"], shaders["VertexColor"], modelMatrix);

		//obstacolele de sus
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(vecOX[i] + 100, resolution.y + 200 - vecOY[i]);
		modelMatrix *= Transform2D::Rotate(3.14);
		RenderMesh2D(meshes["obstacle"], shaders["VertexColor"], modelMatrix);

		//un obiect iese din scena
		if (vecOX[i] < -100) {
			scor++;
			if (print == false) {
				printf("Scor: %d\n", scor);
			}
			vecOX[i] = resolution.x; 
			vecOY[i] = rand() % (170 - 20 + 1) + 20;
		}
		if (start == true) {
			if (over == false) {
				vecOX[i] -= deltaTimeSeconds * 100;
			}
		}
		
	}
	
}

void Tema1::printScore(int scor) {
	if (print == false) {
		printf("GAME OVER\n");
		printf("YOUR SCORE: %d\n", scor);
		print = true;
	}
	
}

void Tema1::FrameEnd()
{
}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{
	if (window->KeyHold(GLFW_KEY_SPACE)) {
		if (over == false) {
			coordBird += deltaTime * 100;
			rad += deltaTime * 0.5f;
		}
	}
}

void Tema1::OnKeyPress(int key, int mods)
{
	if (key == GLFW_KEY_SPACE) {
		space = true;
		start = true;
	}
}

void Tema1::OnKeyRelease(int key, int mods)
{
	if (key == GLFW_KEY_SPACE) {
		space = false;
	}
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema1::OnWindowResize(int width, int height)
{
}


