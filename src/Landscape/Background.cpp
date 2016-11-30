/*
 * background.cpp
 *
 *  Created on: Nov 29, 2016
 *      Author: jason
 */

#include "Background.hpp"

void Background::draw(int width, int height){
	glColor3f(0,0,1);
	glBegin(GL_LINE_LOOP);
			glVertex2i(0, 0);
			glVertex2i(0, height);
			glVertex2i(width, height);
			glVertex2i(width, 0);
	glEnd();
}


