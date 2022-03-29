#include<iostream>
using namespace std;

int main04al()
{
	double x = 0;
	double p = 1;
	double f = 1;
	double sum = 1;
	double eps = 1;
	double a = 0;
	//
	cout << "x = ";
	cin >> x;
	//
	do
	{
		cout << "eps = ";
		cin >> eps;
	} while (eps <= 0);
	//
	int i = 1;
	do {
		p = p * x;
		f = f * i;
		a = p / f;
		i++;
		sum = sum + a;
	} while (abs(a) > eps);
	//
	cout << "sum = " << sum << "  i = " << i << endl;
	cout << "exp(x) = " << exp(x) << endl;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
