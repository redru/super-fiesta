#include "Camera.h"

void Camera::generateMVP() {
	if (_somethingChanged) {
		// Projection matrix : 45° Field of View, 4 : 3 ratio, display range : 0.1 unit <-> 100 units
		_projectionM = glm::perspective(glm::radians(45.0f), _ratio, 0.1f, 100.0f);

		_viewM = glm::lookAt(
			_position,
			_lookingAt,
			_upside // glm::vec3(0.0f, 1.0f, 0.0f) Head is up (set to 0,-1,0 to look upside-down)
		);

		_mvp = _projectionM * _viewM * _modelM;
		_somethingChanged = false;
	}
}