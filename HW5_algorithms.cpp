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

double Suma_Sin (int n, int a, int b, int c)
{
	if (a == 1) 
	{
		if (b == n) return sin(1);
		return sin(Suma_Sin(n, a, b+1, 0));
	}
	else if (c == 0) 
	{
		if (a + b == n + 1) return sin(a);
		return sin(Suma_Sin(n, a, b+1, 0));
	}
	else if (c == 1) return Suma_Sin(n, a, b, 0) + Suma_Sin(n, a - 1, b, 1);
}

int Suma (int n)
{
	if (n < 0) return 0;
	return n + Suma (n - 2);
}

int main()
{
	int n;
	cout << "Enter n: ";
	cin >> n;
	cout << "Task_1 s=" << Sin(n) << endl;
	cout << "Task_1 s=" << Suma_Sin(n, n, 1, 1) << endl;
	cout << "Task_2 s=" << Suma(n) << endl;
	system("pause");
	return 0;
}