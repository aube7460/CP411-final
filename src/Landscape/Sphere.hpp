/*
 * Sphere.hpp
 *
 *  Created on: Nov 29, 2016
 *      Author: jason
 */

#ifndef SPHERE_H
#define SPHERE_H

#include <windows.h>
#include <GL/glut.h>
#include "../Shape.hpp"

class Sphere: public Shape {
public:

	GLfloat radius;
	GLint slices, stacks;
	GLuint textureID;
	GLUquadric *quad;
	Sphere();
	~Sphere();
	void draw();
};

#endif
