#include "GameObject.h"

GameObject::GameObject() : GameObject(0, 0, 0)
{
}

GameObject::GameObject(float initX, float initY, float initZ)
{
	x = initX;
	y = initY;
	z = initZ;
	directionX = 1;
	directionY = 1;
	texture = SOIL_load_OGL_texture(".\\PokeBall.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	glBindTexture(GL_TEXTURE_2D, texture);
}

GameObject::~GameObject()
{
}

void GameObject::Update(GLFWwindow * window)
{

	//x += directionX * 0.001;
}

void GameObject::Render()
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 1.0f);
	glEnd();
	glPopMatrix();
}