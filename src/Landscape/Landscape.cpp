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
}

void Landscape::draw_landscape(){
	list[0]->draw();
	list[1]->draw();
}

void Landscape::reset_landscape(){
	list[0] -> reset();
	list[1] -> reset();
}

