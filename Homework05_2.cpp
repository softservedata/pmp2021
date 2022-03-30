#include <iostream>
using namespace std;

double recurs(double n)
{
	double a,b;
	
	if (n == 0)
	{
		return 0;
	}
	else
	{
		a = sin(n);
		b = sin(a);

		return a + recurs(n - 1);
	}
}



int main()
{
	double n;
	cout << "Enter n ";
	cin >> n;

	cout << recurs(n);
	
}