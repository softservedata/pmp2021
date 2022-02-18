#include <iostream>


using namespace std;

int main()
{
	/*
	int year;

	cout << "Enter year: ";
	cin >> year;

	if ((!(year % 4) && year % 100) || !(year % 400))
	{
		cout << "This is leap year\n";
	}
	else
	{
		cout << "This is not leap year\n";
	}
	*/

	short a, b, c, t;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	cout << endl;

	if (a > b)
	{
		t = a;
		a = b;
		b = t;
	}
	if (b > c)
	{
		t = b;
		b = c;
		c = t;
	}
	if (a > b)
	{
		t = a;
		a = b;
		b = t;
	}

	cout << a << ' ' << b << ' ' << c << endl;

	return 0;
}