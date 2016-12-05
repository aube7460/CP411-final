#include "Arrow.hpp"

const float X_ARROW_INCREMENT = 0.005;
const float Y_ARROW_INCREMENT = 0.004;
const float MAXIMUM_ARROW_PULL = -1.30; // compared to control points of the bowstring

Arrow::Arrow() {
	// initial points for the arrow
	arrowCoordinates[0][0] = -0.63;	arrowCoordinates[0][1] = -1.35; arrowCoordinates[0][2] = 1;
	arrowCoordinates[1][0] = -0.3;	arrowCoordinates[1][1] = -0.5; arrowCoordinates[1][2] = 0.1;
}

void Arrow::draw() {
	glColor3f(0,0,0);
	glLineWidth((GLfloat)2);
	glBegin(GL_LINE_STRIP);
		glVertex3f(arrowCoordinates[0][0], arrowCoordinates[0][1], arrowCoordinates[0][2]);
		glVertex3f(arrowCoordinates[1][0], arrowCoordinates[1][1], arrowCoordinates[1][2]);
	glEnd();


	glColor4f(1.f, 1.f, 1.f, 1.f);
}

// TO BE IMPLEMENTED
// modify fireArrow() to accept:
// 		a 2D array - to hold the direction vector of the arrow
//		float - to determine the power of the arrow
void Arrow::fireArrow(bool toggle) {
	if (toggle) {
		if(arrowCoordinates[0][0] > MAXIMUM_ARROW_PULL) {
			arrowCoordinates[0][0] -= X_ARROW_INCREMENT;
			arrowCoordinates[1][0] -= X_ARROW_INCREMENT;

			arrowCoordinates[0][1] -= Y_ARROW_INCREMENT;
			arrowCoordinates[1][1] -= Y_ARROW_INCREMENT;
		}
	}
	else {
		// TO BE IMPLEMENTED
		// use direction vector and power to determine where the arrow ends

		// resets the arrow position to default values
		arrowCoordinates[0][0] = -0.63;	arrowCoordinates[0][1] = -1.35; arrowCoordinates[0][2] = 1;
		arrowCoordinates[1][0] = -0.3;	arrowCoordinates[1][1] = -0.5; arrowCoordinates[1][2] = 0.1;
	}
}
