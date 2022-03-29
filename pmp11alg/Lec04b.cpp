#include<iostream>
using namespace std;

int main04bl()
{
	int n;
	double r = 0;
	//
	cout << "n = ";
	cin >> n;
	//
	for (int i = n; i > 0; i--)
	{
		r = sqrt(i + r);
	}
	cout << "r = " << r << endl;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
