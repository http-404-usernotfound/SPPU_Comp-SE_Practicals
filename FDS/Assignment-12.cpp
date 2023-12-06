#include <iostream>
using namespace std;

#define MAX 10

class doubleQueue{
	int a[MAX], front, rear, count;

public:
	doubleQueue(){
		front = rear = -1;
		count = 0;
		for(int i = 0; i<MAX; i++) a[i] = '\0';
	}

	void enqueueFront(int n){
		if (count == MAX){
			throw runtime_error("Queue is FULL");
		}
		if(a[front+1]!='\0')
			for(int i = rear; i>front; i--)
				a[i+1] = a[i];

		a[++front] = n;
		rear++;
		count++;
	}

	void enqueueRear(int n){
		if (count == MAX){
			throw runtime_error("Queue is FULL");
		}
		a[++rear] = n;
		count++;
	}

	int dequeueFront(){
		if(!count){
			cout<<"Queue is EMPTY!\n";
			return'\0';
		}
		
		int t = a[0];
		for(int i = 0; i<rear;i++) a[i] = a[i+1];
		front--;
		a[rear--] = '\0';
		count--;
		return t;
	}

	int dequeueRear(){
		if(!count || rear == front){
			cout<<"Rear Queue is EMPTY!\n";
			return '\0';
		}

		int r = a[front+1];
		for(int i = front+1; i<=rear;i++) a[i] = a[i+1];
		
		a[rear--] = '\0';
		count--;
		
		return r;
	}

	void display(){
		cout<<"The Queue is:";
		for(int i = 0; i<count; i++) cout<<" "<<a[i];
		cout<<endl<<endl;;
	}
};

int main() {
	int choice, elmnt;
	doubleQueue dq;

	while(choice != 6){
		cout<<"(1) - Push at front\n"
			  "(2) - Push at rear\n"
			  "(3) - Pop from front\n"
			  "(4) - Pop from rear\n"
			  "(5) - Display\n"
			  "(6) - Exit\n"
			  "\n Enter your choice: "; cin>> choice;
		switch(choice){
		case 1:
			cout<<"Enter value to push: "; cin>>elmnt;
			try{
			dq.enqueueFront(elmnt);
			}catch(runtime_error &e){
				cout<<"Error: "<<e.what()<<endl;
			}
			break;

		case 2:
			cout<<"Enter value to push: "; cin>>elmnt;
			try{
			dq.enqueueRear(elmnt);
			}catch(runtime_error &e){
				cout<<"Error: "<<e.what()<<endl;
			}
			break;

		case 3:
			elmnt = dq.dequeueFront();
			cout<<"Value: "<<elmnt<<endl<<endl;
			break;

		case 4:
			elmnt = dq.dequeueRear();
			cout<<"Value: "<<elmnt<<endl<<endl;
			break;

		case 5:
			dq.display();
			break;

		case 6:
			cout<<"Exiting...\n";
			return 0;
		}

		if(choice>6)cout<<"Enter a valid option!\n";
	}

}
