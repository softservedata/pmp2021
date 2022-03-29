#include<iostream>
using namespace std;

double fsqrt(int i, int n)
{
	if (i > n)
	{
		return 0;
	}
	return sqrt(i + fsqrt(i + 1, n));
}

int main04dl()
{
	int n;
	double r = 0;
	//
	cout << "n = ";
	cin >> n;
	//
	cout << "r = " << fsqrt(1, n) << endl;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}