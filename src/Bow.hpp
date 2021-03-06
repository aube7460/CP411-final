/*
 * Bow.hpp
 *
 *  Created on: Nov 28, 2016
 *      Author: Joe
 */

#ifndef CBOW_H
#define CBOW_H

#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

class Bow {

public:
	GLfloat bowCtrlPoints[4][3];
	GLfloat stringCtrlPoints[4][3];

	Bow(); // initializer function


	void draw();// draw function must be overwritten    - may need to include 'virtual' because it has to be overwritten

	// TO BE IMPLEMENTED
	// change pullBow(bool) to return a float - the distance drawn on the bowstring, will be passed to myArrow as power
	void pullBow(bool); // adjust control points for the bow

	void reset(); // reset bow
};

#endif
