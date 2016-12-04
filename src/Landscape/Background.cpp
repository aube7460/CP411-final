/*
 * background.cpp
 *
 *  Created on: Nov 29, 2016
 *      Author: jason
 */

#include "Background.hpp"

Background::Background(){
	textureSkyID = 0;
	textureGroundID = 0;
}

void Background::drawSky(int winWidth, int winHeight){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,textureSkyID);
	glBegin(GL_LINE_LOOP);
		glTexCoord2f(0.0,0.0); glVertex2i(-winWidth,0);
		glTexCoord2f(1.0,0.0); glVertex2i(-winWidth,winHeight);
		glTexCoord2f(1.0,1.0); glVertex2i(winWidth, winHeight);
		glTexCoord2f(0.0,1.0); glVertex2i(winWidth, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Background::drawGround(int winWidth, int winHeight){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,textureGroundID);
	glBegin(GL_QUADS);
		glTexCoord2i(0,0); glVertex2i(-winWidth, -winHeight);
		glTexCoord2i(1,0); glVertex2i(-winWidth,0);
		glTexCoord2i(1,1); glVertex2i(winWidth, 0);
		glTexCoord2i(0,1); glVertex2i(winWidth, -winHeight);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
