#include<iostream>
using namespace std;
int main() 
{
	int a, b, temp;

	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	
	temp = a;
	a = b;
	b = temp;
	
	cout << "Using an additional variable:" << endl << "a = " << a << endl << "b = " << b << endl;

	
	a = a + b;
	b = a - b;
	a = a - b;
	
	cout << "Using addition and subtraction:" << endl << "a = " << a << endl << "b = " << b << endl;

	
	a = a * b;
	b = a / b;
	a = a / b;

	cout << "Using multiplication and division:" << endl << "a = " << a << endl << "b = " << b << endl;
	

	
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	
	cout << "Using the XOR operator:" << endl << "a = " << a << endl << "b = " << b << endl;



	return 0;
	system("pause");
}