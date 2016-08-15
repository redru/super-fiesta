#pragma once
#include "ShaderUtils.h"
#include "BaseShaderProgram.h"

class DefaultShader : public BaseShaderProgram {

public:
	int DefaultShader::init() {
		_program = ShaderUtils::loadProgram("./shaders/default.vert", "./shaders/default.frag");
		uniformId("mvp", glGetUniformLocation(_program, "mvp"));
		uniformId("transform", glGetUniformLocation(_program, "transform"));

		return 0;
	}

};