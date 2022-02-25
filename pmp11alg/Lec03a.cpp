#include<iostream>
using namespace std;

int main03al()
{
	//unsigned int f = 1;
	double f = 1;
	int n = 0;
	//
	do
	{
		cout << "n = ";
		cin >> n;
	} while (n <= 0);
	//
	// n!
	f = 1;
	for (int i = 1; i <= n; i++)
	{
		f = f * i;
	}
	//
	cout << "f = " << f << endl;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
