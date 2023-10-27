#include <iostream>
#include<fstream>

using namespace std;

class Student{
public:
	string name, phoneNo;

	Student(){
		name = "";
		phoneNo = "";
	}

	void display(){
		cout<<"\nName: "<<name;
		cout<<"\nPhone Number: "<<phoneNo<<endl;
	}

	void accept(){
		cout<<"Enter name: "; cin>> name;
		cout<<"Enter phone number: "; cin>> phoneNo;
	}

};

int main() {
	int size = 0;
	cout<<"Enter number of students: "; cin>> size;
	Student *stds = new Student[size];
	cout<<"Enter the data:\n";
	for(int i = 0; i < size; i++)
		stds[i].accept();

	fstream f;
	int input;
	do{
		cout<<"\n(1) - Store.\n"
			  "(2) - Display.\n"
			  "(3) - Search.\n"
			  "(4) - Modify.\n"
			  "(5) - Exit.\n\n"
			  "Enter your choice: "; cin>> input;

		switch(input){
		case 1:
			f.open("st_data.csv", ios::in | ios::out);
			for(int i = 0; i< size; i++){
				f.write((char*)&stds[i].name, sizeof(stds[i].name));
				f<<", ";
				f.write((char*)&stds[i].phoneNo, sizeof(stds[i].phoneNo));
			} f.close();
			break;
		case 2:
			for(int i = 0; i < size; i++)
				stds[i].display();
			break;
		case 4:
			char pOld[10], pNew[10];
			cout<<"Enter old/current phone number: "; cin>> pOld;
			for(int i = 0; i < size; i++){
				if(stds[i].phoneNo == pOld){
					cout<<"Enter new phone number: "; cin>>pNew;
					stds[i].phoneNo = pNew;
					cout<<"Phone number updated :)";
					break;
				}
			}
			cout<<"Phone number not found :(";
			break;

		case 5:
			cout<<"Exiting...";
			return 0;


		case 3:
			string key;
			int choice;
			cout<<"1. By Name		2. By Phone Number: "; cin>>choice;
			switch(choice){
			case 1:{
				string n;
				cout<<"Enter the name: "; cin>>n;
				for(int i = 0; i < size; i++){
					if (stds[i].name == n){
						cout<<"Student found!\n";
						stds[i].display();
						break;
					}
						cout<<"Student not found:(";
						break;
				} break;
			}

			case 2:{
				string p;
				cout<<"Enter Phone number: "; cin>> p;
				for(int i = 0; i < size; i++){
					if (stds[i].phoneNo == p){
						cout<<"Student found!\n";
						stds[i].display();
						break;
					}
				} cout<<"Student not found:(";
				break;
			}
			}break;
		}
	}while(input != 5);


	return 0;
}

