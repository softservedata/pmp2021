#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b;

	//Використання додаткової змінної:

	cout << "Additional variable:" << endl;
	int f;
	a = 5; b = 13;
	cout << "Old data: a = " << a << " b = " << b << endl;
	f = a; 
	a = b; 
	b = f;
	cout << "New data: a = " << a << " b = " << b << endl << endl;

	//Використання додавання та віднімання:

	cout << "Addition and subtraction:" << endl;
	a = 4; b = 17;
	cout << "Old data: a = " << a << " b = " << b << endl;
	a += b; 
	b = a - b; 
	a -= b;
	cout << "New data: a = " << a << " b = " << b << endl << endl;

	//Використання множення та ділення:

	cout << "Multiplication and division:" << endl;
	float c = 2, d = 14.5;
	cout << "Old data: c = " << c << " d = " << d << endl;
	c *= d; 
	d = c / d; 
	c /= d;
	cout << "New data: c = " << c << " d = " << d << endl << endl;

	//Використання кон'юнкції та диз'юнкції:

	cout << "Conjunction and disjunction:" << endl;
	a = 5; b = 11;
	cout << "Old data: a = " << a << " b = " << b << endl;
	a = (~a & b) | (a & ~b); 
	b = (~a & b) | (a & ~b); 
	a = (~a & b) | (a & ~b);
	cout << "New data: a = " << a << " b = " << b << endl << endl;

	//Зсув:

	cout << "Shift:" << endl;
	a = 7; b = 9;
	cout << "Old data: a = " << a << " b = " << b << endl;
	long long int g = a << 16 | b;
	g = (int)g << 16 | g >> 16; 
	a = g >> 16; 
	b = (short int)g;
	cout << "New data: a = " << a << " b = " << b << endl << endl;

    //Додавання по модулю 2:

	cout << "XOR:" << endl;
	a = 6; b = 12;
	cout << "Old data: a = " << a << " b = " << b << endl;
	a ^= b;	
	b ^= a; 
	a ^= b;
	cout << "New data: a = " << a << " b = " << b << endl << endl;

	return 0;
}