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
#include "Bow.hpp"
#include "Target.hpp"

// declaring the size of the window
GLint winWidth = 800, winHeight = 800;

Background myBackground;
Camera myCamera;
Landscape myLandscape;
Light myLight;
Tree myTree;
RGBpixmap pix[6];   // make six pixmaps
GLint textureArr[2];
Bow myBow;
Target myTarget;

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	myLight.translate(1.5,1.5,1.5);

	myCamera.setProjectionMatrix();
/*	myLandscape.list[1] -> translate(0,0,2);
	myLandscape.list[2] -> translate(2,0,0);
	myLandscape.list[3] -> translate(0,3,0);*/

	pix[0].readBMPFile("target1.bmp");
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
	myTarget.myTarget->textureID = 0;
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
	myTarget.draw(1.0,1.0);
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
	//glewInit();
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed); // movement key function
	glutMainLoop();

	return 0;

}
