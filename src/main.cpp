/*
 * main.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: jason
 */

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "Camera.hpp"
#include "Matrix.hpp"
#include "Light.hpp"
#include "Landscape/Landscape.hpp"
#include "Landscape/background.hpp"

// declaring the size of the window
GLint winWidth = 800, winHeight = 800;
// define the colors RGB
GLfloat red = 1.0, green = 1.0, blue = 1.0;  //color

Camera myCamera;
Landscape myLandscape;
Background myBackground;
Light myLight;

void init(void) {
	myLight.translate(1.5,1.5,1.5);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	myCamera.setProjectionMatrix();
	myBackground.draw(winWidth,winHeight);
	myLandscape.list[1] -> translate(0,0,2);
	myLandscape.list[2] -> translate(2,0,0);
	myLandscape.list[3] -> translate(0,3,0);
}

void reset(void) {
	glFlush();
	glutPostRedisplay();
}

void close(void) {
	exit(0);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	myCamera.setProjectionMatrix();
	myLandscape.draw_landscape();
	glFlush();
	glutSwapBuffers();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	winWidth = newWidth;
	winHeight = newHeight;
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Archery Simulation by Jason and Joe");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;

}
