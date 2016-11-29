/*
 * Shape.hpp
 *
 *  Created on: Nov 28, 2016
 *      Author: jason
 */

#ifndef CSHAPE_H
#define CSHAPE_H

#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "Matrix.hpp"

using namespace std;

/**
 * Shape class the common class that will be inherited model object class
 */
class Shape {
protected:
	Matrix MC; //the Model coordinate system in (X, Y, Z, 0)
	GLfloat s; // scale factor

public:
	Shape();  						// constructor
	virtual ~Shape();  				// destructor
	Matrix getMC();					// get MC matrix
	void ctm_multiply(); 			// function to do the CTM * MC
	void scale_change(GLfloat x);	// to change the scale factor
	virtual void translate(GLfloat tx, GLfloat ty, GLfloat tz); // to translate the MC origin
	virtual void rotate_mc(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle); // to rotate the MC with respect to a local axis.
	virtual void rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);// to rotate the MC including both vectors and origin
	virtual void rotate_origin(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);// to rotate the origin of MC and keep the vector changed
	void rotate_relative(double x0, double y0, double z0, double rx, double ry, double rz, double angle);
	virtual void draw(){};// draw function must be overwritten
	virtual void draw(GLuint){};// draw with texture
	virtual void reset();
};

#endif

