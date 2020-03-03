#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
class node
{
	node *left;
	node *right;
	int data;
public:
	node()
	{
		left=NULL;
		right=NULL;
	}
	friend class tree;
};
class tree
{
	node *root;
public:
	tree()
	{
			
		root=NULL;
	}
	
	node *insert(node *root)
	{
		node *temp=new node;
		node *nev;
		int pos;
		cout<<"Enter the data"<<endl;
		cin>>temp->data;
		if(root==NULL)
		{
			root=temp;
			nev=root;
		}
		
		else
		{
			nev=root;
			while(1)
			{
				cout<<"Enter 1 for left position and 2 for right position"<<endl;
				cin>>pos;
				if(pos==1)
				{
					if(root->left==NULL)
					{
						root->left=temp;
						break;
					}
					else if(root->left!=NULL)
					{
						
						root=root->left;
						continue;
					}
				}
				else if(pos==2)
				{
					if(root->right==NULL)
					{
						root->right=temp;
						break;
					}
					else if(root->right!=NULL)
					{
						root=root->right;
						continue;
					}
				}
			}
			root=nev;
		}
		return root;
	}
	node *nev(int key)
	{
		node *temp=new node;
		temp->data=key;
		root=temp;
		return temp;
	}	
	node *recursiveInsert(node *root,int key)
	{
		int pos;
		node *temp;
		if(root==NULL)
		{
			temp = nev(key);
			return temp;
			
		}
		else
		{
			cout<<"Enter 1 for left position and 2 for right position"<<endl;
			cin>>pos;
			if(pos==1)
			{
				root->left=recursiveInsert(root->left,key);
			}
			else if(pos==2)
			{
				root->right=recursiveInsert(root->right,key);
			}
		}
		return root;
	}
			
		
	node * display(node * root1)
	{
		node *temp;
		node *stack1[20];
		int top;
		temp=root1;
		
		stack1[top]=NULL;
	check:	while(temp!=NULL)
		{
			top=top+1;
			stack1[top]=temp;
			temp=temp->left;
		}
		temp=stack1[top];
		top=top-1;
		while(temp!=NULL)
		{
			cout<<temp->data<<"   ";
			if(temp->right!=NULL)
			{
				temp=temp->right;
				goto check;
			}
			temp=stack1[top];
			top=top-1;
		}
		cout<<endl;
		return root1;
	}
	void recursiveDisplay(node *root)
	{
		if(root)
		{
			recursiveDisplay(root->left);
			cout<<root->data<<"   ";
			recursiveDisplay(root->right);
		}
	}
	int depth(node *root)
	{
		int c;
		if(root==NULL)
		{
			return 0;
		}
		else if(root->left==NULL&&root->right==NULL)
		{
			return 1;
		}
		else
		{
			int a=depth(root->left);
			int b=depth(root->right);
			if(a>b)
			{
				c=1+a;
				return c;
			}
			else
			{
				c=1+b;
				return c;
			}
		}
	}

	node * displayLeaf(node *root1){
		node *temp;
		node *stack1[20];
		int top;
		temp=root1;
		
		stack1[top]=NULL;
	check:	while(temp!=NULL)
		{
			top=top+1;
			stack1[top]=temp;
			temp=temp->left;
		}
		temp=stack1[top];
		top=top-1;
		while(temp!=NULL)
		{	if(temp->left==NULL&&temp->right==NULL)
			cout<<temp->data<<"   ";
			if(temp->right!=NULL)
			{
				temp=temp->right;
				goto check;
			}
			temp=stack1[top];
			top=top-1;
		}
		cout<<endl;
		return root1;
	}


	node* copy(node *t1,node *t2)
	{
		if(t1==NULL)
			t2=NULL;
		else
		{
			t2=new node;
			t2->data=t1->data;
			t2->left=t2->right=NULL;
			t2->left=copy(t1->left,t2->left);
			t2->right=copy(t1->right,t2->right);
		}
		return t2;
	}	
};
int main()
{
	tree z;
	int t, s1,d,num;
	node *p, *p1,*root1, *copyRoot;
	p=NULL;
	while(1)
	{
		cout<<"Enter the following indices to perform respective operations\n1) Insert a node\n2) Depth\n3) Display\n 4) Copy a binary tree\n5) Insert a node (recursive)\n6) Display (recursive)\n7) Display the leaf nodes\n";
		
		cin>>s1;
		switch(s1)
		{
			case 1:p=z.insert(p);
				break;
                	case 2:d=z.depth(p);
                		cout<<"Depth= "<<d<<endl;
				break;
		        case 3:p=z.display(p);
		                break;
		        case 4:p1=z.copy(p,p1);

				cout<<"The copied tree is:\n";
				z.display(p1);
		                break;
				
		        case 5:cout<<"Enter the data"<<endl; //recursive insertions
		        	cin>>num;
		        	p=z.recursiveInsert(p,num);
		        	break;
		        case 6:z.recursiveDisplay(p); //recursive display
		                break;
				
			case 7:p=z.displayLeaf(p);
		                break;
			
		}
		cout<<"Enter 1 to continue, 0 to terminate"<<endl;
		cin>>t;
		if(t)
		continue;
		else
		break;
	}
}
	
			
		

