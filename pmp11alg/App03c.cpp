#include<iostream>
using namespace std;

int main03c()
{
	double x = 0;
	double p = 1;
	double f = 1;
	double sum = 0;
	int n = 0;
	//
	cout << "x = ";
	cin >> x;
	//
	do
	{
		cout << "n = ";
		cin >> n;
	} while (n <= 0);
	//
	for (int i = 0; i < n; i++)
	{
		// x^i
		p = 1;
		for (int j = 0; j < i; j++)
		{
			p = p * x;
		}
		// i!
		f = 1;
		for (int j = 1; j <= i; j++)
		{
			f = f * j;
		}
		//
		sum = sum + p / f;
	}
	cout << "sum = " << sum << endl;
	cout << "exp(x) = " << exp(x) << endl;
	//
	cout << "\ndone02" << endl;
	system("pause");
	return 0;
}
