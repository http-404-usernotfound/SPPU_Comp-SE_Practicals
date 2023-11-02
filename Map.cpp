#include <iostream>
#include<map>
#include<string>

using namespace std;

int main() {
	typedef map<string, int>maptype;

	string state_name;

	mapType popMap;

	popMap.insert(pair<string, int> ("Maharashtra", 7026357));
	popMap.insert(pair<string, int> ("Rajasthan", 6678993));
	popMap.insert(pair<string, int> ("Karnataka", 6678936));
	popMap.insert(pair<string, int> ("Punjab", 6757860));

	mapType :: iteration iter;

	cout<<"Population of states in India"<<endl;
	cout<<"\nSize of population map:"<<popMap.size();
	cout<<"\nEnter name of the state"; cin>> state_name

	iter = popMap.find(state_name);

	if(iter != popMap.end()){
		cout<<state_name<<"'s population is: "<<iter->second;
	}
	else{
		cout<<"Key is not population map\n";
		popMap.clear();
	}

	return 0;
}
