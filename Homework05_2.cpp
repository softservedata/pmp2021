#include <iostream>
using namespace std;

double recuks(double n)
{
	double a;
	if (n<=0)
	{
		return 0;
	}
	else
	{
		return n + recuks(n - 2);
	}
}

int main()
{
	double n;
	cout << "Enter n =";
	cin >> n;

	cout<<"S="<< recuks(n);
}