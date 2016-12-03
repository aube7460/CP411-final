/*
 * TreeBody.hpp
 *
 *  Created on: Nov 29, 2016
 *      Author: jason
 */

#ifndef TREEBODY_HPP_
#define TREEBODY_HPP_

#include <GL/glut.h>
#include "../Shape.hpp"

class TreeBody: public Shape{
protected:
	GLfloat vertex[5][3];
	GLint face[4][3];
	GLfloat treeBody_face_norm_mc[4][3];

public:
	GLuint textureID;
	TreeBody();
	void draw_face(int);
	void draw();
	bool isBackface(int);
};

#endif /* TREEBODY_HPP_ */
