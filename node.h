/*
 * node.h
 *
 *  Created on: 10-Jan-2020
 *      Author: dsfle-9
 */

#ifndef NODE_H_
#define NODE_H_

class node {
private:

	char data;
	node* left;
	node* right;
public:
	friend class Tree;
	node();
	virtual ~node();
};

#endif /* NODE_H_ */
