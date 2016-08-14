#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

class DefaultShader {

public:
	GLuint LoadShader();

	inline GLuint program() { return _program; }
	inline GLuint uMvp() { return _uMvp; }

private:
	GLuint _program;
	GLuint _uMvp;

};