#pragma once
#include <iostream>

#include "Camera.h"

class Drawable {

public:
	Drawable(Camera cam, GLuint shad) : _camera(cam), _shader(shad) { }
	~Drawable() { std::cout << "Destructor of Drawable" << std::endl; }

	virtual void draw() = 0;

	inline void camera(Camera& cam) { _camera = cam; }
	inline Camera& camera() { return _camera; }
	inline void shader(GLuint shad) { _shader = shad; }
	inline GLuint shader() { return _shader; }

protected:
	Camera _camera;
	GLuint _shader;

};