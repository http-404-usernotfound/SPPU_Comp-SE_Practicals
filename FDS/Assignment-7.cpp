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

	~node(){
		cout<<"\nMember deleted.\n";
	}

};

class Club{
	int count;
public:
	node *head, *tail;

	Club(){
		head = tail = NULL;
		count = 0;
	}


	void addMem(string prn, string name){
		node *newNode = new node(prn, name);
		if(head == NULL){
			head = new node("-", "-");
			head->next = newNode;
			newNode->next = tail;
		}
		else{
			node *curr = head;
			while(curr->next != tail) curr = curr->next;

			curr->next = newNode;
			newNode->next = tail;
		}
		count++;
	}

	void remMem(string prn){
		node *curr = head;
		while(curr->next->prn != prn) curr = curr->next;

		if (curr->next->prn == prn){
			node *temp = curr->next;

			curr->next = curr->next->next;

			delete temp;

		}
		else{
			cout<<"\nMember not found!\n";
		}
	}

	void addPres(string prn, string name){
		node *temp = head;
		head = new node(prn, name);
		head->next = temp->next;


	}
	void remPres(){head = NULL;}

	void addSec(string prn, string name){
		tail = new node(prn, name);
	}
	void remSec(){tail = NULL;}

	void display(){
		node *curr = head;
		cout<<"PRN: "<<curr->prn;
		cout<<"  Name: "<<curr->name<<endl<<endl;
		do{
			curr = curr->next;

			if(curr == NULL)cout<<"NULL"<<endl;
			else{
			cout<<"PRN: "<<curr->prn;
			cout<<"  Name: "<<curr->name<<endl<<endl;
			}
		}while(curr != NULL);
	}

	int getCount(){
		return count;
	}

	Club concat(Club c1, Club c2){
		Club result = c1;
		Club con = c2;
		*(result.tail) = *(con.head);

		return result;
	}
};

int main() {
	string name, prn;
	Club c;
	int choice;
	int i, j;
	i = j = 1;


//	while(i){
//		cout<<"(1) - "
//	}


	while(j){
		cout<<"============MENU===============\n";
		cout<<"(1) - Add Members\n";
		cout<<"(2) - Remove Member\n";
		cout<<"(3) - Add President\n";
		cout<<"(4) - Remove President\n";
		cout<<"(5) - Add Secretary\n";
		cout<<"(6) - Remove Secretary\n";
		cout<<"(7) - Display No. of Members\n";
		cout<<"(8) - Display members.\n";
		cout<<"(9) - Exit.\n";
		cout<<"\nEnter your choice: "; cin>>choice;

		switch(choice){
		case 1:
			int num;
			cout<<"How many members to enter?: "; cin>>num;
			for(int k = 0; k<num; k++){
				cout<<"Enter details:\n\nName: "; cin>>name;
				cout<<"PRN: "; cin>>prn;
				c.addMem(prn, name);
			}
			break;

		case 2:
			cout<<"Enter prn: "; cin>> prn;
			c.remMem(prn);
			break;

		case 3:
			cout<<"Enter details of President\n\nName "; cin>>name;
			cout<<"PRN: "; cin>>prn;
			c.addPres(prn, name);
			break;

		case 4:
			cout<<"\n Removing President...";
			c.remPres();
			break;

		case 5:
			cout<<"Enter details of Secretary\n\nName: "; cin>>name;
			cout<<"PRN: "; cin>>prn;
			c.addSec(prn, name);
			break;

		case 6:
			cout<<"Removing Secretary...";
			c.remSec();
			break;

		case 7:
			cout<<"Total number of members: "<<c.getCount();
			break;

		case 8:
			c.display();
			break;

		case 9:
			cout<<"\nExiting...\n";
			return 0;
		}
	}
}
