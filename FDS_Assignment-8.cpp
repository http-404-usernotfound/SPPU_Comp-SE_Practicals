#iclude<iostram>
using namespace std;

class node{
public:
	string name;
	node *next;
	
	node(string n){
		name = n;
		next = NULL;
	}
}

class set{
	int count;
	node *head, *tail;
	
public:
	set(){
		count = 0;
		head = tail = NULL;
	}
	
	void addNode(string n){
		node *newNode = new node(n);
		if(!head){
			head = newNode;
			newNode->next = tail;
			count += 1;
		}
		else{
			tail = newNode;
			newNode->next = tail;
			count += 1;
		}
	}
	
	void display(){
		node *curr = head;
		for(int i = 0; i < count; i++){
			cout<<curr->name<<" "<<endl;
			cout = cur->next;
			cout<<endl<<endl;
		}
	}
	
	int getCount(){
		return count;
	}
	
	set AND(set b){
		set a = *this;
		node *currA, *currB;
		for(int i = 0; i < count; i++){
			for(int j = 0; j < count; j++){
				if(
				currB = currB->next;
			}
			currA = currA->next;
		}
	}

}

int main(){
	set a, b, VandB, VorB_not_both, neitherVnorB;
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
		case 1:
			cout<<"How many elements?: "; cin>>num;
			cout<<"\nEnter the elements:\n";
			for(int i = 0; i < num; i++)
				cout<<">> "; cin>>name;
				a.addNode(name);
		}
		break;
		
		case 2:
			cout<<"How many elements?: "; cin>>num;
			cout<<"\nEnter the elements:\n";
			for(int i = 0; i < num; i++)
				cout<<">> "; cin>>name;
				b.addNode(name);
		}
		break;
		
		case 3:
	}
}	return 0;