/*
 * main.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: jason
 */

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "glaux.h" // for reading bmp files
#include "Camera.hpp"
#include "Matrix.hpp"
#include "Light.hpp"
#include "Landscape/Landscape.hpp"
#include "Landscape/Background.hpp"
#include "Landscape/TreeBody.hpp"
#include "Landscape/Tree.hpp"
#include "pixmap/RGBpixmap.hpp"

// declaring the size of the window
GLint winWidth = 800, winHeight = 800;

Background myBackground;
Camera myCamera;
Landscape myLandscape;
Light myLight;
Tree myTree;
RGBpixmap pix[6];   // make six pixmaps
GLint textureArr[2];

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	myLight.translate(1.5,1.5,1.5);

	myCamera.setProjectionMatrix();
/*	myLandscape.list[1] -> translate(0,0,2);
	myLandscape.list[2] -> translate(2,0,0);
	myLandscape.list[3] -> translate(0,3,0);*/

	pix[0].readBMPFile("Bullseye.bmp");
	pix[0].setTexture(0);

	pix[1].readBMPFile("sky.bmp");
	pix[1].setTexture(1);

	pix[2].readBMPFile("grass.bmp");
	pix[2].setTexture(2);

	pix[3].readBMPFile("treeBody.bmp");
	pix[3].setTexture(3);

	pix[4].readBMPFile("bark.bmp");
	pix[4].setTexture(4);

	pix[5].readBMPFile("sun.bmp");
	pix[5].setTexture(5);

	myTree.myBody->textureID = 3;
	myTree.myTrunk->textureID = 4;
	myLandscape.list[1] = &myTree;

	Sun* sunObj = (Sun*) myLandscape.list[0];
	sunObj->mySun->textureID=5;
	myBackground.textureGroundID = 2;
	myBackground.textureSkyID = 1;
}

void reset(void) {
	glFlush();
	glutPostRedisplay();
}

void close(void) {
	exit(0);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	myCamera.setProjectionMatrix();
	myBackground.drawGround(winWidth,winHeight);
	myBackground.drawSky(winWidth,winHeight);
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
	//glewInit();
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;

}
