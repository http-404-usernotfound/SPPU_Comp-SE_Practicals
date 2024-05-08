#include<iostream>
#include<fstream>

using namespace std;

class employee{
public:
	int id, salary;
	string name, designation;
	employee(){
		id = -1;
		name = "";
		designation = "";
		salary = -1;
	}
	employee(int i, string n, string d, int s){
		id = i;
		name = n;
		designation = d;
		salary = s;
	}

	void accept(){
		cout<<"Enter:\n-ID: "; cin>>id;
		cout<<"\n-Name: "; cin>> name;
		cout<<"\n-Designation: "; cin>> designation;
		cout<<"\n-Salary: "; cin>> salary;
	}

	void display(){
			cout<<"\n---------------------------------\n";
			cout<<"\n-ID: "<<this->id;
			cout<<"\n-Name: "<<this->name;
			cout<<"\n-Designation: "<<this->designation;
			cout<<"\n-Salary: "<<this->salary;
	}
};

int main(){
	int choice;
	bool first = true;
	while(true){
		cout<<"\n\n========= MENU ==========\n"
			  "(1) - Add.\n"
			  "(2) - Search.\n"
			  "(3) - Delete.\n"
			  "(4) - Display.\n"
			  "(5) - Exit.\n"
			  "\n    Enter your choice: "; cin>>choice;

		switch(choice){
		case 1:{
			fstream empData;
			employee e;
			e.accept();
			if(first){
				empData.open("EmpData.dat", ios::out);
				first = false;
			}
			else empData.open("EmpData.dat", ios::app);
			empData.write((char*)&e, sizeof(e));
			empData.close();
			break;
		}

		case 2:{
			int id;
			fstream empData;
			cout<<"Enter ID of employee: "; cin>>id;
			empData.open("EmpData.dat", ios::in);
			employee e;
			while(true){
				empData.read((char*)&e, sizeof(e));
				if(!empData) break;
				if(e.id == id){
					cout<<"\n\nEmployee found!\n";
					e.display();
				}
			}
			empData.close();
			break;
			}

		case 3:{
			int id;
			fstream empData;
			cout<<"Enter ID of employee: "; cin>>id;
			empData.open("EmpData.dat", ios::ate|ios::in);
			employee e;
			while(empData){
				empData.read((char*)&e, sizeof(e));
				if(e.id == id){
					cout<<"Employee found!\n\nName: "<<e.name<<endl;
					fstream emp;
					emp.seekp(empData.tellg());
					empData.seekg(-sizeof(e), ios::end);
					empData.read((char*)&e, sizeof(e));
					emp.write((char*)&e, sizeof(e));
					emp.close();
					break;
				}
			}
			empData.close();
			break;
			}

		case 4:{
			fstream empData;
			empData.open("EmpData.dat", ios::in);
			employee e;
			while(true){
				empData.read((char*)&e, sizeof(e));
				if(!empData) break;
				e.display();
			}
			break;
			empData.close();
			}

		case 5:
			cout<<"Exiting...\n";
			return 0;
		}
	}
}
