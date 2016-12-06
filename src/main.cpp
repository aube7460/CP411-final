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
#include "Landscape/Landscape.hpp"
#include "Landscape/Background.hpp"
#include "Landscape/TreeBody.hpp"
#include "Landscape/Tree.hpp"
#include "pixmap/RGBpixmap.hpp"
#include "Bow.hpp"
#include "Arrow.hpp"
#include "Target.hpp"

// declaring the size of the window
GLint winWidth = 800, winHeight = 800;

// Variables for target position and arrow position
GLfloat tarX = -0.4;
GLfloat tarY=-0.6;
GLfloat tarZ=-10.0;
GLfloat arrowXPos,arrowYPos,arrowZPos;


Background myBackground;
Camera myCamera;
Landscape myLandscape;
Tree myTree,myTree2,myTree3;
RGBpixmap pix[6];   // make six pixmaps
Bow myBow;
Arrow myArrow;
Target myTarget;

//declare shader program object
GLuint ProgramObject;

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);

	myCamera.setProjectionMatrix();

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
	myTree.scale_change(0.2);
	myTree.myBody->translate(0,-0.25,0);
	myTree2.myBody->textureID = 3;
	myTree2.myTrunk->textureID = 4;
	myTree2.scale_change(0.4);
	myTree2.myBody->translate(0,-0.25,0);
	myTree3.myBody->textureID = 3;
	myTree3.myTrunk->textureID = 4;
	myTree3.scale_change(0.8);

	myLandscape.list[1] = &myTree;
	myLandscape.list[2] = &myTree2;
	myLandscape.list[3] = &myTree3;

	myLandscape.list[1] -> translate(1.5,0,0);
	myLandscape.list[2] -> translate(-1.5,-0.5,0);
	myLandscape.list[3] -> translate(-2.5,-1,0);

	myTarget.myTarget->translate(tarX,tarY,tarZ);

	Sun* sunObj = (Sun*) myLandscape.list[0];
	sunObj->mySun->textureID=5;

	myBackground.textureGroundID = 2;
	myBackground.textureSkyID = 1;

	myTarget.myTarget->textureID = 0;
	myTarget.scale_change(0.25);
}

void reset(void) {
	myArrow.reset();
	myBow.reset();
	glFlush();
	glutPostRedisplay();
}

void close(void) {
	exit(0);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	myCamera.setProjectionMatrix();
	myBackground.drawGround(winWidth,winHeight);
	myBackground.drawSky(winWidth,winHeight);
	myLandscape.draw_landscape();
	myTarget.draw(tarX,tarY,tarZ,0.3);
	myArrow.draw();
	myBow.draw();

	glFlush();
	glutSwapBuffers();
}

void animate_arrow(int keepGoing) {
	if ((arrowXPos<(tarX+myTarget.myTarget->radius)&&
		(arrowXPos>(tarX-myTarget.myTarget->radius)))&&
		((arrowYPos<(tarY+myTarget.myTarget->radius))&&
		(arrowYPos>(tarY-myTarget.myTarget->radius)))&&
		arrowZPos <= tarZ){
		printf("TARGET HIT\n");
		myArrow.fired = false;
	}else {
		if (arrowZPos < -15){
			myArrow.fired = false;
			printf("MISSED");
		}
	}
	arrowZPos = arrowZPos - 0.5;
	myArrow.translate(0,0,-0.5);

    if (keepGoing && myArrow.fired) {
    	glutTimerFunc(40, animate_arrow, 1);  // callback every 40 ms
    }
    glutPostRedisplay();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	winWidth = newWidth;
	winHeight = newHeight;
}

void keyPressed (unsigned char key, int x, int y) {
	if (key == 's') {
		if (myCamera.eye.y < 1.25){ //DOWN
			myCamera.rotate(1.0, 0.0,0.0, 0.5);
			myBow.rotate = 3;
			myArrow.rotate = 3;
		}
	}
	else if (key == 'a') { //LEFT
		if (myCamera.eye.x <8){
			myCamera.rotate(0.0, -1.0, 0.0, 0.5);
			myBow.rotate = 1;
			myArrow.rotate = 1;
		}

	}
	else if (key == 'w') { //UP
		if (myCamera.eye.y > -3){
			myCamera.rotate(-1.0, 0.0,0.0, 0.5);
			myBow.rotate = 4;
			myArrow.rotate = 4;
		}
	}
	else if (key == 'd') { //RIGHT
		if (myCamera.eye.x>-8){
			myCamera.rotate(0.0, 1.0, 0.0,0.5);
			myBow.rotate = 2;
			myArrow.rotate = 2;
		}
	}
	else if (key == 'o') {
		myArrow.fireArrow(true);
		myBow.pullBow(true);
		display();
	}
	else if (key == 'r') {
		reset();
	}

	else {
		printf("Invalid keystroke\n");
	}
	glutPostRedisplay();
}

void keyUpPressed (unsigned char key, int x, int y) {
	if (key == 'o') {
		arrowXPos = myArrow.arrowCoordinates[1][0];
		arrowYPos = myArrow.arrowCoordinates[1][1];
		arrowZPos = myArrow.arrowCoordinates[0][2];
		myArrow.fireArrow(false);
		myBow.pullBow(false);

		animate_arrow(1);
		display();
	}
//	else if (key == 'a' ) {
//		myBow.rotate = 0;
//	}
//	else if (key =='d') {
//		myBow.rotate = 0;
//	}
//	else if (key == 'w') {
//		myBow.rotate = 0;
//	}
//	else if (key == 'a') {
//		myBow.rotate = 0;
//	}
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
	glutKeyboardUpFunc(keyUpPressed);
	glutMainLoop();

	return 0;

}
