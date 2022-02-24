#include<iostream>
using namespace std;

int main02l()
{
	/*
	double a = 0;
	double b = 0;
	double c = 0;
	double t = 0;
	//
	cout << " a = ";
	cin >> a;
	cout << " b = ";
	cin >> b;
	cout << " c = ";
	cin >> c;
	*/
	//
	/*
	cout << "sorted: ";
	if (a < b)
	{
		if (b < c)
		{
			cout << a << "  " << b << "  " << c;
		}
		else
		{
			if (a < c)
			{
				cout << a << "  " << c << "  " << b;
			}
			else
			{
				cout << c << "  " << a << "  " << b;
			}
		}
	}
	else
	{
		if (a < c)
		{
			cout << b << "  " << a << "  " << c;
		}
		else
		{
			if (b < c)
			{
				cout << b << "  " << c << "  " << a;
			}
			else
			{
				cout << c << "  " << b << "  " << a;
			}
		}
	}
	*/
	/*
	cout << "sorted: ";
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
	cout << a << "  " << b << "  " << c;
	*/
	// Initialization
	int* a;
	int n = 0;
	do {
		cout << " n = ";
		cin >> n;
	} while (n <= 0);
	//
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << " a[" << i << "] = ";
		cin >> a[i];
	}
	// Business Logic
	// Sum
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		s = s + a[i];
	}
	//
	// prod
	int p = 1;
	for (int i = 0; i < n; i++)
	{
		p = p * a[i];
	}
	//
	// Print Result
	cout << "s = " << s << endl;
	cout << "p = " << p << endl;
	delete[] a;
	//
	cout << "\ndone02" << endl;
	system("pause");
	return 0;
}
