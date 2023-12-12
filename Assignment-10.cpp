#include<iostream>

using namespace std;

const char prec[] = {};

class stack{
	int ptr, *st;
	
  public:
	stack(int num){
		st = new int [num];
		ptr = -1;
	}
	
	void push(int n){
		st[++ptr] = n;
	}
	
	int pop(){
		return st[ptr--];
	}
	
	int peek(){
		return st[ptr];
	}
	
	bool isEmpty(){
		return ptr == -1;
	}
};

int main(){
	int n, j = 0;
	string infix;
	char c;
	
	cout<<"Enter infix expression: "; cin>>infix;
	n = infix.length();
	char postfix[n];
	stack operators(n/2);
	
	for(int i = 0; i<n; i++){
		if(48<=((int)infix[i]) && ((int)infix[i])<=57) postfix[j++] = infix[i];
		
		else{
			c = infix[i];
			switch(c){
			case '/':
			case '*':
				operators.push(c);
				break;
			
			case '+':
			case '-':
				while((operators.peek() == '/' || operators.peek() == '*') && !operators.isEmpty())
					postfix[j++] = operators.pop();
				operators.push(c);
			}
		}
	}
	
	while(!operators.isEmpty()) postfix[j++] = operators.pop();
	postfix[j] = '\0';
	cout<<"Postfix exp: "<<postfix<<endl;
	
	float result;
	int temp;
	stack operands(n+1-n/2);
	for(int i = n-1; i>=0; i--)
		if(!(48<=((int)postfix[i]) && ((int)postfix[i])<=57)) 
			operators.push(postfix[i]);
		
	for(int i = 0; i<n; i++)
		if(48<=((int)postfix[i]) && ((int)postfix[i])<=57)
			operands.push((int)postfix[i]-48);

	result = operands.pop();
	while(!operands.isEmpty()){
		c = operators.pop();
		switch(c){
		case '*':
			result *= operands.pop();
			break;
		case '/':
			result = operands.pop()/result;
			break;
		case '-':
			result = operands.pop() - result;
			break;
		case '+':
			result += operands.pop();
		}
	}
	
	cout<<"\nResult: "<<result<<endl;	
	
	return 0;
}
