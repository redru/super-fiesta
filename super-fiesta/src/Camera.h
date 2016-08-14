#pragma once
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

using namespace glm;

class Camera {

public:
	void generateMVP();

	inline mat4 mvp() { return _mvp; }
	inline void ratio(float rat) { _ratio = rat; }
	inline float ratio() { return _ratio; }

private:
	float _ratio;

	mat4 _modelM = mat4(1.0), _viewM, _projectionM, _mvp;
	vec4 position = vec4(0.0), rotation = vec4(0.0), scalation = vec4(1.0);

};