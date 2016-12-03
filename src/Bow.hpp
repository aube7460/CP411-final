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
#include <stdio.h>

class Bow {

protected:
	GLfloat bowCtrlPoints[4][3];

public:

	Bow(); // initializer function
	void draw(){};// draw function must be overwritten    - may need to include 'virtual' because it has to be overwritten
	void pullBow(); // adjust control points for the bow
	void reset(); // reset bow
};

#endif