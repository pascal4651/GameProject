#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
public:
	Player();
	~Player();
	void Update(GLFWwindow*);
	void Render();
};

