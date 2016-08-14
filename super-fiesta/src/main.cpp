#include <iostream>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "Engine.h"
#include "Graphics.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main() {
	std::cout << "starting..." << std::endl;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	GLFWwindow* window = glfwCreateWindow(1400, 800, "ProjectRed", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}

	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	Engine::context(*window);
	Engine::init();
	Engine::start();

	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);

	Engine::aRatio(height > 0 ? (float) width / (float) height : 0.0);
}