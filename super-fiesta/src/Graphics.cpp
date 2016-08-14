#include "Graphics.h"

int Graphics::init() {
	_defaultShader.LoadShader();
	glUseProgram(_defaultShader.program());

	return 0;
}