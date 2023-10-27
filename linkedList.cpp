//============================================================================
// Name        : DSL-linkedList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node{
public:

	string prn, name;
	node *next;

	node(string prn, string name){
		this->prn = prn;
		this->name = name;
		next = NULL;
	}

};

class Club{
	static int count;
public:
	node *head, *tail;

	Club(){
		head = tail = NULL;
	}


	void addNode(string prn, string name){
		node *newNode = new node(prn, name);
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail->next = newNode;
			tail = newNode;
		}
		count++;
		node *curr = head;
		while(curr->next->next != tail) curr = curr->next;

		tail->next = curr->next;
		curr->next = tail;
		tail->next->next = NULL;
		tail = tail->next;

	}

	void display(){
		node *curr = head;
		while(curr != NULL){
			cout<<"PRN: "<<curr->prn;
			cout<<"  Name: "<<curr->name<<endl<<endl;
			curr = curr->next;
		}
	}

	static int getCount(){
		return count;
	}

	Club concat(Club c1, Club c2){
		Club result = c1;
		Club con = c2;
		*(result.tail) = *(con.head);

		return result;
	}
};

int Club::count = 0;

int main() {
	string name, prn;
	Club c;

	cout<<"Enter the details()\n(enter '-1' when done)\n\n";
	while(name != "-1"){
		cout<<"Enter name: "; cin>>name;
		cout<<"Enter PRN: "; cin>>prn;
		if (prn != "-1") c.addNode(prn, name);
	}

	c.display();
	return 0;
}

