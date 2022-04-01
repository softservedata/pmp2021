// Homework 05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;


double dod(int i, int n, int  y)
{
	if (i == 1) return sin(y);
	else return sin(dod(i - 1, n, --y));

}

double sum(double s, int i, int n)
{

	if (i > n) return s;
	double y = dod(i, n, n);
	s += sum(s, i + 1, n) + y;

}

double sum_i(int n)
{
	double s = 0;
	for (int i = 1; i <=n; i++)
	{
		double d = n - i + 1;
		for (int j = 1; j <= i; j++)
		{
			d = sin(d);
		}
		s += d;
	}
	return s;
}

int sum_recurs(int s, int n)
{
	if (n > 0)
	{
		s += sum_recurs(s, n - 2)+n;
	}
	return s;
}

int main()
{
	//Task1
	int n;
	cout << "n=";
	cin >> n;

	double s = 0;

	cout << "res1=" << sum_i(n) << endl; //the first variant 
	cout << "res= " << sum(0, 1, n) << endl; //the second variant 

	//Перевірка
	/*n = 3;

	for (int i = 1; i <= n; i++)
	{
		cout << dod(i, n, n) << endl;
		s += dod(i, n, n);
	}
	cout << "sum= " << s << endl;
	

	cout << endl;
	double d1 = sin(3);
	cout << "sin(3)=" << d1 << endl;

	double d2 = sin(sin(2));
	cout << "sin(sin(2))=" << d2 << endl;

	double d3= sin(sin(sin(1)));
	cout << "sin(sin(sin(1))=" << d3 << endl;

	double s1 = d1 + d2 + d3;
	cout << "sum1=" << s1 << endl;

	cout << "sum2=" << sum(0, 1, n)<<endl;*/

	//Task 2 
	int x;
	cout << "x=";
	cin >> x;

	cout <<"S = "<< sum_recurs(0, x) << endl;
	

}

