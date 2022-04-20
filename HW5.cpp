#include <iostream>
using namespace std;

double sin(int n)
{
	double s = 0, a = 0;
	for (int i = n; i >= 0; i--)
	{
		a = sin(n - i);
		for (int j = i - 1; j >= 0; j--)
			a = sin(a);
		s += a;
	}
	return s;
}

double sin_sum(int n, int a, int b, int c)
{
	if (a == 1)
	{
		if (b == n) return sin(1);
		return sin(sin_sum(n, a, b + 1, 0));
	}
	else if (c == 0)
	{
		if (a + b == n + 1) return sin(a);
		return sin(sin_sum(n, a, b + 1, 0));
	}
	else if (c == 1) return sin_sum(n, a, b, 0) + sin_sum(n, a - 1, b, 1);
}

int sum(int n)
{
	if (n < 0) return 0;
	return n + sum(n - 2);
}

int main()
{
	int n;
	cout << "Enter n: ";
	cin >> n;
	cout << "sum 1 = " << sin(n) << endl;
	cout << "recurcive sum 1 = " << sin_sum(n, n, 1, 1) << endl;
	cout << "recursive sum 2 = " << sum(n) << endl;
	system("pause");
	return 0;
}