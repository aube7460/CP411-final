/*
 * background.hpp
 *
 *  Created on: Nov 29, 2016
 *      Author: jason
 */

#ifndef BACKGROUND_HPP_
#define BACKGROUND_HPP_

#include <GL/glut.h>

class Background{
public:
	GLint textureSkyID;
	GLint textureGroundID;
	Background();
	void drawSky(int width,int height);
	void drawGround(int width,int height);
};

#endif /* BACKGROUND_HPP_ */
