/*
 * main.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: jason
 */

/**
 *	CP411 Assignment 4 reference design
 */

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

// declaring the size of the window
GLint winWidth = 800, winHeight = 800;
// define the colors RGB
GLfloat red = 1.0, green = 1.0, blue = 1.0;  //color

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
}


void reset(void) {
	glFlush();
	glutPostRedisplay();
}

void close(void) {
	exit(0);
}

void display(void) {
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

void mouseAction(int button, int state, int x, int y) {
	glutPostRedisplay();
}

void mouseMotion(GLint x, GLint y) {
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Archery by Jason and Joe");
	init();
	return 0;
}
