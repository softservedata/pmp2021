#include <iostream>
using namespace std;


int main()
{

	/*
	//Task A
	int n,a,b,c,d,e;
	cout << "Enter n=";
	cin >> n;
	a = 2;
	b = 0;
	c = 1;
	d = 2;
	e = 1;
	while (true)
	{
		while (c<=d)
		{
			b += a;
			a++;
			c++;

			if (a > n)
			{
				break;
			}
		}
		c = 1;
		d++;
		if (a > n)
		{
			break;
		}
		e *= b;
		b = 0;
	}
	cout <<"Answer on the task A=" << e;

	*/

	/*
	//Task B
	int n, a, b, c, d, e;
	cout << "Enter n=";
	cin >> n;
	a = 1;
	b = 1;
	c = 1;
	d = 2;
	e = 1;
	while (true)
	{
		while (c <= d)
		{
			b *= a;
			a++;
			c++;

			if (a > n)
			{
				break;
			}
		}
		c = 1;
		d = 1;
		e += b;
		if (a > n)
		{
			break;
		}
	}
	cout << "Answer on the task B=" << e;
	*/

	/*
	//Task C
	int n, a, b, c, d, e;
	cout << "Enter n=";
	cin >> n;
	a = 2;
	b = 1;
	e = 1;
	c = a;
	while (true)
	{
		while (true)
		{
			b *= a;

			if (c * c == a)
				break;
			a++;
		}
		c++;
		a = c;
		e += b;
		if (c > n)
		{
			break;
		}
		b = 1;
	}
	cout << "Answer on the task C=" << e;
	*/
}