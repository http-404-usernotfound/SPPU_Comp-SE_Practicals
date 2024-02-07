#include <iostream>
using namespace std;

class node{
	int data;
	node *left, *right;
public:
	node(int d=NULL, node* l=NULL, node* r=NULL){
		data = d;
		left = l;
		right = r;
	}
};

class BST{
	node*root;
	int count, height;
public:
	BST(){
		root = NULL;
		count = height = 0;
	}

	void add(int data){
		node* curr = root;
		int i = 0;
		while(curr->data!=NULL){
			if(data>root->data)
				curr = curr->right;
			else
				curr = curr->left;
			i++;
		}
		curr = new node(data);
		if(i>height) height = i;
	}

	int search(int data){
		node* curr = root;
		int i = 0;
		while(curr->data!=NULL){
			if(data>root->data)
				curr = curr->right;
			else
				curr = curr->left;

			if(curr->data == data) return i;
			i++;
		}
		return -1;
	}

	int getHeight(){
		return height;
	}

	void preOrder(node*rt=root){
		node *curr = rt;
		if(!curr) return;

		cout<<curr->data<<' ';

		preOrder(curr->left);
		preOrder(curr->right);
	}

	void postOrder(node*rt=root){
		node *curr = rt;
		if(!curr) return;

		postOrder(curr->left);
		cout<<curr->data<<' ';
		postOrder(curr->right);
	}

	void inOrder(node*rt=root){
		node *curr = rt;
		if(!curr) return;

		inOrder(curr->left);
		cout<<curr->data<<' ';
		inOrder(curr->right);
	}

	int minimum(){
		node* curr = root;

		while(!curr) curr = curr->left;

		return curr->data;
	}

	BST mirror(){
		BST mirr(root);
		return mirr;
	}

	void display(){

	}
};

int main() {
	int choice;
	BST bst;
	while(true){
		cout<<"(1) - Insert.\n"
			  "(2) - Search.\n"
			  "(3) - Height.\n"
			  "(4) - Pre-Order.\n"
			  "(5) - Post-Order.\n"
			  "(6) - In-Order.\n"
			  "(7) - Minimum.\n"
			  "(8) - Mirror.\n"
			  "(9) - Display.\n"
			  "(10) - Exit.\n"
			  "\nEnter your choice: ";cin>>choice;

		switch(choice){
		case 1:
			int data;
			cout<<"Enter element: "; cin>>data;
			bst.add(data);
			break;

		case 2:
			int data;
			cout<<"Enter element: "; cin>>data;
			int h = bst.search(data);
			if(h>-1) cout<<"Element found at height: "<<h<<endl;
			else cout<<"Element not found :(\n";
			break;

		case 3:
			int h = bst.getHeight();
			cout<<"\nHeigth is "<<h<<endl;
			break;

		case 4:
			bst.preOrder();
			break;

		case 5:
			bst.postOrder();
			break;

		case 6:
			bst.inOrder();
			break;

		case 7:
			int mini = bst.minimum();
			cout<<"Minimum is "<<bst.minimum<<endl<<endl;
			break;

		case 8:
			BST mirr;

			break;

		case 9:
			bst.display();
			break;

		case 10:
			cout<<"Exiting...\n";
			return 0;
		}
	}
}
