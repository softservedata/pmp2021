#include<iostream>
//#include<cmath>
using namespace std;

unsigned long facktor(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n* facktor(n - 1);
	}
}

unsigned long binomial(int n, int k)
{
	if ((n <= 1) || (n <= k) || (k <=0 ))
	{
		return 1;
	}
	else
	{
		return binomial(n - 1, k - 1) + binomial(n - 1, k);
	}
}

int main05d()
{
	int n, k;
	//
	do {
		cout << "n = ";
		cin >> n;
	} while (n < 1);
	//
	do {
		cout << "k = ";
		cin >> k;
	} while (k > n);
	//
	cout << "facktor(n) = " << facktor(n) << endl;
	cout << "facktorial: C_{n}^{k} = " << facktor(n) / (facktor(k) * facktor(n - k)) << endl;
	cout << "binomial:   C_{n}^{k} = " << binomial(n, k) << endl;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
