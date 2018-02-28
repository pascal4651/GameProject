#include "GameWorld.h"

GameWorld::GameWorld(GLFWwindow * windowContext)
{
	window = windowContext;
	objects = new vector<GameObject>;
	tmpGO = new Player();

	glEnable(GL_TEXTURE_2D); //Aktivere tektur mapning
							 //Specificere hvorledes tekture interpoliseres over overflader
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	backGroundtexture = SOIL_load_OGL_texture(".\\background.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	glBindTexture(GL_TEXTURE_2D, backGroundtexture);

	//objects->push_back(tmpGO);
}

GameWorld::~GameWorld()
{
	delete tmpGO;
}

void GameWorld::GameLoop()
{
	GameLogic();
	Render();
	glfwPollEvents();
}

void GameWorld::GameLogic()
{
	tmpGO->Update(window);

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) //Tjekker op på at ESC er trykket ned, hvis ja luk vinduet
	{
		glfwSetWindowShouldClose(window, true);
	}
}

void GameWorld::DrawBackGround() {
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glBindTexture(GL_TEXTURE_2D, backGroundtexture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();
	glPopMatrix();
}

void GameWorld::DrawRectangle() {
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.4f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(-0.4f, -1.0f, 0.0f);
	glVertex3f(-0.4f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glColor3f(1,1,1);

	glEnd();
}

void GameWorld::Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity(); //Null stiller OpenGL matrise

	DrawBackGround();
	DrawRectangle();

	tmpGO->Render();

	glfwSwapBuffers(window);

}
