#include<iostream>
using namespace std;

class node{
public:
	string name;
	node *child, *next;
	char type;
	node(string n, char t='\0'){
		name = n;
		type = t;
		child = next = nullptr;
	}
};

class Tree{
	node* root;
	int count;
public:
	Tree(string n){
		root = new node(n, 'b');
		count = 0;
	}
	void addChapter(string name){
		node* curr = root->child;
		if(curr == nullptr){
			root->child = new node(name, 'c');
			return;
		}
		while(curr->next!=nullptr) curr = curr->next;
		curr->next = new node(name, 'c');
	}

	void addSection(string n){
		string chapter = "";
		int i;
		for(i = 0; n[i]!='.'; i++)
			chapter += n[i];

		i++;
		string name = "";
		for(i; n[i]!='\0'; i++)
			name += n[i];

		node *curr = root->child;
		if(curr == nullptr){
			root->child = new node(chapter, 'c');
			root->child->child = new node(name, 's');
		}
		while(curr->name!=chapter && curr->next!=nullptr)  curr = curr->next;
		if(curr->name!=chapter) {
			curr->next = new node(chapter, 'c');
			curr->next->child = new node(name, 's');
		}
		else{
			if(curr->child==nullptr){
				curr->child = new node(name, 's');
				return;
			}
			curr = curr->child;
			while(curr->next!=nullptr) curr = curr->next;
			curr->next = new node(name, 's');
		}
	}

	void addSubsection(string n){
	cout<<"ex";
		string chapter = "";
		int i;
		for(i = 0; n[i]!='.'; i++)
			chapter += n[i];

		i++;cout<<"ex";
		string section = "";
		for(i; n[i]!='.'; i++)
			section += n[i];
cout<<"ex";
		i++;
		string name = "";
		for(i; n[i]!='\0'; i++)
			name += n[i];
		cout<<chapter<<section<<name;
		node *curr = root->child;
		if(curr == nullptr){
			root->child = new node(chapter, 'c'); cout<<"ex";
			root->child->child = new node(section, 's');cout<<"ex";
			curr->child->child->child = new node(name, 'e');
			return;
		}
		while(curr->name!=chapter && curr->next!=nullptr)  curr = curr->next;
		if(curr->name!=chapter) {
			curr->next = new node(chapter, 'c');
			curr->next->child = new node(section, 's');
			curr->next->child->child = new node(name, 'e');
		}

		else{
			if(curr->child==nullptr){
				curr->child = new node(section, 's');
				curr->child->child = new node(name, 'e');
				return;
			}
			curr = curr->child;
			while(curr->name!=section && curr->next != nullptr) curr = curr->next;
			if(curr->name!=section) {
				curr->next = new node(section, 's');
				curr->next->child = new node(name, 'e');
			}
			else{
				if(curr->child==nullptr){
					curr->child = new node(name, 'e');
					return;
				}

				curr = curr->child;
				while(curr->next!=nullptr) curr = curr->next;

				curr->next = new node(name, 'e');
			}
		}
	}

	void display(node*curr=nullptr, bool first=true){
		if(first) curr = root;
		if(curr==nullptr) return;
		switch(curr->type){
		case 's':
			cout<<"\n    Section: ";
			break;
		case 'c':
			cout<<"\n\n  Chapter: ";
			break;
		case 'e':
			cout<<"\n      Subsection: ";
			break;
		case 'b':
			cout<<"Book: ";
		}
		cout<<curr->name;
		display(curr->child, false);
		display(curr->next, false);
	}
};

int main(){
	int choice;
	string name;
	cout<<"Enter name of book: "; cin>> name;
	Tree t(name);
	while(true){
		cout<<"\n\n========== MENU ===========\n"
			  "(1) - Add Chapter.\n"
			  "(2) - Add Section.\n"
			  "(3) - Add Subsection.\n"
			  "(4) - Display.\n"
			  "(5) - Exit.\n"
			  "\nEnter your choice: "; cin>>choice;

		switch(choice){
		case 1:{
			string name;
			cout<<"Enter the name: "; cin>>name;
			t.addChapter(name);
			break;
		}
		case 2:{
			string name;
			cout<<"Enter the name (chapter.section): "; cin>>name;
			t.addSection(name);
			break;
		}

		case 3:{
			string name;
			cout<<"Enter the name (chapter.section.subsection): "; cin>>name;
			t.addSubsection(name);
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
