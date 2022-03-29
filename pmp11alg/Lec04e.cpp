#include<iostream>
//#include<cmath>
using namespace std;

unsigned long fibon(unsigned long n)
{
	cout << "\tRunning n = " << n << endl;
	if (n <= 1)
	{
		return 1;
	}
	return fibon(n - 1) + fibon(n - 2);
}


int main04el()
{
	unsigned long n;
	//
	do
	{
		cout << "n = ";
		cin >> n;
	} while (n <= 0);
	//
	//
	cout << "f = " << fibon(n) << endl;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
