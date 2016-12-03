/*
 * Landscape.hpp
 *
 *  Created on: Nov 29, 2016
 *      Author: jason
 */

#ifndef LANDSCAPE_HPP_
#define LANDSCAPE_HPP_

#include "TreeBody.hpp"
#include "TreeTrunk.hpp"
#include "Tree.hpp"
#include "Sun.hpp"

class Landscape {
public:
	Shape* list[4];
	Landscape();
	~Landscape();
	void draw_landscape();
	void reset_landscape();
};

#endif /* LANDSCAPE_HPP_ */
