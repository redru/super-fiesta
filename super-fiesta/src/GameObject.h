#pragma once
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

class GameObject {

public:
	inline glm::mat4 transform() {
		_posM = glm::translate(glm::mat4(1.0), _position);
		_rotM = glm::rotate(glm::mat4(1.0), radians(_rotation[0]), glm::vec3(1.0f, 0.0f, 0.0f));
		_rotM = glm::rotate(_rotM, radians(_rotation[1]), glm::vec3(0.0f, 1.0f, 0.0f));
		_rotM = glm::rotate(_rotM, radians(_rotation[2]), glm::vec3(0.0f, 0.0f, 1.0f));
		_sizeM = glm::scale(glm::mat4(1.0), _size);
		
		return _posM * _rotM * _sizeM;
	}

	inline void move(glm::vec3 offset) {
		_position += offset;
	}

	inline void rotate(glm::vec3 offset) {
		_rotation += offset;
	}

	inline void scale(glm::vec3 offset) {
		_size += offset;
	}

	inline void position(glm::vec3 _position) { this->_position = _position; }
	inline glm::vec3 position() { return this->_position; }

	inline void rotation(glm::vec3 _rotation) { this->_rotation = _rotation; }
	inline glm::vec3 rotation() { return this->_rotation; }

	inline void size(glm::vec3 _size) { this->_size = _size; }
	inline glm::vec3 size() { return this->_size; }

private:
	glm::vec3 _position = glm::vec3(0.0f), _rotation = glm::vec3(0.0f), _size = glm::vec3(1.0f);
	glm::mat4 _posM, _rotM, _sizeM, transformM;

};