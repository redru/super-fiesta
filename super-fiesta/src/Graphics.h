#pragma once
#include <GL\glew.h>

#include "DefaultShader.h"

class Graphics {

public:
	int init();

	inline DefaultShader& defaultShader() { return _defaultShader; }

private:
	DefaultShader _defaultShader;

};