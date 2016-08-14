#include "Camera.h"

void Camera::generateMVP() {
	// Projection matrix : 45° Field of View, 4 : 3 ratio, display range : 0.1 unit <-> 100 units
	_projectionM = perspective(radians(45.0f), Engine::aRatio(), 0.1f, 100.0f);

	_viewM = lookAt(
		vec3(4, 3, 3), // Camera is at (4,3,3), in World Space
		vec3(0, 0, 0), // and looks at the origin
		vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
		);

	_mvp = _projectionM * _viewM * _modelM;
}