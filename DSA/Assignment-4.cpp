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
	node*root;
	int count, height, *xorder;
	vector<vector<int>> disp;
public:
	BST(){
		root = nullptr;
		count = height = 0;
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

	int getHeight(){
		return height;
	}

	int* preOrder(node*curr=nullptr, bool first=true){
		if(first){
			curr=root;
			xorder = nullptr;
			xorder = (int*)malloc(sizeof(int)*(count+2));
			xorder[0] = 0;
		}
		if(curr==nullptr) return nullptr;

		xorder[++xorder[0]] = curr->data;
		preOrder(curr->left, false);

		preOrder(curr->right, false);

		return xorder;
	}

	int* postOrder(node*curr=nullptr, bool first=true){
		if(first){
			curr = root;
			xorder = nullptr;
			xorder = (int*)malloc(sizeof(int)*(count+2));
			xorder[0] = 0;
		}
		if(curr==nullptr) return nullptr;

		postOrder(curr->left, false);
		postOrder(curr->right, false);

		xorder[++xorder[0]] = curr->data;

		return xorder;
	}

	int* inOrder(node*curr=nullptr, bool first=true){
		if(first){
			curr = root;
			xorder = nullptr;
			xorder = (int*)malloc(sizeof(int)*(count+2));
			xorder[0] = 0;
		}
		if (curr==nullptr) return nullptr;

		inOrder(curr->left, false);
		xorder[++xorder[0]] = curr->data;
		inOrder(curr->right, false);

		return xorder;
	}

	int minimum(){
		node* curr = root;

		while(curr->left!=nullptr) curr = curr->left;

		return curr->data;
	}

	void mirror(node* curr=nullptr, bool first=true){
		if(first) curr = root;
		if(curr==nullptr) return;

		node* temp = curr->left;
		curr->left = curr->right;
		curr->right = temp;

		mirror(curr->left, false);
		mirror(curr->right, false);
	}

	void createDisplayVector(node* curr, int level){
		if(curr==nullptr){
			disp[level].push_back(' ');
			return;
		}
		cout<<"\nEx 3 "<<level;
		disp[level].push_back(curr->data);
		cout<<"\nEx 5 "<<curr->data;

		createDisplayVector(curr->left, level+1);
		createDisplayVector(curr->right, level+1);
	}

	void display(){
		disp.clear();
		vector<int> lvl;
		for(int i = 0; i<=height+1; i++)
			disp.push_back(lvl);
		this->createDisplayVector(root, 0);

		for(int i = height; i>0; i++){
			for(int j = i; j>0; j++){

			}
		}
                      23
          12                      34
     10          13          32          45
  99    11    99    99    99    99    99    99
11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11

  23
12  34
	}
};

int main() {
	int choice;
	BST bst;
	while(true){
	 cout<<"\n========= MENU =========\n"
			  "(1) - Insert.\n"
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
		case 1:{
			int data;
			cout<<"Enter element: "; cin>>data;
			bst.add(data);
			break;
		}
		case 2:{
			int data;
			cout<<"Enter element: "; cin>>data;
			int h;
			h = bst.search(data);
			if(h>-1) cout<<"Element found at height: "<<h<<endl;
			else cout<<"Element not found :(\n";
			break;
		}
		case 3:
			cout<<"\nHeigth is "<<bst.getHeight()<<endl;
			break;

		case 4:{
			int *arr = bst.preOrder();
			for(int i = 1; i<=arr[0]; i++) cout<<arr[i]<<' ';
			cout<<endl<<endl;
			break;
		}
		case 5:{
			int *arr = bst.postOrder();
			for(int i = 1; i<=arr[0]; i++) cout<<arr[i]<<' ';
			cout<<endl<<endl;
			break;
		}

		case 6:{
			int *arr = bst.inOrder();
			for(int i = 1; i<=arr[0]; i++) cout<<arr[i]<<' ';
			cout<<endl<<endl;
			break;
		}

		case 7:
			cout<<"Minimum is "<<bst.minimum()<<endl<<endl;
			break;

		case 8:
			bst.mirror();
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
