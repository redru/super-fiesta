#pragma once
#include <glm\glm.hpp>

class GameObject {

public:
	inline void position(glm::vec3 _position) { this->_position = _position; }
	inline glm::vec3 position() { return this->_position; }

	inline void rotation(glm::vec3 _rotation) { this->_rotation = _rotation; }
	inline glm::vec3 rotation() { return this->_rotation; }

	inline void size(glm::vec3 _size) { this->_size = _size; }
	inline glm::vec3 size() { return this->_size; }

private:
	glm::vec3 _position;
	glm::vec3 _rotation;
	glm::vec3 _size;

};