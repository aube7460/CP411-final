/*
 * Target.cpp
 *
 *  Created on: Nov 29, 2016
 *      Author: jason
 */

#include "Target.hpp"

Target::Target(){
	PI = 3.14159;
	myTarget = new Sphere();
	myTarget->radius=0.25;

}

void Target::draw(GLfloat x, GLfloat y,GLfloat z,GLfloat radius){
	//myTarget->translate(x,y,z);
	tarX = x;
	tarY = y;
	tarZ = z;
	myTarget->radius = radius;
	GLfloat matAmb1[] = { 0.7, 0.53, 0.3, 1.0 }; //ambient
	GLfloat matDif1[] = { 0.76, 0.57, 0.16, 1.0 }; //diffuse
	GLfloat matSpec1[] = { 1.0, 0.15, 0.0, 1.0 }; //specular
	GLfloat matEm1[] = { 0.75, 0.588, 0.0, 1.0 }; //emission
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDif1);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec1);
	glMaterialfv(GL_FRONT, GL_EMISSION, matEm1);
	myTarget->draw();

	/*glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,textureID);
	glBegin(GL_POLYGON);
		for(i = 0; i < 360.0;i+=2) {
			radian = i * (PI/180.0);
			 x = (float)cos(radian)*radius+x;
			 y = (float)sin(radian)*radius+y;

			 glTexCoord2f(x, y);
			 glVertex2f(x, y);
		}
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor4f(1.f, 1.f, 1.f, 1.f);*/
}
