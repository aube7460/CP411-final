/*
 * Target.hpp
 *
 *  Created on: Nov 29, 2016
 *      Author: jason
 */

#ifndef TARGET_HPP_
#define TARGET_HPP_

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include <GL/glut.h>
#include "Landscape/Sphere.hpp"

class Target : public Shape{
public:
	Sphere* myTarget;
	GLfloat PI;
	Target();
	void draw(GLfloat x, GLfloat y,GLfloat radius);
};

#endif /* TARGET_HPP_ */
