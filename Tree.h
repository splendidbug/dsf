/** Tree.h
 *
 *  Created on: 10-Jan-2020
 *      Author: dsfle-9
 */
#include <iostream>
using namespace std;
#include "node.h"
#ifndef TREE_H_
#define TREE_H_

class Tree {
	node *root;
public:
	Tree();
	void preorder(node*);
	void postorder(node*);
	void inorder(node*);
	void non_rec_preorder(node*);
	void non_rec_inorder(node*);
	void non_rec_postorder(node*);
	node* build(string exp);
	virtual ~Tree();
};

#endif /* TREE_H_ */
