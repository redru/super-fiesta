#pragma once
#include <iostream>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "Graphics.h"
#include "Triangle.h"
#include "Camera.h"

class Engine {

public:
	static int init();
	static int start();

	static inline void context(GLFWwindow& _context) { Engine::_context = &_context; }
	static inline GLFWwindow& context() { return *Engine::_context; }

	static inline Graphics& graphics() { return Engine::_graphics; }

	static inline void aRatio(float aspectRatio) { Engine::_aspectRatio = aspectRatio; }
	static inline float aRatio() { return Engine::_aspectRatio; }

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

	static Graphics _graphics;

};