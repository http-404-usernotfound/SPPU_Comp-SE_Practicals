#include <iostream>
using namespace std;

class Person{
	string *name, *bloodGrp, *address;
	int rollNo, dob;
	long int ipn, drNo, contactNo;
	float height;

public:
	static int count;

	Person(){
		name = new string, bloodGrp = new string, address = new string;
		ipn = -1, drNo = -1, contactNo = -1, height = -1, rollNo = -1, dob = -1;
		count++;
		display();
	}

	Person(const Person &p){
		name = p.name, bloodGrp = p.bloodGrp, address = p.address;
		ipn = p.ipn, drNo = p.drNo, contactNo = p.contactNo, height = p.height, rollNo = p.rollNo, dob = p.dob;
		count++;
		display();
	}

	Person(string n, string b, string a, long int ipn, long int drNo, long int contactNo, float height, int rollNo, int dob){
		name = new string, bloodGrp = new string, address = new string;
		this->ipn = ipn, this->drNo = drNo, this->contactNo = contactNo, this->height = height,
				this->rollNo = rollNo, this->dob = dob;
		*name = n, *bloodGrp = b, *address = a;
		count++;
		display();
	}

	void display(){
		cout<<"Name: "<<*name;
		cout<<", Blood Group: "<<*bloodGrp;
		cout<<", Address: "<<*address;
		cout<<", IPN: "<<ipn;
		cout<<", Driving license number: "<<drNo;
		cout<<", Contact Number: "<<contactNo;
		cout<<", Height: "<<height;
		cout<<", Roll Number: "<<rollNo;
		cout<<", DOB: "<<dob<<endl;
	}

	static void displayCount(){
		cout<<"Number of entries: "<<count<<endl;
	}

	Person* compare(Person* p){
		if(p->height > height) return p;
		else return this;
	}
	~Person(){
		cout<<"Destructor called...";
		count--;
	}
	friend class Age;
};

class Age{
	int age, currentYear = 2023;
public:
	int calculateAge(Person* p){
		age = currentYear - p->dob;
		return age;
	}

};

int Person::count = 0;

int main() {
	string *name, *bloodGrp, *address;
	int rollNo, dob;
	long int ipn, drNo, contactNo;
	float height;

	int choice;
	Person* persons[10];

	while (true){
		cout<<endl<<endl;
		cout<<"(1) - Default constructor.\n"
			  "(2) - Parameterised constructor.\n"
			  "(3) - No. of entries.\n"
			  "(4) - Calculate age.\n"
			  "(5) - Taller student.\n"
			  "(6) - Exit.\n";
		cout<<"Enter your choice >> ";cin>>choice;

		switch(choice){
			case 1:{
				Person p = Person();
				break;
			}

			case 2:{
				name = new string;
				cout<<"Enter Name: "; cin>>*name;
				bloodGrp = new string;
				cout<<"Enter Blood Group: "; cin>>*bloodGrp;
				address = new string;
				cout<<"Enter Address: "; cin>>*address;
				cout<<"Enter IPN: "; cin>>ipn;
				cout<<"Enter Driving license number: "; cin>>drNo;
				cout<<"Enter Contact Number: "; cin>>contactNo;
				cout<<"Enter Height: "; cin>>height;
				cout<<"Enter Roll Number: "; cin>>rollNo;
				cout<<"Enter DOB: "; cin>>dob;

				persons[Person::count-1] = new Person (*name, *bloodGrp, *address, ipn, drNo, contactNo, height, rollNo, dob);

				break;
			}

			case 3:
				Person::displayCount();
				break;
			case 4:{
				int i;
				cout<<"Calculate age of which student?\n";
				for(i = 0; i<Person::count; i++){ cout<<"("<<i+1<<") - "; persons[i]->display();}
				cout<<"\nEnter choice: ";cin>>i;
				Age a;
				cout<<"\nAge is: "<<a.calculateAge(persons[i-1])<<endl;
				break;
			}
			case 5:
				Person *temp;
				temp = persons[0];
				for(int i = 0; i<Person::count-1; i++) temp = temp->compare(persons[i+1]);
				cout<<"\nTallest student is: "; temp->display();
				break;
			case 6:
				cout<<"Exiting...";
				return 0;
		}
	}
}

