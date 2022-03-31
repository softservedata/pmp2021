#include<iostream>
using namespace std;

struct Tabular
{
	double x;
	double f;
};

double f(double x)
{
	return x;
}

/*
void tabFunct(double a, double b, double h)
{
	double x = 0;
	int n = (b - a) / h + 0.5;
	for (int i = 0; i <= n; i++)
	{
		x = a + i * h;
		cout << x << "\t" << f(x) << endl;
	}
}
*/

Tabular* tabFunct(double a, double b, double h, int& n)
{
	n = (b - a) / h + 0.5;
	Tabular* tab = new Tabular[n + 1];
	//
	for (int i = 0; i <= n; i++)
	{
		tab[i].x = a + i * h;
		tab[i].f = f(tab[i].x);
	}
	return tab;
}

void tabPrint(Tabular* arr, int n)
{
	cout << "Tab:" << endl;
	for (int i = 0; i <= n; i++)
	{
		cout << arr[i].x << "\t" << arr[i].f << endl;
	}
	cout << endl;
}

int main05bl()
{
	double a, b, h;
	int n = 0;
	//
	cout << "a = ";
	cin >> a;
	//
	do {
		cout << "b = ";
		cin >> b;
	} while (b < a);
	//
	cout << "h = ";
	cin >> h;
	//
	Tabular* arr = tabFunct(a, b, h, n);
	tabPrint(arr, n);
	//
	cout << "\ndone" << endl;
	system("pause");
	//delete[] arr; // One Dimension. Heap
	//
	return 0;
}