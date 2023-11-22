#include<iostream>
using namespace std;

class stack{
	int count, top, length;
	char *st;
  public:
	stack(int len){
		count = 0;
		top = -1;
		length = len;
		st = new char[len];
	}
	
	void push(char c){
		if(this->isFull()){
			cout<<"Stack Overflow\n";
			return;
		}
		st[++top] = c;
		count++;
	}
	
	char pop(){
		if(this->isEmpty()){
			cout<<"Stack is Empty!\n";
			return '\0';
		}
		return st[top--];
	}
	
	bool inline isFull(){
		return !(count<length);
	}
	
	bool inline isEmpty(){
		return count==0;
	}
};

string reverse(string str, int size){
	stack reverse(size);
	char result[size];
	for(int i = 0; i<size; i++) reverse.push(str[i]);
	for(int i = 0; i<size; i++) result[i] = reverse.pop();
	
	return result;
}

bool palindrome(string str, int size){
	bool result = true;
	string rev = reverse(str, size);
	for(int i = 0; i<size; i++) if(rev[i] != str[i]) result = false;
	
	return result;
}

int main(){
	string str;
	char input;
	do{
		cout<<"\nEnter a word: "; cin>>str;
		cout<<"\nReverse: "<<reverse(str, str.length())<<endl;
		
		if(palindrome(str, str.length())) cout<<"\nThe word is a palindrome\n";
		else cout<<"\nThe word is not a palindrome\n";
		
		cout<<"\nDo you want to continue?(y/n): "; cin>>input;
		
	} while(input != 'n');
	return 0;
}
