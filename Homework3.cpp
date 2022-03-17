// Homework3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	
	//Task1
	int n;
	cout << "n=";
	cin >> n;
	int p = 1;
	int k = 1;
	int t = 1; 

	while (true)
	{
		int s = 0;
		for (int i = 1; i <= t; i++)
		{
			s += k;
			k++;
		}
		t++;
		p *= s;

		if (k > n)
		{
			break;
		}
	}
	cout << "p=" << p << endl;
	


	//Task 2
	int n;
	cout << "n=";
	cin >> n;
	int s = 0;
	int f2 = 1; 
	int f1 = 0; 
	for (int i = 1; i <= n; i++)
	{
		f1 = f2;
		f2 = f1 * i;
		s += f2;

	}
	cout << "s=" << s << endl;
	


	//Task 3
	int n;
	cout << "n=";
	cin >> n;
	int s = 0;

	for (int k = 1; k <= n; k++) 
	{
		int p = 1;
		int c = pow(k, 2);
		for (int j = k; j <= c; j++)
		{
			p *= j;
		}
		s += p;
	}
	cout << "s=" << s << endl;
	
}
