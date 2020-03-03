/*
 * queue.h
 *
 *  Created on: 06-Jan-2020
 *      Author: dsflh-9
 */

#ifndef QUEUE_H_
#define QUEUE_H_
//#include "node.h"
#include <iostream>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;
class queue;
class node {
	string name ;
	string city;
	string dob;
	int age;

	int priority;
	node *next;
public:
	friend class queue;

};

class queue {

	node *front;
	node *rear;

public:
	//friend class node;

void enqueue();
queue();
void dequeue();
void sort(node *t);
};

#endif /* QUEUE_H_ */
