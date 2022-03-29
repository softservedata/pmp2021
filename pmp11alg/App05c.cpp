#include<iostream>
//#include<cmath>
using namespace std;

double div(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		return n / (1 + div(n - 1));
	}
}


int main05c()
{
	int n;
	//
	cout << "n = ";
	cin >> n;
	//
	cout << "r = " << div(n) << endl;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
