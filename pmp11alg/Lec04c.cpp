#include<iostream>
using namespace std;


long fn(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	return n * fn(n - 1);
};


int main04cl()
{
	int n;
	//
	cout << "n = ";
	cin >> n;
	//
	cout << "n! = " << fn(n) << endl;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
