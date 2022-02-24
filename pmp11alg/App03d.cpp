#include<iostream>
using namespace std;

int main()
{
	double x = 0;
	double p = 1;
	double f = 1;
	double sum = 1;
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
	for (int i = 1; i < n; i++)
	{
		p = p * x;
		f = f * i;
		sum = sum + p / f;
	}
	cout << "sum = " << sum << endl;
	cout << "exp(x) = " << exp(x) << endl;
	//
	cout << "\ndone02" << endl;
	system("pause");
	return 0;
}
