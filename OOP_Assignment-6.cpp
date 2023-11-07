//============================================================================
// Name        : OOP_Assignment-6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

class item{

public:
	char name[10];
	int nos,cost,code;


	bool operator ==(const item &i1){
		return code==i1.code;
	}

	bool operator < (const item&i1){
		return code<i1.code;
	}
};
vector<item>o1;
void print(item &i1);
void display();
void insert();
void search();
void dlt();
bool compare(const item &i1, const item &i2){
	return i1.cost<i2.cost;

}

int main() {
	int ch;

	while (ch!=6){
		cout<<"Menu:\n";
		cout<<"1. Insert.\n";
		cout<<"2. Display.\n";
		cout<<"3. Search.\n";
		cout<<"4. Sort.\n";
		cout<<"5. Delete.\n";
		cout<<"6. Exit.\n";
		cout<<"\n Enter your choice: "; cin>>ch;

		switch(ch){
		case 1:
			insert();
			break;
		case 2:
			display();
			break;

		case 3:
			search();
			break;

		case 4:
			sort(o1.begin(), o1.end(), compare);
			cout<<"This Vector has been sorted!";
			display();
			break;

		case 5:
			dlt();
			break;

		case 6:
			cout<<"=====THE END====";
		}
	}
	return 0;
}

void insert(){
	item i1, qty;
	cout<<"Enter item name: "; cin>>i1.name;
	cout<<"Enter item quantity: "; cin>>i1.nos;

	cout<<"Enter item cost: "; cin>>i1.cost;
	cout<<"Enter item code: "; cin>>i1.code;

	o1.push_back(i1);
}

void display(){
	for_each(o1.begin(), o1.end(), print);

}

void print(item &i1){
	cout<<"Item name: "<<i1.name<<endl
		<<"Item quantity: "<<i1.nos<<endl
		<<"Item cost: "<<i1.cost<<endl
		<<"Item code: "<<i1.code<<endl;

}

void search(){
	vector<item>::iterator p;
	item i1;
	cout<<"Enter item code to search: "; cin>>i1.code;

	p = find(o1.begin(), o1.end(), i1);

	if(p == o1.end()) cout<<"\nItem not found!!\n";

	else cout<<"\nItem found!!\n\nName: "<<p->name<<endl
			<<"Quantity: "<<p->nos<<endl
			<<"Cost: "<<p->cost<<endl
			<<"Code: "<<p->code<<endl;
}

void dlt(){
	vector<item>::iterator p;

	item i1;
	cout<<"Enter item code to delete: "; cin>>i1.code;

	p = find(o1.begin(), o1.end(), i1);

	if(p == o1.end()) cout<<"Item not found!!";

	else{
		o1.erase(p);
		cout<<"Deleted!!";
	}
}
