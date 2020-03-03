//============================================================================
// Name        : ass2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "queue.h"
#include "hospital.h"
using namespace std;
class hospital {

	queue q;
public:
	void admit();
	void release();
};
void hospital::admit(){
	q.enqueue();
}
void hospital::release(){
	q.dequeue();
}

int main() {
	hospital h;
	int s1,t;
	while(1){
			cout<<"Please enter the following indices to perform respective operations\n1) admit the patient\n2) release the patient"<<endl;
			cin>>s1;
			switch(s1){

				case 1:
					h.admit();
					break;
				case 2:
					h.release();
					break;

			}
			cout<<"Enter 1 to continue, 0 to terminate"<<endl;
			cin>>t;
			if(!t)
				break;
	}

return 0;
}
