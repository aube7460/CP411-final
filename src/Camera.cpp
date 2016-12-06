/*
 * Camera.cpp
 *
 *  Created on: Nov 29, 2016
 *      Author: jason
 */

#include <stdio.h>
#include "Camera.hpp"
#include "Matrix.hpp"


bool DEBUG = false;

Camera::Camera(){
	eye.x = 0.0, eye.y = 0.0, eye.z = 10.0;
	ref.x = 0.0, ref.y = 0.0, ref.z = 0.0;
	viewup.x = 0.0,viewup.y = 1.0, viewup.z = 0.0;
	aspect = 1.0, viewAngle = 40.0, nearDist = 1.0, farDist = 30.0;
	setViewNorm();
}


void Camera::setDefaultCamera(void) { // make default camera
	eye.x = 5.0, eye.y = 0.0, eye.z = 10.0;
	ref.x = 0.0, ref.y = 0.0, ref.z = 0.0;
	viewup.x = 0.0,viewup.y = 1.0, viewup.z = 0.0;
	aspect = 1.0, viewAngle = 40.0, nearDist = 1.0, farDist = 40.0;
	setViewNorm();
}

void Camera::set(Point Eye, Point Look, Vector Up) {
	eye.set(Eye);
	ref.set(Look);
	viewup.set(Up);
	aspect = 1.0, viewAngle = 40.0, nearDist = 1.0, farDist = 40.0;
	setViewNorm();
}


void Camera::setViewNorm() {
	GLfloat x, y, z, sr;
	x = ref.x-eye.x;
	y = ref.y-eye.y;
	z = ref.z-eye.z;
	sr = sqrt(x*x + y*y + z*z);
	x = x/sr;
	y = y/sr;
	z = z/sr;
	viewNorm.set(x, y, z);
}

void Camera::rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle){ //w.r.p.t WC
	Matrix *m =  new Matrix();
	m->rotate(rx, ry, rz, angle);
	GLfloat vector[4];
	vector[0] = eye.x;
	vector[1] = eye.y;
	vector[2] = eye.z;
	vector[3] = 1;
	m->multiply_vector(vector);
	eye.x = vector[0];
	eye.y = vector[1];
	eye.z = vector[2];
}

void Camera::translate(GLfloat tx, GLfloat ty, GLfloat tz){ //w.r.p.t WC
	eye.x += tx;
	eye.y += ty;
	eye.z += tz;
}

void Camera::setProjectionMatrix() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(viewAngle, aspect, nearDist, farDist);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye.x, eye.y, eye.z, ref.x, ref.y, ref.z, viewup.x,viewup.y,viewup.z);
}
