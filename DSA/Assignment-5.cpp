#include <iostream>
#include <vector>
using namespace std;

class node{
public:
	int data;
	node *left, *right;

	node(int d=-1){
		data = d;
		left = right = nullptr;
	}
};

class BST{
	node *root, *xorder;
	int count;
	vector<vector<int>> disp;
public:
	BST(){
		root = nullptr;
		count = 0;
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
		if(i>height) height = i;
		count ++;
	}
	
	int* inOrder(node*curr=nullptr, bool first=true){
		if(first){
			curr = root;
			xorder = nullptr;
			xorder = new int [count+3];
			xorder[1] = xorder[count+2] = new node;
			xorder[0] = 1;
		}
		if (curr==nullptr) return nullptr;
		
		inOrder(curr->left, false);
		xorder[++xorder[0]] = curr;
		inOrder(curr->right, false);
		
		return xorder;
	}
	
	void convert(){
		this->inOrder();
		for(int i = 2; i<xorder[0]+2; i++){
			if(xorder[i]->left==nullptr) xorder[i]->left = xorder[i-1];
			if(xorder[i]->right==nullptr) xorder[i]->right = xorder[i-1];
		}
	}
	
	void display(){
		
	}
};

int main(){
	int choice;
	Tree t;
	while(true){
		cout<<"(1) - Add.\n"
			  "(2) - Convert to threaded binary tree.\n"
			  "(3) - Exit.\n"
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
			cout<<"Exiting...\n";
		}
	}
}
