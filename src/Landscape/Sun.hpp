/*
 * Sun.hpp
 *
 *  Created on: Nov 29, 2016
 *      Author: jason
 */

#ifndef SUN_HPP_
#define SUN_HPP_

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include <GL/glut.h>
#include "Sphere.hpp"

extern GLfloat light0_ambient[];
extern GLfloat light0_diffuse[];
extern GLfloat light0_position[];

class Sun : public Shape {

public:
	GLfloat Rd, Ia, Ra;
	Sphere* mySun;

	Sun();
	void draw();
	void set_color(GLfloat, GLfloat, GLfloat);
	void scale_change(GLfloat x);
	//void translate(GLfloat tx, GLfloat ty, GLfloat tz);
	void rotate_origin(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);
	void reset();
};

#endif /* SUN_HPP_ */
