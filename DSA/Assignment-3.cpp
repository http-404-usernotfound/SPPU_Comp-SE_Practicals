#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* left, *right;
	node(int d){
		data = d;
		left = right = nullptr;
	}
};

class Tree{
	node* root;
	int count;
public:
	Tree(){
		root = nullptr;
		count = 0;
	}

	void add(int data){
		if(root==nullptr){
			root = new node(data);
			return;
		}
		bool right;
		node* curr = root;
		node* parent;
		int i = 0;
		while(curr!=nullptr){
			parent = curr;
			right = false;
			if(data>curr->data){
				curr = curr->right;
				right = true;
			}
			else
				curr = curr->left;
			i++;
		}
		curr = new node(data);
		if(right) parent->right = curr;
		else parent->left = curr;
		count ++;
	}

	int dlt(int data){
		node* curr = root;
		int i = 0;
		while(curr!=nullptr){
			if(curr->data == data) curr = nullptr;
			if(data>curr->data)
				curr = curr->right;
			else
				curr = curr->left;
			i++;
		}
		return -1;
	}

	int search(int data){
		node* curr = root;
		int i = 0;
		while(curr!=nullptr){
			if(curr->data == data) return i;
			if(data>curr->data)
				curr = curr->right;
			else
				curr = curr->left;
			i++;
		}
		return -1;
	}

	void display(){
		//Like display function of assignment 4		  
		
	}


};

int main(){
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
		case 1:{
			int d;
			cout<<"Enter the value: "; cin>>d;
			t.add(d);
			break;
		}
		case 2:{
			int d;
			cout<<"Enter value: "; cin>>d;
			t.dlt(d);
			break;
		}

		case 3:{
			int d;
			cout<<"Enter value: "; cin>>d;
			int lvl = t.search(d);
			if(lvl>-1) cout<<"\nThe value was found at level: "<<lvl<<endl;
			else cout<<"\nValue not found :(\n";
			break;
		}

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
