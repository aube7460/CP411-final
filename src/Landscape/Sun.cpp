/*
 * Sun.cpp
 *
 *  Created on: Nov 29, 2016
 *      Author: jason
 */

#include "Sun.hpp"

Sun::Sun() {
	mySun = new Sphere();
	mySun-> radius = 0.5;
	mySun-> translate(3, 3, 0);
	Rd = 0.5;
	Ia = 1.0;
	Ra = 0.5;

}

void Sun::draw() { /*1: wire, 4: bitmap */
	GLfloat matAmb1[] = { 0.7, 0.53, 0.3, 1.0 }; //ambient
	GLfloat matDif1[] = { 0.76, 0.57, 0.16, 1.0 }; //diffuse
	GLfloat matSpec1[] = { 1.0, 0.15, 0.0, 1.0 }; //specular
	GLfloat matEm1[] = { 0.75, 0.588, 0.0, 1.0 }; //emission
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDif1);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec1);
	glMaterialfv(GL_FRONT, GL_EMISSION, matEm1);
	mySun->draw();
}

void Sun::rotate_origin(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
	mySun->rotate_origin(rx, ry, rz, angle);
}

void Sun::reset() {
	delete mySun;
	mySun = new Sphere();
	mySun->radius = 1;
	mySun->translate(0, 0, 0);
	Rd = 0.5;
	Ia = 1.0;
	Ra = 0.5;
}
