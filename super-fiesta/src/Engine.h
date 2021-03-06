#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "Camera.h"
#include "Graphics.h"
#include "Triangle.h"

class Engine {

public:
	static int init();
	static int start();
	static void keyCallback(int key, int scancode, int action, int mods);
	static void mouseCallback(int button, int action, int mods);
	static void scrollCallback(double xoffset,double yoffset);

	static inline void context(GLFWwindow& _context) { Engine::_context = &_context; }
	static inline GLFWwindow& context() { return *Engine::_context; }

	static inline Graphics& graphics() { return Engine::_graphics; }

	static inline void aRatio(float aspectRatio) { 
		Engine::_aspectRatio = aspectRatio;
		Engine::_camera.ratio(aspectRatio);
	}

	static inline float aRatio() { return Engine::_aspectRatio; }

	static const int FPS;
	static const long SLEEP_TIME;

	static const int ENGINE_STATE_ERROR;
	static const int ENGINE_STATE_NOT_STARTED;
	static const int ENGINE_STATE_INITIALIZED;
	static const int ENGINE_STATE_STARTED;

	static const int MODULE_STATE_ERROR;
	static const int MODULE_STATE_NOT_STARTED;
	static const int MODULE_STATE_STARTED;

private:
	static GLFWwindow* _context;

	static int _state;
	static float _aspectRatio;

	static double beginTime;
	static double endTime;
	static long elapsedTime;

	static Graphics _graphics;
	static Camera _camera;

};