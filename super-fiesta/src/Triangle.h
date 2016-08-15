#pragma once
#include "Engine.h"
#include "GameObject.h"
#include "Drawable.h"

using namespace glm;

class Triangle : public GameObject, public Drawable {
	
public:
	Triangle(Camera& cam = Camera(), GLuint shad = -1);

	void draw() override;

private:
	GLuint vao = 0;

	const static float points[];
	const static float colours[];

};