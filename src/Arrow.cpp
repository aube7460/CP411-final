#include "Arrow.hpp"

const float X_ARROW_INCREMENT = 0.005;
const float Y_ARROW_INCREMENT = 0.004;
const float MAXIMUM_ARROW_PULL = -1.30; // compared to control points of the bowstring
const float X_MAX_STRING_ROTATE_DOWN = -6.2;
const float X_MAX_STRING_ROTATE_UP = 11.2;
const float Y_MAX_STRING_ROTATE = 39;


Target arrowTarget;

Arrow::Arrow() {
	// initial points for the arrow
	arrowCoordinates[0][0] = -0.5;	arrowCoordinates[0][1] = -1.65; arrowCoordinates[0][2] = 0.32;
	arrowCoordinates[1][0] = -0.15;	arrowCoordinates[1][1] = -0.3; arrowCoordinates[1][2] = 0.22;

	fired = false; 
	rotate = 0;
	xrotation = 0;
	yrotation = 0;
}

void Arrow::draw() {

	if (rotate == 1) {
		yrotation -= 0.35;
		glRotatef(yrotation, 0.0, 0.5, 0.0f); // Rotate our object around the y axis
	}
	else if (rotate == 2) {
		yrotation += 0.35;
		glRotatef(yrotation, 0.0, 0.5, 0.0f); // Rotate our object around the y axis
	}
	else if (rotate == 3) {
		xrotation -= 0.35;

		glRotatef(xrotation, 0.5, 0.0, 0.0f); // Rotate our object around the x axis
	}
	else if (rotate == 4) {
		xrotation += 0.35;
		glRotatef(xrotation, 0.5, 0.0, 0.0f); // Rotate our object around the x axis
	}

	glColor3f(0,0,0);
	glLineWidth((GLfloat)2);
	glBegin(GL_LINE_STRIP);
		glVertex3f(arrowCoordinates[0][0], arrowCoordinates[0][1], arrowCoordinates[0][2]);
		glVertex3f(arrowCoordinates[1][0], arrowCoordinates[1][1], arrowCoordinates[1][2]);
	glEnd();

	glColor4f(1.f, 1.f, 1.f, 1.f);
}

void Arrow::translate(GLfloat tx, GLfloat ty, GLfloat tz){ //w.r.p.t WC
	arrowCoordinates[0][0] += tx;
	arrowCoordinates[1][0] += tx;

	arrowCoordinates[0][1] += ty;
	arrowCoordinates[1][1] += ty;

	arrowCoordinates[0][2] += tz;
	arrowCoordinates[1][2] += tz;
}


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
		fired = true;
	}
}

// resets arrow coordinates to default values
void Arrow::reset() {
	arrowCoordinates[0][0] = -0.5;	arrowCoordinates[0][1] = -1.65; arrowCoordinates[0][2] = 0.32;
		arrowCoordinates[1][0] = -0.15;	arrowCoordinates[1][1] = -0.3; arrowCoordinates[1][2] = 0.22;
}
