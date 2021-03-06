#include "Bow.hpp"

const float X_BOW_ANCHOR_INCREMENT = 0.004;
const float Y_BOW_ANCHOR_INCREMENT = 0.004;
const float X_STRING_ANCHOR_INCREMENT = 0.004;
const float Y_STRING_ANCHOR_INCREMENT = 0.004;
const float X_STRING_CONTROL_INCREMENT = 0.0072;
const float Y_STRING_CONTROL_INCREMENT = 0.0072;
const float MAXIMUM_BOW_PULL = -1.475995; // compared to control points of the bowstring

Bow::Bow(){
	// initial control points for the bow
	bowCtrlPoints[0][0] = -0.5; bowCtrlPoints[0][1] = 1.0; bowCtrlPoints[0][2] = 2;
	bowCtrlPoints[1][0] = -0.2; bowCtrlPoints[1][1] = -0.8; bowCtrlPoints[1][2] = 1;
	bowCtrlPoints[2][0] = -0.2; bowCtrlPoints[2][1] = -1.0; bowCtrlPoints[2][2] = 1;
	bowCtrlPoints[3][0] = -0.5; bowCtrlPoints[3][1] = -4.3; bowCtrlPoints[3][2] = 0.0;

	// initial control points for the string
	stringCtrlPoints[0][0] = -0.5; stringCtrlPoints[0][1] = 1.0; stringCtrlPoints[0][2] = 2;
	stringCtrlPoints[1][0] = -0.5; stringCtrlPoints[1][1] = -1.85; stringCtrlPoints[1][2] = 1;
	stringCtrlPoints[2][0] = -0.5; stringCtrlPoints[2][1] = -1.85; stringCtrlPoints[2][2] = 1;
	stringCtrlPoints[3][0] = -0.5; stringCtrlPoints[3][1] = -4.3; stringCtrlPoints[3][2] = 0.0;
}

void Bow::draw() {
	// draw bow
	glShadeModel(GL_FLAT);
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &bowCtrlPoints[0][0]);
	glEnable(GL_MAP1_VERTEX_3);
	int i;
	glColor3f(1.0, 0, 0);
	glLineWidth((GLfloat)5);
	glBegin(GL_LINE_STRIP);
		for (i = 0; i <= 30; i++){
	         glEvalCoord1f((GLfloat) i/30.0);
		}
	 glEnd();

	// draw bowstring
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &stringCtrlPoints[0][0]);
	glEnable(GL_MAP1_VERTEX_3);
	glColor3f(0,0,1);
	glLineWidth((GLfloat)1);
	int j;
	glBegin(GL_LINE_STRIP);
		for (j = 0; j <= 30; j++){
	         glEvalCoord1f((GLfloat) j/30.0);
		}
	 glEnd();

	glColor4f(1.f, 1.f, 1.f, 1.f);
}

void Bow::pullBow(bool toggle) {
	if (toggle) {
		if (stringCtrlPoints[1][0] > MAXIMUM_BOW_PULL) {
			// bow anchor points
			bowCtrlPoints[0][0] -= X_BOW_ANCHOR_INCREMENT; bowCtrlPoints[0][1] -= Y_BOW_ANCHOR_INCREMENT;
			bowCtrlPoints[3][0] -= X_BOW_ANCHOR_INCREMENT; bowCtrlPoints[3][1] += Y_BOW_ANCHOR_INCREMENT;

			// string control points
			stringCtrlPoints[1][0] -= X_STRING_CONTROL_INCREMENT;
			stringCtrlPoints[2][0] -= Y_STRING_CONTROL_INCREMENT;
			// string anchor points
			stringCtrlPoints[0][0] -= X_STRING_ANCHOR_INCREMENT; stringCtrlPoints[0][1] -= Y_STRING_ANCHOR_INCREMENT;
			stringCtrlPoints[3][0] -= X_STRING_ANCHOR_INCREMENT; stringCtrlPoints[3][1] += Y_STRING_ANCHOR_INCREMENT;
		}
	}
	else {
		// initial control points for the bow
		bowCtrlPoints[0][0] = -0.5; bowCtrlPoints[0][1] = 1.0; bowCtrlPoints[0][2] = 2;
		bowCtrlPoints[1][0] = -0.2; bowCtrlPoints[1][1] = -0.8; bowCtrlPoints[1][2] = 1;
		bowCtrlPoints[2][0] = -0.2; bowCtrlPoints[2][1] = -1.0; bowCtrlPoints[2][2] = 1;
		bowCtrlPoints[3][0] = -0.5; bowCtrlPoints[3][1] = -4.3; bowCtrlPoints[3][2] = 0.0;

		// initial control points for the string
		stringCtrlPoints[0][0] = -0.5; stringCtrlPoints[0][1] = 1.0; stringCtrlPoints[0][2] = 2;
		stringCtrlPoints[1][0] = -0.5; stringCtrlPoints[1][1] = -1.85; stringCtrlPoints[1][2] = 1;
		stringCtrlPoints[2][0] = -0.5; stringCtrlPoints[2][1] = -1.85; stringCtrlPoints[2][2] = 1;
		stringCtrlPoints[3][0] = -0.5; stringCtrlPoints[3][1] = -4.3; stringCtrlPoints[3][2] = 0.0;

		// TO BE IMPLEMENTED
		// fluid return to original position


	}
}

/* The following code displays the control points as dots. */
//	   glPointSize(5.0);
//	   glColor3f(1.0, 0, 0);
//	   glBegin(GL_POINTS);
//	      for (i = 0; i < 4; i++)
//	         glVertex3fv(&ctrlpoints[i][0]);
//	   glEnd();

