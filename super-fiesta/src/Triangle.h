#pragma once
#include <GL\glew.h>
#include <glm\glm.hpp>

#include "GameObject.h"
#include "Drawable.h"
#include "Camera.h"

using namespace glm;

class Triangle : public GameObject, public Drawable {
	
public:
	Triangle();

	// Virtual overridden
	void draw() override;

	mat4 mvp;

private:
	const static float points[];
	const static float colours[];

};