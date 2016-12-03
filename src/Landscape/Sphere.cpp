/*
 * Sphere.cpp
 *
 *  Created on: Nov 29, 2016
 *      Author: jason
 */

#include "Sphere.hpp"

Sphere::Sphere() {
	radius = 1.0, slices = 50, stacks = 50;
	textureID = 0;
	quad = gluNewQuadric();

	gluQuadricTexture(quad, GL_TRUE);
	gluQuadricOrientation(quad, GLU_OUTSIDE);
	gluQuadricNormals(quad, GLU_SMOOTH);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

Sphere::~Sphere() {
}

void Sphere::draw() {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glPushMatrix();
	this->ctm_multiply();
	gluSphere(quad, radius, slices, stacks);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}
