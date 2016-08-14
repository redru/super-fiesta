#include "Engine.h"

using namespace std;

float Engine::_aspectRatio = (float)1400 / (float)800;
Graphics Engine::_graphics;
Camera Engine::_camera;
GLFWwindow* Engine::_context = NULL;
int Engine::_state = Engine::ENGINE_STATE_NOT_STARTED;

int Engine::init() {
	cout << "[engine] init" << endl;
	Engine::_graphics.init();
	Engine::_camera.ratio(_aspectRatio);

	Engine::_state = Engine::ENGINE_STATE_INITIALIZED;
	return Engine::_state;
}

int Engine::start() {
	cout << "[engine] start" << endl;
	Engine::_camera.generateMVP();
	
	Triangle triangle(Engine::_camera, Engine::graphics().defaultShader().program());

	glClearColor(0.0, 0.0, 0.0, 1.0);

	/* Loop until the user closes the context */
	while (!glfwWindowShouldClose(Engine::_context)) {
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		triangle.draw();

		/* Swap front and back buffers */
		glfwSwapBuffers(_context);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}

const int Engine::ENGINE_STATE_ERROR = 0x000000;
const int Engine::ENGINE_STATE_NOT_STARTED = 0x000001;
const int Engine::ENGINE_STATE_INITIALIZED = 0x000002;
const int Engine::ENGINE_STATE_STARTED = 0x000003;

const int Engine::MODULE_STATE_ERROR = 0x000000;
const int Engine::MODULE_STATE_NOT_STARTED = 0x000001;
const int Engine::MODULE_STATE_STARTED = 0x000002;