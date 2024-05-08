#include <iostream>
#include <vector>
using namespace std;

class node{
public:
	int data;
	node *left, *right;

	node(int d=-999){
		data = d;
		left = right = nullptr;
	}
};

class BST{
	node *root, **xorder;
	int count,index, iterations, *inorder;
	bool threaded;
public:
	BST(){
		root = nullptr;
		count = 0;
		threaded = false;
	}

	void add(int data){
		if(root == nullptr){
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

	void thread(node*curr=nullptr, bool first=true){
		if(first){
			curr = root;
			index = 1;
			xorder = new node* [count+3];
			xorder[0] = xorder[count+2] = new node(-999);
			iterations = 0;
		}
		if (curr==nullptr) return;
		iterations ++;
		thread(curr->left, false);
		xorder[index++] = curr;
		thread(curr->right, false);
	}

	void inOrder(node*curr=nullptr, bool first=true){
		if(first){
			curr = root;
			inorder = new int[count+1];
			inorder[0] = 0;
		}
		if(curr==nullptr) return;
		iterations ++;
		inOrder(curr->left, false);
		inorder[++inorder[0]] = curr->data;
		inOrder(curr->right, false);
	}


	void convert(){
		this->thread();
		for(int i = 1; i<count+2; i++){
			if(xorder[i]->left==nullptr) xorder[i]->left = xorder[i-1];
			if(xorder[i]->right==nullptr) xorder[i]->right = xorder[i+1];
		}
		threaded = true;
	}

	void display(){
		if(!threaded){
			this->inOrder();
			cout<<"Before threading:\n    Inorder traversal: ";
			for(int i = 1; i<=inorder[0]; i++) cout<<inorder[i]<<' ';
		}

		else{
			iterations = 0;
			node* curr = root;
			int prev = -999;
			while(true){
				while(curr->left->data!=prev) curr = curr->left;
				cout<<curr->data<<' ';
				curr = curr->right;
				if(curr->data==-999) break;
				cout<<curr->data<<' ';
				prev = curr->data;
				curr = curr->right;
				iterations ++;
			}
		}
		cout<<"\n\nIterations: "<<iterations<<endl;
	}
};

int main(){
	int choice;
	BST t;
	while(true){
		cout<<"\n\n================ MENU ==================\n"
			  "(1) - Add.\n"
			  "(2) - Convert to threaded binary tree.\n"
			  "(3) - Display.\n"
			  "(4) - Exit.\n"
			  "\nEnter your choice: "; cin>>choice;

		switch(choice){
		case 1:{
			int d;
			cout<<"Enter the value: "; cin>>d;
			t.add(d);
			break;
		}

		case 2:
			t.convert();
			break;
		case 3:
			t.display();
			break;
		case 4:
			cout<<"Exiting...\n";
			return 0;
		}
	}
}
