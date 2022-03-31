#include <iostream>
using namespace std;

double Sin(int n)
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

double Sum(int n, int a, int b, int c)
{
	if (a == 1)
	{
		if (b == n) return sin(1);
		return sin(Sum(n, a, b + 1, 0));
	}
	else if (c == 0)
	{
		if (a + b == n + 1) return sin(a);
		return sin(Sum(n, a, b + 1, 0));
	}
	else if (c == 1) return Sum(n, a, b, 0) + Sum(n, a - 1, b, 1);
}

int SumTask2(int n)
{
	if (n < 0) return 0;
	return n + SumTask2(n - 2);
}

int main()
{
	int n;
	cout << "Enter n>> ";
	cin >> n;
	cout << "The result of task1 = " << Sin(n) << endl;
	cout << "The result of task1 = " << Sum(n, n, 1, 1) << endl;
	cout << "The result of task2 = " << Sum(n) << endl;
	system("pause");
	return 0;
}