#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "ShaderProgram.h"

class DefaultShader : public ShaderProgram {

public:
	int init();

	inline GLuint uMvp() { return _uMvp; }

private:
	GLuint _uMvp;

};