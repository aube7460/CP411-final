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
#include "Bow.hpp"

// declaring the size of the window
GLint winWidth = 800, winHeight = 800;
// define the colors RGB
GLfloat red = 1.0, green = 1.0, blue = 1.0;  //color

Camera myCamera;
Landscape myLandscape;
Light myLight;
Bow myBow;

void init(void) {
	myLight.translate(1.5,1.5,1.5);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	myCamera.setProjectionMatrix();


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

	myBow.draw();

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

void keyPressed (unsigned char key, int x, int y) {
	if (key == 'w') {
		printf("UP\n");
	}
	else if (key == 'a') {
		printf("LEFT\n");
	}
	else if (key == 's') {
		printf("DOWN\n");
	}
	else if (key == 'd') {
		printf("RIGHT\n");
	}
	else {
		printf("-invalid key-\n");
	}
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
      glOrtho(-5.0, 5.0, -5.0*(GLfloat)h/(GLfloat)w,
               5.0*(GLfloat)h/(GLfloat)w, -5.0, 5.0);
   else
      glOrtho(-5.0*(GLfloat)w/(GLfloat)h,
               5.0*(GLfloat)w/(GLfloat)h, -5.0, 5.0, -5.0, 5.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Archery Simulation by Jason and Joe");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed); // movement key function
	glutMainLoop();

	return 0;
}
