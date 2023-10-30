#include <iostream>
using namespace std;

class Complex{
	int imag;
	int real;

public:
	Complex(int imag = 0, int real = 0){
		this->imag = imag;
		this->real = real;
		cout<<"Default constructor: ";this->giveOutput();
	}
	void takeInput(){
		cin>> real; cin>> imag;
	}

	void giveOutput(){
		cout<<real<<"+"<<imag<<'i'<<endl;
	}
	Complex operator +(Complex comp){
		Complex sum = comp;
		sum.real+=real;
		sum.imag+=imag;
		return sum;
	}
	Complex operator *(Complex comp){
		Complex product;
		product.real = real*comp.real-imag*comp.imag;
		product.imag = real*comp.imag+imag*comp.real;

		return product;

	}
};

int main() {
	Complex comp1, comp2, sum, product;
	cout<<"Enter first complex number:"<<endl;
	comp1.takeInput();
	cout<<"First complex number is: "; comp1.giveOutput();
	cout<<endl;

	cout<<"Enter second complex number:"<<endl;
	comp2.takeInput();
	cout<<"Second complex number is: "; comp2.giveOutput();
	cout<<endl;

	sum = comp1 + comp2;
	product = comp1 * comp2;

	cout<<"Sum is: "; sum.giveOutput();
	
	cout<<"Product is: "; product.giveOutput();

	return 0;
}
