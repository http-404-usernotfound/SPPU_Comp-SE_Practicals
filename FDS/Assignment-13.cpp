#include<iostream>

using namespace std;

#define MAX 5

class queue{
	int front, rear, count, orders[MAX];
	
  public:
	queue(){
		front = 0;
		rear = -1;
		count = 0;
	}
	
	void add(int o){
		if(count == MAX) throw runtime_error("Queue is FULL!");
		
		if(rear == MAX-1) rear = -1;
		
		orders[++rear] = o;
		count++;
	}
	
	int del(){
		if(!count) throw runtime_error("Queue is EMPTY!");
		if(front == MAX) front = 0;
		count--;
		return orders[front++];
	}
	
	void display(){
		int i;
		for(i = front; i!=rear; i++){
			if(i == MAX) i = 0;
			cout<<orders[i]<<" ";
		}
		cout<<orders[i]<<endl<<endl;
	}
};

int main(){
	int choice, order;
	queue orderList;
	
	while(true){
		cout<<"=======MENU=======\n"
			  "(1) - Add Order.\n"
			  "(2) - Delete Order.\n"
			  "(3) - Display Orders.\n"
			  "(4) - Exit.\n"
			  "\nEnter your choice: "; cin>>choice;
			  
		switch(choice){
		case 1:
			cout<<"Enter order no.: "; cin>>order;
			try{
			orderList.add(order);
			} catch(runtime_error &e){
				cout<<"Error: "<<e.what()<<endl;
			}
			break;
		case 2:
			try{
			cout<<"Job deleted: "<<orderList.del()<<endl;
			} catch(runtime_error &e){
				cout<<"Error: "<<e.what()<<endl;
			}
			break;
		case 3:
			cout<<"The order list is: ";
			orderList.display();
			break;
		case 4:
			cout<<"Exiting...\n";
			return 0;
		}
		if(choice > 4) cout<<"Enter a valid option!\n";
	}
	
}
