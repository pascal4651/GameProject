#pragma once

#include <GLFW\glfw3.h>
#include "GameObject.h"
#include "Player.h"
#include <vector>
#include <iostream>
using namespace std;

class GameWorld
{
private:
	GLFWwindow * window;
	GameObject* tmpGO;
	GLuint backGroundtexture;
	vector<GameObject>* objects;
	void GameLogic();
	void Render();
	void DrawBackGround();
	void DrawRectangle();

public:
	GameWorld(GLFWwindow *);
	~GameWorld();
	void GameLoop();
};

