#pragma once
#include <iostream>
#include <string>

#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

class Camera {

public:
	void generateMVP();

	inline void move(const glm::vec3& offset) {
		_position += offset;
		_somethingChanged = true;
	}

	inline glm::mat4 mvp() { return _mvp; }

	inline void ratio(float rat) { 
		_ratio = rat;
		_somethingChanged = true;
	}

	inline float ratio() { return _ratio; }

	inline void position(const glm::vec3& newPos) {
		_position = newPos;
		_somethingChanged = true;
	}

	inline glm::vec3 position() { return _position; }

	inline void look(const glm::vec3& newLook) {
		_lookingAt = newLook;
		_somethingChanged = true;
	}

	inline glm::vec3 lookingAt() { return _lookingAt; }

	inline void invert() {
		_upside = glm::vec3(0.0f, -_upside[1], 0.0f);
		_somethingChanged = true;
	}

private:
	float _ratio;
	bool _somethingChanged = true;

	glm::vec3 _position = glm::vec3(0.0f), _lookingAt = glm::vec3(0.0f), _upside = glm::vec3(0.0f, 1.0f, 0.0f);

	glm::mat4 _modelM = glm::mat4(1.0f), _viewM, _projectionM, _mvp;

};