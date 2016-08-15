#include "Engine.h"

using namespace std;

const int Engine::FPS = 30;
const long Engine::SLEEP_TIME = 1000 / Engine::FPS;

double Engine::beginTime = 0;
double Engine::endTime = 0;
long Engine::elapsedTime = 0;

float Engine::_aspectRatio = (float) 1400 / (float) 800;
Graphics Engine::_graphics;
Camera Engine::_camera;
GLFWwindow* Engine::_context = NULL;
int Engine::_state = Engine::ENGINE_STATE_NOT_STARTED;

int Engine::init() {
	cout << "[engine] init" << endl;
	Engine::_graphics.initShaders();

	Engine::_camera.ratio(_aspectRatio);
	Engine::_camera.position(glm::vec3(4.0f, 3.0f, 15.0f));
	Engine::_camera.look(glm::vec3(0.0f, 0.0f, 0.0f));
	Engine::_camera.generateMVP();

	Engine::_state = Engine::ENGINE_STATE_INITIALIZED;
	return Engine::_state;
}

int Engine::start() {
	cout << "[engine] start" << endl;
	
	Triangle triangle(Engine::_camera, Engine::graphics().defaultShader().program());

	glClearColor(0.0, 0.0, 0.0, 1.0);

	/* Loop until the user closes the context */
	while (!glfwWindowShouldClose(Engine::_context)) {
		Engine::beginTime = glfwGetTime();

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::vec3 tmpMoveVector = glm::vec3(0.0f, 0.0f, 0.08f);
		// triangle.move(tmpMoveVector);

		// Engine::_camera.look(triangle.position());
		Engine::_camera.generateMVP();

		triangle.draw();

		/* Swap front and back buffers */
		glfwSwapBuffers(_context);

		/* Poll for and process events */
		glfwPollEvents();

		Engine::endTime = glfwGetTime();
		Engine::elapsedTime = (long) (Engine::endTime - Engine::beginTime);

		if (elapsedTime < Engine::SLEEP_TIME)
			std::this_thread::sleep_for(std::chrono::milliseconds(Engine::SLEEP_TIME - elapsedTime));
	}

	glfwTerminate();

	return 0;
}

void Engine::keyCallback(int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS || action == GLFW_REPEAT) {
		if (key == GLFW_KEY_W) {
			Engine::_camera.move(glm::vec3(0.0f, 0.0f, -0.5f));
			Engine::_camera.moveLook(glm::vec3(0.0f, 0.0f, -0.5f));
		} else if (key == GLFW_KEY_A) {
			Engine::_camera.move(glm::vec3(-0.5f, 0.0f, 0.0f));
			Engine::_camera.moveLook(glm::vec3(-0.5f, 0.0f, 0.0f));
		} else if(key == GLFW_KEY_S) {
			Engine::_camera.move(glm::vec3(0.0f, 0.0f, 0.5f));
			Engine::_camera.moveLook(glm::vec3(0.0f, 0.0f, 0.5f));
		} else if(key == GLFW_KEY_D) {
			Engine::_camera.move(glm::vec3(0.5f, 0.0f, 0.0f));
			Engine::_camera.moveLook(glm::vec3(0.5f, 0.0f, 0.0f));
		}
	}	
}

void Engine::mouseCallback(int button, int action, int mods) {
	
}

void Engine::scrollCallback(double xoffset, double yoffset) {
	if (yoffset > 0) {
		Engine::_camera.move(glm::vec3(0.0f, 0.5f, 0.0f));
		Engine::_camera.moveLook(glm::vec3(0.0f, 0.5f, 0.0f));
	} else {
		Engine::_camera.move(glm::vec3(0.0f, -0.5f, 0.0f));
		Engine::_camera.moveLook(glm::vec3(0.0f, -0.5f, 0.0f));
	}
}

const int Engine::ENGINE_STATE_ERROR = 0x000000;
const int Engine::ENGINE_STATE_NOT_STARTED = 0x000001;
const int Engine::ENGINE_STATE_INITIALIZED = 0x000002;
const int Engine::ENGINE_STATE_STARTED = 0x000003;

const int Engine::MODULE_STATE_ERROR = 0x000000;
const int Engine::MODULE_STATE_NOT_STARTED = 0x000001;
const int Engine::MODULE_STATE_STARTED = 0x000002;