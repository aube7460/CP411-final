/*
 * TreeTrunk.hpp
 *
 *  Created on: Nov 29, 2016
 *      Author: jason
 */

#ifndef TREETRUNK_HPP_
#define TREETRUNK_HPP_

#include <GL/glut.h>
#include "../Camera.hpp"
#include "../Shape.hpp"

class TreeTrunk:public Shape{
protected:
	GLfloat vertex[8][3];
	GLint face[6][4];
	GLfloat treeTrunk_face_norm_mc[6][4];
public:
	GLuint textureID;
	TreeTrunk();
	void draw_face(int);
	void draw();
};

#endif /* TREETRUNK_HPP_ */
