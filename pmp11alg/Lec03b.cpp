#include<iostream>
//#include<cmath>
using namespace std;

int main03cl()
{
	double a;
	double a0;
	double x;
	double eps;
	int n;
	//
	do
	{
		cout << "eps = ";
		cin >> eps;
	} while ((eps <= 0) || (eps > 1));
	//
	n = 1;
	a = 2;
	do
	{
		a0 = a;
		n = n + 1;
		//
		a = 1;
		x = 1.0 + 1.0 / n;
		for (int i = 0; i < n; i++)
		{
			a = a * x;
		}
	} while (abs(a - a0) > eps);
	//
	cout << "a = " << a << endl;
	cout << "n = " << n << endl;
	cout << "exp(1) = " << exp(1) << endl;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
