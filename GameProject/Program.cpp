#include <GLFW\glfw3.h>
#include "GameWorld.h"
#include <iostream>

GameWorld * gw;

void size_resize_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main() {
	glfwInit(); //Initialisering af glfw
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2); //S�tte �vre OpenGl version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0); //S�tte nedre OpenGl Version
	
	GLFWwindow* window = glfwCreateWindow(1200, 600, "GAME", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Kunne ikke oprette OpenGL Vindue" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); //S�rger for at OpenGL Bruger vinduet som renderings context
	
	glViewport(0, 0, 1200, 600); //Oprettet en viewport gennem OpenGL kald

	glfwSetFramebufferSizeCallback(window, size_resize_callback); //Sikre at hvis vinduets st�rrelse �ndres �ndres viewport ogs�

	gw = new GameWorld(window);

	while (!glfwWindowShouldClose(window)) // K�re s� l�nge glfw vinduet ikke har f�et besked p� at lukke (f.eks. tryk p� X knappen)
	{
		gw->GameLoop();
	}
	glfwTerminate(); //Lukker evt. �bnede vinduer og frigiver resurse brugt her til
	return 0;
}