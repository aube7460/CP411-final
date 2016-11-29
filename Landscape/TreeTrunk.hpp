/*
 * Tree.hpp
 *
 *  Created on: Nov 29, 2016
 *      Author: jason
 */

#ifndef TREETRUNK_HPP_
#define TREETRUNK_HPP_

#include <GL/glut.h>
#include "Shape.hpp"

class TreeTrunk:public Shape{
protected:
	GLfloat vertex[8][3];
	GLint face[6][4];
	GLfloat treeTrunk_face_norm_wc[6][4];
	GLfloat treeTrunk_face_norm_mc[6][4];
public:
	TreeTrunk();
	void draw_face(int);
	void draw();
	bool isBackface(int);
	GLfloat getFaceShade(int);
	void setTextureID(int,int);
};

#endif /* TREE_HPP_ */
