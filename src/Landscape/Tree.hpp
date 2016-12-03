/*
 * Tree.hpp
 *
 *  Created on: Nov 29, 2016
 *      Author: jason
 */

#ifndef TREE_HPP_
#define TREE_HPP_

#include "TreeBody.hpp"
#include "TreeTrunk.hpp"

class Tree: public Shape {

public:
	TreeTrunk* myTrunk; // body of the tree
	TreeBody* myBody; // trunk of the tree
	Tree();
	void draw();
};

#endif /* TREE_HPP_ */
