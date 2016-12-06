/*
 * tree.cpp
 *
 *  Created on: Nov 29, 2016
 *      Author: jason
 */

#include "TreeTrunk.hpp"

extern Camera myCamera;
//extern Light myLight;

TreeTrunk::TreeTrunk(){
	vertex[0][0] = -0.5; vertex[0][1] = -1; vertex[0][2] = -0.5;
	vertex[1][0] = -0.5; vertex[1][1] =  1; vertex[1][2] = -0.5;
	vertex[2][0] =  0.5; vertex[2][1] = -1; vertex[2][2] = -0.5;
	vertex[3][0] =  0.5; vertex[3][1] =  1; vertex[3][2] = -0.5;
	vertex[4][0] = -0.5; vertex[4][1] = -1; vertex[4][2] =  0.5;
	vertex[5][0] = -0.5; vertex[5][1] =  1; vertex[5][2] =  0.5;
	vertex[6][0] = 	0.5; vertex[6][1] = -1; vertex[6][2] =  0.5;
	vertex[7][0] = 	0.5; vertex[7][1] =  1; vertex[7][2] =  0.5;

	face[0][0] = 0;face[0][1] = 1;face[0][2] = 3;face[0][3] = 2;
	face[1][0] = 3;face[1][1] = 7;face[1][2] = 6;face[1][3] = 2;
	face[2][0] = 7;face[2][1] = 5;face[2][2] = 4;face[2][3] = 6;
	face[3][0] = 4;face[3][1] = 5;face[3][2] = 1;face[3][3] = 0;
	face[4][0] = 5;face[4][1] = 7;face[4][2] = 3;face[4][3] = 1;
	face[5][0] = 6;face[5][1] = 4;face[5][2] = 0;face[5][3] = 2;

	textureID = 0;
}

void TreeTrunk::draw_face(int i){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0,0.0);glVertex3fv(&vertex[face[i][0]][0]);
		glTexCoord2f(1.0,0.0);glVertex3fv(&vertex[face[i][1]][0]);
		glTexCoord2f(1.0,1.0);glVertex3fv(&vertex[face[i][2]][0]);
		glTexCoord2f(0.0,1.0);glVertex3fv(&vertex[face[i][3]][0]);
	glEnd();
	glColor4f(1.f, 1.f, 1.f, 1.f);

	glDisable(GL_TEXTURE_2D);

}

void TreeTrunk::draw(){
	glPushMatrix();
	this->ctm_multiply();
	glScalef(0.5*s,0.5*s,0.5*s);
	for (int i=0; i<6; i++){
		draw_face(i);
	}
	glPopMatrix();
}

/*bool TreeTrunk::isBackface(int i){
	GLfloat v[4];
	v[0] = treeTrunk_face_norm_mc[i][0];
	v[1] = treeTrunk_face_norm_mc[i][1];
	v[2] = treeTrunk_face_norm_mc[i][2];
	v[3] = 0.0;
	this->MC.multiply_vector(v);

	if(v[0]*myCamera.eye.x+v[1]*myCamera.eye.y+v[2]*myCamera.eye.z+v[3] < 0){
		return true;
	}

	return false;
}*/

