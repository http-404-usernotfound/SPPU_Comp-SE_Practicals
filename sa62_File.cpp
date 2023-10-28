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
			f.open("st_data.txt", ios::in | ios::out);
			for(int i = 0; i< size; i++){
				f.write((char*)&stds[i], sizeof(stds[i]));
			} f.close();
			break;
		case 2:
			for(int i = 0; i < size; i++)
				stds[i].display();
			break;
		case 4:{
			char pOld[10], pNew[10];
			int j = 0;
			cout<<"Enter old/current phone number: "; cin>> pOld;
			for(int i = 0; i < size; i++){
				if(stds[i].phoneNo == pOld){
					cout<<"Enter new phone number: "; cin>>pNew;
					stds[i].phoneNo = pNew;
					cout<<"Phone number updated :)";
					j = 1;
					break;
				}
			}if (j ==1)cout<<"Phone number not found :(";
			break;
		}

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
				int j = 0;
				cout<<"Enter the name: "; cin>>n;
				for(int i = 0; i < size; i++){
					if (stds[i].name == n){
						cout<<"Student found!\n";
						stds[i].display();
						j = 1;
						break;
					}
				}
				if (j == 0) cout<<"Student not found:(";
				break;
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
