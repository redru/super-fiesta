#include "DefaultShader.h"

int DefaultShader::init() {
	loadProgram("./shaders/default.vert", "./shaders/default.frag");
	_uMvp = glGetUniformLocation(_program, "mvp");

	return 0;
}