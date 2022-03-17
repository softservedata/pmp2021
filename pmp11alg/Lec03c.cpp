#include<iostream>
//#include<cmath>
using namespace std;

int main03cl()
{
	unsigned int f0;
	unsigned int f1;
	unsigned int f;
	int n;
	//
	do
	{
		cout << "n = ";
		cin >> n;
	} while (n <= 0);
	//
	f1 = 1;
	f = 1;
	for (int i = 1; i < n; i++)
	{
		f0 = f1;
		f1 = f;
		f = f0 + f1;
	}
	//
	cout << "f = " << f << endl;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
