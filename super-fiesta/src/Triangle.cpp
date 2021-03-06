#include "Triangle.h"

const float Triangle::points[] = {
	 0.0f,  0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f
};

const float Triangle::colours[] = {
	1.0f, 0.0f,  0.0f,
	0.0f, 1.0f,  0.0f,
	0.0f, 0.0f,  1.0f
};

Triangle::Triangle(Camera& cam, GLuint shad) : Drawable(cam, shad) {
	GLuint points_vbo = 0;
	glGenBuffers(1, &points_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);

	GLuint colours_vbo = 0;
	glGenBuffers(1, &colours_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, colours_vbo);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), colours, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, colours_vbo);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

void Triangle::draw() {
	glBindVertexArray(vao);

	glUniformMatrix4fv(Engine::graphics().defaultShader().uniformId("mvp"), 1, GL_FALSE, &_camera.mvp()[0][0]);
	glUniformMatrix4fv(Engine::graphics().defaultShader().uniformId("transform"), 1, GL_FALSE, &transform()[0][0]);

	glUseProgram(_shader);

	// draw points 0-3 from the currently bound VAO with current in-use shader
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glBindVertexArray(0);
}