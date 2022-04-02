#include<iostream>
using namespace std;

// Overload
/*
void work(int i)
{
	cout << "\tstart work i = " << i << endl;
	i = i + 1;
	cout << "\tdone work i = " << i << endl;
}
*/

// Overload
/*
void work(int* a)
{
	cout << "\tstart work a[0] = " << a[0] << "  a[1] = " << a[1] << endl;
	a[0] = 31;
	cout << "\tdone work a[0] = " << a[0] << "  a[1] = " << a[1] << endl;
}
*/

void work(double* d)
{
	cout << "\tstart work address d = " << d << "  value d = " << *d << endl;
	cout << "\tinput d = ";
	cin >> *d;
	cout << "\tdone work address d = " << d << "  value d = " << *d << endl;
}

void work(string s)
{
	cout << "\tstart work s = " << s << endl;
	s = s + "123";
	cout << "\tdone work s = " << s << endl;
}

void work(int& i)
{
	cout << "\tstart work i = " << i << endl;
	i = i + 1;
	cout << "\tdone work i = " << i << endl;
}

void work(int*& a)
{
	cout << "\tstart work a = " << a << endl;
	a = new int[2];
	a[0] = 31;
	a[1] = 32;
	cout << "\tdone work a = " << a << " a[0] = " << a[0] << "  a[1] = " << a[1] << endl;
}

double x1(double x)
{
	return x;
}

double x2(double x)
{
	return x * x;
}

double getIntegral(double a, double b, int n)
{
	double x;
	double h = (b - a) / n;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		x = a + i * h;
		sum = sum + x1(x);
	}
	return sum * h;
}

int main06al()
{
	// 1. By Value, value Type
	/*
	int i;
	i = 1;
	cout << "start main i = " << i << endl;
	work(i);
	cout << "done main i = " << i << endl;
	*/
	//
	// 2. By Value, Reference Type
	// Create in Stack
	// int a[2];
	// Create in Heap
	/*
	int* a;
	a = new int[2];
	a[0] = 11;
	a[1] = 12;
	cout << "start main a[0] = " << a[0] << "  a[1] = " << a[1] << endl;
	work(a);
	cout << "done main a[0] = " << a[0] << "  a[1] = " << a[1] << endl;
	delete[] a; // if Create in Heap
	*/
	//
	// 2.1. By Value, Reference Type. Read Parameters
	/*
	double d;
	d = 11;
	cout << "start main d = " << d << endl;
	work(&d);
	cout << "done main d = " << d << endl;
	*/
	//
	// 3. By Value, Reference Immutable Type.
	/*
	string s;
	s = "abc";
	cout << "start main s = " << s << endl;
	work(s);
	cout << "done main s = " << s << endl;
	*/
	//
	// 4. By reference, Value Type
	/*
	int i;
	i = 1;
	cout << "start main i = " << i << endl;
	work(i);
	cout << "done main i = " << i << endl;
	*/
	//
	// 5. By reference, Reference Type
	/*
	int* a; // Object will Create in work
	a = NULL;
	cout << "start main a = " << a << endl;
	work(a);
	cout << "done main a[0] = " << a[0] << "  a[1] = " << a[1] << endl;
	delete[] a; // if Create in Heap
	*/
	//
	// By Name
	double a = 1;
	double b = 2;
	int n = 1000;
	cout << "Integral = " << getIntegral(a, b, n) << endl;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
