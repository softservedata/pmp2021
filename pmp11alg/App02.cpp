#include<iostream>
using namespace std;

int main02a()
{
	double a = 0;
	double b = 0;
	double max = 0;
	//
	cout << " a = ";
	cin >> a;
	cout << " b = ";
	cin >> b;
	if (a > b)
	{
		max = a;
	}
	else
	{
		max = b;
	}
	cout << " max = " << max << endl;
	//
	cout << "\ndone02" << endl;
	system("pause");
	return 0;
}