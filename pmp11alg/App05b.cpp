#include<iostream>
//#include<cmath>
using namespace std;

int main05b()
{
	int n;
	double r;
	//
	cout << "n = ";
	cin >> n;
	//
	r = 0;
	for (int i = 1; i <= n; i++)
	{
		r = i / (1 + r);
	}
	// 
	//
	cout << "r = " << r << endl;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
