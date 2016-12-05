/*
 * Tree.cpp
 *
 *  Created on: Nov 29, 2016
 *      Author: jason
 */

#include "Tree.hpp"

Tree::Tree() {
	myTrunk = new TreeTrunk();
	myBody = new TreeBody();
	myBody->translate(0, 0.25, 0);
}

void Tree::draw() {
	myTrunk->scale_change(s);
	myBody->scale_change(s);
	glPushMatrix();
	this->ctm_multiply();
	myTrunk->draw();
	myBody->draw();
	glPopMatrix();
}
