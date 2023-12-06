#include <iostream>
using namespace std;
#define MAX 5

class queue{
	
	int a[MAX],front,rear;
public:
	queue(){
		rear = -1;
		front = 0;
	}
	
	void add(int);
	int del();
	int isEmpty();
	int peek();
	void display();
};

void queue::add(int j){

	if(rear != MAX-1) a[++rear] = j;
	
	else throw runtime_error("Queue is FULL!");
}

int queue::del(){
	if(this->isEmpty()) throw runtime_error("Queue is Empty!");	
	
	int t = a[front];
	for(int i = 0; i < rear; i++) a[i] = a[i+1];
	rear--;
	return t;
}

int queue::isEmpty(){
	return rear==-1;
}

int queue::peek(){
	return a[front];
}

void queue::display(){
	cout<<"The Queue is:";
	for(int i = 0; i <= rear; i++) cout<<" "<<a[i];
	cout<<endl;
}

int main(){
	queue q;	
	
	int choice, element;
	while(true){
		
		cout<<"===========MENU===========\n"
			  "(1) - Enqueue.\n"
			  "(2) - Dequeue\n"
			  "(3) - Peek.\n"
			  "(4) - Display.\n"
			  "(5) - Exit.\n"
			  "\nEnter your choice: "; cin>>choice;
		
		switch(choice){
		case 1:
			cout<<"\nEnter the element: "; cin>>element;
			try{
			q.add(element);
			} catch(runtime_error &e){
				cerr<<"Error: "<<e.what()<<endl;
			}
			break;
		case 2:
			try{
			cout<<"Element deleted: "<<q.del()<<endl;
			}catch(runtime_error &e){
				cerr<<"Error: "<<e.what()<<endl;
			}
			break;
		case 3:
			cout<<"First element: "<<q.peek()<<endl;
			break;
		case 4:
			q.display();
			break;
		case 5:
			cout<<"Exiting...\n";
			return 0;
		if(choice > 5) cout<<"Enter a valid input!\n";
		}
	}
}
