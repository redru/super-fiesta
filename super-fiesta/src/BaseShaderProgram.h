#pragma once
#include <iostream>
#include <string>
#include <map>

#include <GL\glew.h>

class BaseShaderProgram {

public:
	inline GLuint program() { return _program; }

	inline GLuint uniformId(std::string uniformName) {
		return uniforms.at(uniformName);
	}

protected:
	GLuint _program;
	std::map<std::string, GLuint> uniforms;

	inline void uniformId(std::string uniformName, GLuint uniformValue) {
		uniforms.insert(std::pair<std::string, GLuint>(uniformName, uniformValue));
	}

};