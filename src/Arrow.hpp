/*
 * Arrow.hpp
 *
 *  Created on: Nov 28, 2016
 *      Author: Joe
 */

#ifndef CARROW_H
#define CBOW_H

#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

#include "Target.hpp"

class Arrow {

public:

	GLfloat arrowCoordinates[2][3];
	bool fired;
	float rotate;
	float xrotation;
	float yrotation;
	Arrow(); // initializer function
	void draw();// draw function must be overwritten    - may need to include 'virtual' because it has to be overwritten

	// TO BE IMPLEMENTED
	// modify fireArrow() to accept:
	// 		a 2D array - to hold the direction vector of the arrow
	//		float - to determine the power of the arrow
	void fireArrow(bool); // fire arrow
	void translate(GLfloat tx, GLfloat ty, GLfloat tz);

	void reset(); // reload arrow
};

#endif
