#include "Player.h"



Player::Player() : GameObject()
{

}


Player::~Player()
{
}

void Player::Update(GLFWwindow * window)
{
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		x -= 1 * 0.001; // Gå til venstre
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		x += 1 * 0.001; // Gå til højre
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		y += 1 * 0.001;
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		y -= 1 * 0.001;
	}
}

void Player::Render()
{

}
