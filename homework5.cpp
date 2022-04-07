#include <iostream>
#include <math.h>
using namespace std;

int recurs(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		return n + recurs(n - 2);
	}
}

int main()
{
	int n;
	cout << " n =";
	cin >> n;

	cout<<"sum = "<< recurs(n)<< endl;
  return 0;
}
