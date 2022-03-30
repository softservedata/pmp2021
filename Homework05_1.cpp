#include <iostream>
using namespace std;

double recurs(double n, double m, double c)
{
	double a, b;
	a = sin(n);
	while (c!=0)
	{
		b = sin(a);
		a = b;
		c--;
	}
	
	c = m;

	if (n == 0)
	{
		return 0;
	}
	else
	{
		return a + recurs(n - 1,m+1,c+1);
	}
}



int main()
{
	double n,m,c;
	cout << "Enter n ";
	cin >> n;
	m = 0;
	c = 0;
	cout << recurs(n,m,c);

}