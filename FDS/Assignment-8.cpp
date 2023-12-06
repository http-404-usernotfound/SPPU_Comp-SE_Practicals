#include<iostream>
using namespace std;

class node{
public:
	string name;
	node *next;

	node(string n){
		name = n;
		next = nullptr;
	}
};

class set{
	int count;
	node *head, *tail;

public:
	set(){
		count = 0;
		head = tail = nullptr;
	}

	void addNode(string n){
		node *newNode = new node(n);
		if(head == nullptr){
			head = tail = newNode;
			count += 1;
		}
		else{
			tail->next = newNode;
			tail = newNode;
			tail->next = nullptr;
			count += 1;
		}
	}

	void display(){
		node *curr = head;
		while(curr != nullptr){
			cout<<curr->name<<" ";
			curr = curr->next;
		} cout<<endl<<endl;
	}

	int inline getCount(){
		return count;
	}

	set AND(set b){
		set result;
		node *currA, *currB;
		currA = head;
		while(currA != nullptr){
			currB = b.head;
			while(currB != nullptr){
				if(currA->name == currB->name) result.addNode(currA->name);
				currB = currB->next;
			}
			currA = currA->next;
		}
		return result;
	}

	set OR(set b){
		set result;
		node *currA, *currB;
		currB = b.head;
		while(currB != nullptr){
			result.addNode(currB->name);
			currB = currB->next;
		}
		currA = head;
		bool same;
		while(currA != nullptr){
			currB = b.head;
			same = false;
			while(currB != nullptr){
				if(currA->name == currB->name){
					same = true;
					break;
				}
				currB = currB->next;
			}
			if(!same) result.addNode(currA->name);
			currA = currA->next;
		}
		return result;
	}

	set DIFF(set b){
		set result;
		node *currA, *currB, *temp;
		currA = head;
		while(currA != nullptr){
			result.addNode(currA->name);
			currA = currA->next;
		}

		if(result.head->name == b.head->name) result.head = result.head->next;
		currA = result.head;
		while(currA->next != nullptr){
			currB = b.head;
			while(currB->next != nullptr){
				if(currA->next->name == currB->next->name){
					temp = currA->next;
					currA->next = currA->next->next;
					temp->next = nullptr;
				}
				currB = currB->next;
			}
			currA = currA->next;
		}
		return result;
	}
};

int main(){
	set a, b, VandB, VorB_not_both, neitherVnorB, andd, orr;
	int choice, num;
	string name;

	while(true){
		cout<<"==============MENU==================\n";
		cout<<"(1) - Enter elements of Set A.\n"
			  "(2) - Enter elements of Set B.\n"
			  "(3) - Display elements.\n"
			  "(4) - Students who like both Vanilla and Butterscotch\n"
			  "(5) - Students who like either Vanilla or Butterscotch but not both\n"
			  "(6) - Students who like neither Vanilla nor Butterscotch\n"
			  "(7) - Exit\n\n"
			  "Enter your choice: "; cin>>choice;
		switch(choice){
		case 1:{
			cout<<"How many elements?: "; cin>>num;
			cout<<"\nEnter the elements:\n";
			for(int i = 0; i < num; i++){
				cout<<">> "; cin>>name;
				a.addNode(name);
			} break;}

		case 2:{
			cout<<"How many elements?: "; cin>>num;
			cout<<"\nEnter the elements:\n";
			for(int i = 0; i < num; i++){
				cout<<">> "; cin>>name;
				b.addNode(name);
			} break;}

		case 3:
			cout<<"Elements of Set A: "; a.display();
			cout<<"Elements of Set B: "; b.display();
			orr = a.OR(b);
			break;

		case 4:
			VandB = a.AND(b);
			cout<<"Students who like Vanilla and Butterscotch: "; VandB.display();
			break;

		case 5:
			orr = a.OR(b);
			andd = a.AND(b);
			VorB_not_both = orr.DIFF(andd);
			cout<<"Students who like either Vanilla or Butterscotch but not both: "; VorB_not_both.display();
			break;

		case 6:
			cout<<"Enter total number of students: "; cin>>num;
			num = num - a.getCount() - b.getCount();
			cout<<"Students who like neither Vanilla nor Butterscotch: "<<num<<endl;
			break;
		case 7:
			cout<<"Exiting...\n";
			return 0;
		}
	}
}
