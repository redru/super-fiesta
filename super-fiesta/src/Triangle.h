#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>

#include "Engine.h"
#include "GameObject.h"
#include "Drawable.h"

using namespace glm;

class Triangle : public GameObject, public Drawable {
	
public:
	Triangle(Camera cam = Camera(), GLuint shad = -1) : Drawable(cam, shad) { }

	void draw() override;

private:
	const static float points[];
	const static float colours[];

};