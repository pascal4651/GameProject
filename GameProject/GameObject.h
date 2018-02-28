#pragma once
#include <GLFW\glfw3.h>
#include <SOIL.h>

class GameObject
{
protected:
	GLuint texture;
	float x;
	float y;
	float z;
public:
	GameObject();
	GameObject(float initX, float initY, float initZ);
	~GameObject();
	void virtual Update(GLFWwindow*);
	void virtual Render();
	int directionX;
	int directionY;
};

