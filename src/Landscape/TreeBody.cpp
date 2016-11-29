/*
 * TreeBody.cpp
 *
 *  Created on: Nov 29, 2016
 *      Author: jason
 */

#include "TreeBody.hpp"

TreeBody::TreeBody(){
	vertex[0][0] = -1;vertex[0][1] = 0;vertex[0][2] = 1;
	vertex[1][0] = 1;vertex[1][1] = 0;vertex[1][2] = 1;
	vertex[2][0] = 1;vertex[2][1] = 0;vertex[2][2] = -1;
	vertex[3][0] = -1;vertex[3][1] = 0;vertex[3][2] = -1;
	vertex[4][0] = 0;vertex[4][1] = 1;vertex[4][2] = 0;

	face[0][0] = 1;face[0][1] = 4;face[0][2] = 0;
	face[1][0] = 2;face[1][1] = 4;face[1][2] = 1;
	face[2][0] = 3;face[2][1] = 4;face[2][2] = 2;
	face[3][0] = 0;face[3][1] = 4;face[3][2] = 3;

}

void TreeBody::draw_face(int i){
	glBegin(GL_LINE_LOOP);
		glVertex3fv(&vertex[face[i][0]][0]);
		glVertex3fv(&vertex[face[i][1]][0]);
		glVertex3fv(&vertex[face[i][2]][0]);
	glEnd();
}

void TreeBody::draw(){
	glPushMatrix();
	this->ctm_multiply();
	glScalef(s,s,s);
	for (int i = 0; i < 4; i++){
		draw_face(i);
	}
	glPopMatrix();
}

