#include<iostream>
//#include<cmath>
using namespace std;

double xpowern(double x, int n) {
	if (n == 0)
	{
		return 1;
	}
	else if (n < 0)
	{
		return 1 / xpowern(x, abs(n));
	}
	else
	{
		return x * xpowern(x, n - 1);
	}

}


int main05a()
{
	int n;
	double x;
	//
	cout << "n = ";
	cin >> n;
	//
	cout << "x = ";
	cin >> x;
	//
	//
	cout << "x^n = " << xpowern(x, n) << endl;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
