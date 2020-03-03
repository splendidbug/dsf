//============================================================================
// Name        : Exp4tree.cpp
// Author      : saurabh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "node.h"
#include "Tree.h"

using namespace std;

void menu()
{
	cout<<"1.Inorder"<<endl;
	cout<<"2.Preorder"<<endl;
	cout<<"3.Postorder"<<endl;
	cout<<"4.Exit"<<endl;
	cout<<"Select option:";
}

int main()
{
	int opt;
	string exp;
	cout<<"Expression:";
	cin>>exp;
	Tree t;
	node* root=t.build(exp);
	while(1)
	{
		menu();
		cin>>opt;
		switch(opt)
		{
		case 1:
			cout<<"RECURSIVE:";
			t.inorder(root);
			cout<<endl;
			cout<<"NON-RECURSIVE:";
			t.non_rec_inorder(root);
			cout<<endl;
			break;
		case 2:
			cout<<"RECURSIVE:";
			t.preorder(root);
			cout<<endl;
			cout<<"NON-RECURSIVE:";
			t.non_rec_preorder(root);
			cout<<endl;
			break;
		case 3:
			cout<<"RECURSIVE:";
			t.postorder(root);
			cout<<endl;
			cout<<"NON-RECURSIVE:";
			t.non_rec_postorder(root);
			cout<<endl;
			break;
		case 4:
			return 0;
		}
	}
}
