#pragma once
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

#include "Engine.h"

using namespace glm;

class Camera {

public:
	void generateMVP();

	inline mat4 mvp() { return _mvp; }

private:
	mat4 _modelM = mat4(1.0), _viewM, _projectionM, _mvp;
	vec4 position = vec4(0.0), rotation = vec4(0.0), scalation = vec4(1.0);

};