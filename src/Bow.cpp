#include "Bow.hpp"


Bow::Bow(){
	// initial control points for the bow
	bowCtrlPoints[0][0] = -0.5; bowCtrlPoints[0][1] = -2.5; bowCtrlPoints[0][2] = 0.0;
	bowCtrlPoints[1][0] = 0.0; bowCtrlPoints[1][1] = -3.3; bowCtrlPoints[1][2] = 0.0;
	bowCtrlPoints[2][0] = 0.0; bowCtrlPoints[2][1] = -4.5; bowCtrlPoints[2][2] = 0.0;
	bowCtrlPoints[3][0] = -0.5; bowCtrlPoints[3][1] = -5.8; bowCtrlPoints[3][2] = 0.0;

	// initial control points for the string
	stringCtrlPoints[0][0] = -0.5; stringCtrlPoints[0][1] = -2.5; stringCtrlPoints[0][2] = 0.0;
	stringCtrlPoints[1][0] = -0.5; stringCtrlPoints[1][1] = -4.35; stringCtrlPoints[1][2] = 0.0;
	stringCtrlPoints[2][0] = -0.5; stringCtrlPoints[2][1] = -4.35; stringCtrlPoints[2][2] = 0.0;
	stringCtrlPoints[3][0] = -0.5; stringCtrlPoints[3][1] = -5.8; stringCtrlPoints[3][2] = 0.0;


}

void Bow::draw() {
	// draw bow
	glShadeModel(GL_FLAT);
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &bowCtrlPoints[0][0]);
	glEnable(GL_MAP1_VERTEX_3);
	int i;
	glColor3f(1.0, 0, 0);
	glLineWidth((GLfloat)3);
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
		// bow anchor points
		bowCtrlPoints[0][0] -= 0.008; bowCtrlPoints[0][1] -= 0.008;
		bowCtrlPoints[3][0] -= 0.008; bowCtrlPoints[3][1] += 0.008;

		// string control points
		stringCtrlPoints[1][0] -= 0.05;
		stringCtrlPoints[2][0] -= 0.05;

		// string anchor points
		stringCtrlPoints[0][0] -= 0.008; stringCtrlPoints[0][1] -= 0.008;
		stringCtrlPoints[3][0] -= 0.008; stringCtrlPoints[3][1] += 0.008;

	}
	else {
		// reset bow control points
		bowCtrlPoints[0][0] = -0.5; bowCtrlPoints[0][1] = -2.5; bowCtrlPoints[0][2] = 0.0;
		bowCtrlPoints[1][0] = 0.0; bowCtrlPoints[1][1] = -3.3; bowCtrlPoints[1][2] = 0.0;
		bowCtrlPoints[2][0] = 0.0; bowCtrlPoints[2][1] = -4.5; bowCtrlPoints[2][2] = 0.0;
		bowCtrlPoints[3][0] = -0.5; bowCtrlPoints[3][1] = -5.8; bowCtrlPoints[3][2] = 0.0;


		// reset string control points
		stringCtrlPoints[0][0] = -0.5; stringCtrlPoints[0][1] = -2.5; stringCtrlPoints[0][2] = 0.0;
		stringCtrlPoints[1][0] = -0.5; stringCtrlPoints[1][1] = -4.35; stringCtrlPoints[1][2] = 0.0;
		stringCtrlPoints[2][0] = -0.5; stringCtrlPoints[2][1] = -4.35; stringCtrlPoints[2][2] = 0.0;
		stringCtrlPoints[3][0] = -0.5; stringCtrlPoints[3][1] = -5.8; stringCtrlPoints[3][2] = 0.0;
	}
}

/* The following code displays the control points as dots. */
//	   glPointSize(5.0);
//	   glColor3f(1.0, 0, 0);
//	   glBegin(GL_POINTS);
//	      for (i = 0; i < 4; i++)
//	         glVertex3fv(&ctrlpoints[i][0]);
//	   glEnd();

