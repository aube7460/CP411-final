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
protected:
	GLint x1,x2,y1,y2;
public:
	void draw(int,int);
};

#endif /* BACKGROUND_HPP_ */
