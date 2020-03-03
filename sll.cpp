#include<iostream>
#include<string>
#include <algorithm>

using namespace std;

class node{
public:
	char data;
	node *next;

};

class stack{
	node *top;
	public:
	
	stack(){
			top = new node;
			top = NULL;
	}
	void push(char c){
			
			node *temp = new node;
			temp->data=c;
			temp->next = top;
			top = temp;		
	}
	void empty(){
		while(top!=NULL)
			pop();

	}
	
	char pop(){
			char c;
			if(top==NULL)
			cout<<"Stack underflow"<<endl;
			else
			{
				//cout<<top->data<<endl;
				c = top->data;
				top = top->next;
				return c;		
			}
	}
	bool isEmpty(){
			if(top==NULL)
			return true;
			else
			return false;
	}

};



class conversion{
	public:
	string infixToPostfix(stack s, string str){ 
			//cout<<"Please enter an infix expression"<<endl;
			string  exp="";
			//cin>>str;							
			s.push('(');
			str += ')';
			for(int i=0;i<str.length();i++){


				switch(str[i]){
						case '(':
							s.push(str[i]);
							break;
						case 'a':
							exp+='a';
							break;
						case 'b':
							exp+='b';
							break;
						case 'c':
							exp+='c';
							break;
						case 'd':
							exp+='d';
							break;
						case 'e':
							exp+='e';
							break;
						case 'f':
							exp+='f';
							break;
						case 'h':
							exp+='h';
							break;
						case 'g':
							exp+='g';

							break;
	//a+(b*c-(d/e^f)*g)*h
						case ')':
								while(1){
										
										char c1 = s.pop();
										char c2 = s.pop();
									if(c2!='(')
									{
										exp +=c1;
										s.push(c2);
										
									}
									else
									{	exp +=c1;
										break;									
									}

							}//inCase while
								break;

					}//switch				
	
					
					 if(str[i]=='+'||str[i]=='-'||str[i]=='/'||str[i]=='^'||str[i]=='*')
							while(1){
								 
								char c1;
								c1 = s.pop();
								if(c1 == '(')
								{
									s.push(c1);
									s.push(str[i]);
									
								//	cout<<str[i]<<endl;
									break;
								}
								
								if(precedence(str[i]) > precedence(c1))
								{
									s.push(c1);
									s.push(str[i]);
								//	cout<<str[i]<<endl;
									break;
								}
							
								if(precedence(str[i]) == precedence(c1))
								{
									exp+=c1;
									//s.push(c1);
									s.push(str[i]);
								//	cout<<str[i]<<endl;
									break;
								}
									
								//check associativity}
								else
									{								
										exp += c1;
										
										//s.push(str[i]);

									//cout<<str[i]<<endl;
									}
									
							
						} // while

//cout<<exp<<endl;
			
			}//for looop
			//cout<<endl<<exp<<endl; // ans = ab+

	return exp;

	}//func.


int precedence(char c1){
	if(c1=='^') 
	return 3;
	if(c1=='/' || c1 == '*')
	return 2;
	if(c1=='+'||c1=='-')
	return 1;
		 
}

void infixToPrefix(stack s, string str){
		//cout<<"Please enter an infix expression"<<endl;
			string exp="";
			//cin>>str;
			reverse(str.begin(), str.end());

			for(int i=0;i<str.length();i++){
					if(str[i]=='(')
						{
							str[i] = ')';
							continue;
						}
					if(str[i]==')')
						{
							str[i] = '(';
							continue;
						}
					
			}	
 //(a+b^c)*d+e^f

		str = infixToPostfix(s, str);
		reverse(str.begin(), str.end());
		cout<<str<<endl;


}

};

int main(){
	stack s;
	char ch;
	conversion c;
	int t, s1;
	while(1){
			cout<<"Please enter the following indices to perform respective operations\n1) push\n2) pop\n3) is empty\n4) Empty the stack\n5) infix to post fix\n6) infix to pre fix"<<endl;
			cin>>s1;		
			switch(s1){
				case 1:
					cout<<"Please enter a character"<<endl;
					cin>>ch;
					s.push(ch);
					break;
				case 2:
					ch = s.pop();
					cout<<ch<<endl;
					break;
				case 3:
					if(s.isEmpty())
					cout<<"Yes"<<endl;
					else
					cout<<"No"<<endl;
					break;

				case 4:
					
					s.empty();	
					
				
				
				case 5:
					{string str;
					cout<<"PLease enter an infix expression"<<endl;
					cin>>str;
					cout<<c.infixToPostfix(s, str)<<endl;
					break;}
				case 6:
					string str;
					cout<<"PLease enter an infix expression"<<endl;
					cin>>str;
					c.infixToPrefix(s, str);
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
