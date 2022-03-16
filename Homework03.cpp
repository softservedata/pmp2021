#include<iostream>
using namespace std;

int main()
{
	// task 2
	
	unsigned long  sum, d, n;
	cout << "Enter n  = ";
	cin >> n;
	sum=0;
	for (int i = 1; i<= n; ++i)
	{
		d = 1;
		for (int j = 1;j<=i ; ++j)
		{
			d *=  j;
			
		}
		sum += d;
	}
	cout << sum << endl;
	
	
	
	
}
