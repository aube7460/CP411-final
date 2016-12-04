#include "Bow.hpp"


Bow::Bow(){
	// initial control points for the bow
	bowCtrlPoints[0][0] = 0.0; bowCtrlPoints[0][1] = 0.0; bowCtrlPoints[0][2] = 0.0;
	bowCtrlPoints[1][0] = 0.75; bowCtrlPoints[1][1] = -0.6; bowCtrlPoints[1][2] = 0.0;
	bowCtrlPoints[2][0] = 0.75; bowCtrlPoints[2][1] = -1.8; bowCtrlPoints[2][2] = 0.0;
	bowCtrlPoints[3][0] = 0.0; bowCtrlPoints[3][1] = -4.0; bowCtrlPoints[3][2] = 0.0;

	glShadeModel(GL_FLAT);
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &bowCtrlPoints[0][0]);
	glEnable(GL_MAP1_VERTEX_3);
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
	glColor3f(0,1,0);
	glLineWidth((GLfloat)1);
	glBegin(GL_LINES);
	    glVertex3f(0, 0, 0);
	    glVertex3f(0, -4, 0);
	glEnd();

	glColor4f(1.f, 1.f, 1.f, 1.f);
}


/* The following code displays the control points as dots. */
//	   glPointSize(5.0);
//	   glColor3f(1.0, 0, 0);
//	   glBegin(GL_POINTS);
//	      for (i = 0; i < 4; i++)
//	         glVertex3fv(&ctrlpoints[i][0]);
//	   glEnd();

