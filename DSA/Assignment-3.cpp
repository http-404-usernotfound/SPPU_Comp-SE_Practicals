#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* left, *right;
	node(int d, node*l, node*r){
		data = d;
		left = l;
		right = r;
	}
};

class Tree{
	node* root;
	int count;
	Tree(){
		root = NULL;
		count = 0;
	}

	void add(int data){
		if(!root){
			root = new node(data);
			return;
		}
	}

	void dlt(int data){
	}

	int search(int data){
	}

	void display(){
	}


};

in main(){
	int choice;
	Tree t;
	while(true){
		cout<<"(1) - Add.\n"
			  "(2) - Delete.\n"
			  "(3) - Search.\n"
			  "(4) - Display.\n"
			  "(5) - Exit.\n"
			  "\nEnter your choice: "; cin>>choice;

		switch(choice){
		case 1:
			int d;
			cout<<"Enter the value: "; cin>>d
			t.add(d);
			break;

		
		case 2:
			int d;
			cout<<"Enter value: "; cin>>d;
			t.dlt(d);
			break;

		case 3:
			int d;
			cout<<"Enter value: "; cin>>d;
			int lvl = t.search(d);
			if(lvl>-1) cout<<"\nThe value was found at level: "<<lvl<<endl;
			else cout<<"\nValue not found :(\n";
			break;

		case 4:
			t.display();
			break;

		case 5:
			cout<<"\nExtiting...\n";
			return 0;
		}	
	}
	return 0;
}
