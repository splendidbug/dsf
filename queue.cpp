/*
 * queue.cpp
 *
 *  Created on: 06-Jan-2020
 *      Author: dsflh-9
 */

#include "queue.h"
#include <iostream>
#include <string.h>

//#include <bits/stdc++.h>
using namespace std;
queue::queue()
{
	rear = new node;
	front = new node;
	rear = NULL;
	front= NULL;
}
void queue:: enqueue(){
	 node *temp = new node;
	      string nameDOBCity;
	      int age1 ;

			cout<<"Please enter the name"<<endl;

	//		while(1){
			  cin>>nameDOBCity;

	//		  for(int i=0;i<nameDOBCity.length();i++)
	//		   if(isdigit(nameDOBCity[0]))
	//		  {
		//		  cout<<"Please enter name in correct format"<<endl;
		//		  continue;
		//	  }
		//	  break;
			  temp->name = nameDOBCity;
		//}
	    cout<<"PLease enter the date of birth"<<endl;
	    cin>>nameDOBCity;
	      fflush(stdin);

	    temp->dob = nameDOBCity;

	    cout<<"Please enter the age"<<endl;
	    cin>>age1;
	    temp->age = age1;
	    cout<<"Please enter the city"<<endl;
   	    cin>>nameDOBCity;
   	    temp->city = nameDOBCity;

   	 cout<<"Please enter the solemnity of the situation"<<endl;
   	   	    cin>>age1;
   	   	    temp->priority = age1;

	    if (rear == NULL) {

	      rear=temp;
	        // cout<<"aal is well"<<endl;
 	    	front=rear;
 	    	rear->next=NULL;
	   }
	    else{
	    	if(temp->priority>rear->priority)
	    	sort(temp);
	    	else{	rear ->next = temp;
	    	temp->next=NULL;
	    	rear=temp;
	    	}
	         //cout<<"aal is well"<<endl;
	    }
}


void queue:: dequeue(){
	int c;
	if(front==NULL)
		cout<<"Stack Underflow"<<endl;
	else{
		cout<<"released patient:\n"<<"name:\t"<<front->name<<endl<<"Date of Birth:\t"<<front->dob<<endl<<"age:\t"<<front->age<<endl<<"city:\t"<<front->city<<endl;
		if(front != rear)
			front = front->next;

		else{
				front = NULL;
				rear = NULL;
			}
	}

	node*temp=new node;
	temp=front;
	while(temp!=NULL){
		cout<<endl<<"remaining patients:\n"<<"name:\t"<<temp->name<<endl<<"Date of Birth:\t"<<temp->dob<<endl<<"age:\t"<<temp->age<<endl<<"city:\t"<<temp->city<<endl;
		temp=temp->next;
	}

}

void queue::sort(node *t){
	node *traverse;
	traverse = front;

	while(1){
		if(front==rear){
			front = t;
			front->next=rear;
			break;
		}
		else if(front->priority<=t->priority){
			t->next=front;
			front = t;
			break;
		}
		else if(traverse->next->priority<=t->priority){
			t->next=traverse->next;
			traverse->next = t;
			traverse=t;
			break;
		}
		else{
			traverse=traverse->next;
		}
	}
}


