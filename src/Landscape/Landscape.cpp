/*
 * Landscape.cpp
 *
 *  Created on: Nov 29, 2016
 *      Author: jason
 */

#include "Landscape.hpp"

Landscape::Landscape(){
	list[0] = new Sun();
}

Landscape::~Landscape(){
	delete list[0];
	delete list[1];
	delete list[2];
	delete list[3];
}

void Landscape::draw_landscape(){
	list[0]->draw();
	list[1]->draw();
	list[2]->draw();
	list[3]->draw();
}

void Landscape::reset_landscape(){
	list[0] -> reset();
	list[1] -> reset();
	list[2] -> reset();
	list[3] -> reset();
}

