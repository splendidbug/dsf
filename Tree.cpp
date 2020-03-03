/*
 * Tree.cpp
 *
 *  Created on: 10-Jan-2020
 *      Author: dsfle-9
 */

#include "Tree.h"
#include <iostream>
#include<stack>
using namespace std;
Tree::Tree() {
	// TODO Auto-generated constructor stub
	root=0;
}

Tree::~Tree() {
	// TODO Auto-generated destructor stub
}

bool isoperand(char c)
{
	return (c>='a' && c<='z');
}

bool isoperator(char c)
{
	return (c=='+' || c=='*' || c=='-' || c=='/');
}

node* Tree::build(string exp)
{
	stack<node*> s;

	for(int i=0;i<exp.length();i++)
	{
		node* temp=new node;
		if(isoperand(exp[i]))
		{
			temp->data=exp[i];
			s.push(temp);
		}
		else if(isoperator(exp[i]))
		{
			node* t1=s.top();
			s.pop();

			node* t2=s.top();
			s.pop();

			//node* temp=new node;
			temp->data=exp[i];
			temp->right=t1;
			temp->left=t2;
			s.push(temp);
		}
	}
	root=s.top();
	return root;
}

void Tree::non_rec_preorder(node* r)
{
	stack<node*> s;
	s.push(r);

	while(!s.empty())
	{
		node* temp=s.top();
		s.pop();

		while(temp)
		{
			cout<<temp->data<<" ";
			if(temp->right)
				s.push(temp->right);
			temp=temp->left;
		}
	}
}

void Tree::non_rec_inorder(node* r)
{
	node* temp=r;
	stack<node*> s;

	while(temp)
	{
		s.push(temp);
		temp=temp->left;
	}

	while(!s.empty())
	{
		temp=s.top();
		s.pop();
		cout<<temp->data<<" ";
		if(temp->right!=NULL){
			temp=temp->right;
		while(temp)
			{
				s.push(temp);
				temp=temp->left;
			}
		}
	}

}

void Tree::non_rec_postorder(node* r)
{
	stack<node*> s1,s2;
	s1.push(r);

	while(!s1.empty())
	{
		node* temp=s1.top();
		s1.pop();
		if(temp)
			s2.push(temp);
		if(temp->right)
			s1.push(temp->left);
		if(temp->left)
			s1.push(temp->right);
	}
	while(!s2.empty())
	{
		node* temp=s2.top();
		cout<<temp->data<<" ";
		s2.pop();
	}
}

void Tree::preorder(node* r)
{
	node* temp=r;
	if(r==0)
		return;

	cout<<temp->data<<" ";
	preorder(temp->left);
	preorder(temp->right);
}

void Tree::postorder(node* r)
{
	node* temp=r;
	if(r==0)
		return;

	postorder(temp->left);
	postorder(temp->right);
	cout<<temp->data<<" ";
}

void Tree::inorder(node* r)
{
	node* temp=r;
	if(r==0)
		return;

	inorder(temp->left);
	cout<<temp->data<<" ";
	inorder(temp->right);
}
