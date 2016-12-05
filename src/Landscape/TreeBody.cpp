/*
 * TreeBody.cpp
 *
 *  Created on: Nov 29, 2016
 *      Author: jason
 */

#include "TreeBody.hpp"

extern Sun mySun;

TreeBody::TreeBody(){
	vertex[0][0] = -0.5; vertex[0][1] = 0; vertex[0][2] =  0.5;
	vertex[1][0] =  0.5; vertex[1][1] = 0; vertex[1][2] =  0.5;
	vertex[2][0] =  0.5; vertex[2][1] = 0; vertex[2][2] = -0.5;
	vertex[3][0] = -0.5; vertex[3][1] = 0; vertex[3][2] = -0.5;
	vertex[4][0] =  0.5; vertex[4][1] = 2; vertex[4][2] =  0.5;

	face[0][0] = 1;face[0][1] = 4;face[0][2] = 0;
	face[1][0] = 2;face[1][1] = 4;face[1][2] = 1;
	face[2][0] = 3;face[2][1] = 4;face[2][2] = 2;
	face[3][0] = 0;face[3][1] = 4;face[3][2] = 3;

	TreeBody_face_norm_mc[0][0] = 0.0,TreeBody_face_norm_mc[0][1] = 0.0,TreeBody_face_norm_mc[0][2] = -1.0,
	TreeBody_face_norm_mc[1][0] = 1.0, TreeBody_face_norm_mc[1][1] = 0.0, TreeBody_face_norm_mc[1][2] = 0.0;
	TreeBody_face_norm_mc[2][0] = 0.0, TreeBody_face_norm_mc[2][1] = 0.0, TreeBody_face_norm_mc[2][2] = 1.0;
	TreeBody_face_norm_mc[3][0] = -1.0, TreeBody_face_norm_mc[3][1] = 0.0, TreeBody_face_norm_mc[3][2] = 0.0;

	textureID=0;

}

void TreeBody::draw_face(int i){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glBegin(GL_TRIANGLES);
		glTexCoord2f(0.0,0.0);glVertex3fv(&vertex[face[i][0]][0]);
		glTexCoord2f(2.0,0.0);glVertex3fv(&vertex[face[i][1]][0]);
		glTexCoord2f(1.0,1.0);glVertex3fv(&vertex[face[i][2]][0]);
	glEnd();
	glDisable(GL_TEXTURE_2D);
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

/*GLfloat TreeBody::getFaceShade(int faceIndex){
	GLfloat Id;
	GLfloat v[3];
	GLfloat s;

	v[0] = vertex[face[faceIndex][0]][0] - getMC().mat[0][3];
	v[1] = vertex[face[faceIndex][0]][1] - getMC().mat[1][3];
	v[2] = vertex[face[faceIndex][0]][2] - getMC().mat[2][3];

	s = TreeBody_face_norm_mc[faceIndex][0]*v[0] + TreeBody_face_norm_mc[faceIndex][1]*v[1]+TreeBody_face_norm_mc[faceIndex][2]*v[2];

	Id = mySun.Rd*s+mySun.Ra*mySun.Ia*0.75 ;

	return Id;
}*/
