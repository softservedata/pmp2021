#include <iostream>
using namespace std;

long Suma(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return n + Suma(n - 1);
}

int Task_A(int n)
{
	int p = 1, s = 0, k = 1, a = 1;
	for (int i = 1; i <= n; i++)
	{
		if ((i - a) == 0)
		{
			s += i;
			p *= s;
			s = 0;
			k += 1;
			a += k;
		}
		else if (i == n)
		{
			s += i;
			p *= s;
		}
		else s += i;
	}
	return p;
}

long Factorial(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	return n * Factorial(n - 1);
}

int Task_B(int n)
{
	int s = 0;
	for (int i = 1; i <= n; i++)
		s += Factorial(i);
	return s;
}

int Task_C(int n)
{
	int s = 0;
	for (int k = 1; k <= n; k++)
	{
		int p = 1;
		for (int i = 0; i <= ((k - 1) * k); i++)
			p *= (k + i);
		s += p;
	}
	return s;
}

int main()
{
	int n;
	cout << "n=";
	cin >> n;
	cout << "a. s=" << Task_A(n) << endl;
	cout << "b. s=" << Task_B(n) << endl;
	cout << "c. s=" << Task_C(n) << endl;

	system("pause");
	return 0;
}