#include<iostream>
using namespace std;

int main()
{
	int a, b, c, max;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	//
	// /*
	c = a + b;
	cout << "c = " << c << endl;
	// */
	/*
	if (a > b)
	{
		max = a;
	}
	else
	{
		max = b;
	}
	*/
	max = a;
	if (b > max)
	{
		max = b;
	}
	cout << "max = " << max << endl;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
