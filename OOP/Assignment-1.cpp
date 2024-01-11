#include <iostream>
using namespace std;

class Complex{
	int imag;
	int real;

public:
	Complex(int imag = 0, int real = 0){
		this->imag = imag;
		this->real = real;
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
	
	friend istream& operator>>(istream&, Complex&);
	friend ostream& operator<<(ostream&, Complex&);
};

istream& operator>>(istream& in, Complex& comp){
	in>>comp.real>>comp.imag;
	
	return in;
}

ostream& operator<<(ostream& out, Complex& comp){
	out<<comp.real<<(comp.imag>=0?" +":"")<<comp.imag<<'i';
		
	return out;
}

int main() {
	Complex comp1, comp2;
	cout<<"Enter first complex number:"; cin>>comp1;
	
	cout<<"First complex number is: "<<comp1<<endl;

	cout<<"Enter second complex number:"; cin>>comp2;
	
	cout<<"Second complex number is: "<<comp2<<endl;

	Complex sum = comp1 + comp2;
	Complex product = comp1 * comp2;

	cout<<"Sum is: "<<sum<<endl;
	
	cout<<"Product is: "<<product<<endl;

	return 0;
}
