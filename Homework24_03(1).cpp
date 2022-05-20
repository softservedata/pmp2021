#include <iostream>

using namespace std;

int recursion(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		n += recursion(n - 2);
	}
}

int main()
{
	int n;
	cout << " n =";
	cin >> n;

	cout << "result = " << recursion(n) << endl;
	return 0;
}