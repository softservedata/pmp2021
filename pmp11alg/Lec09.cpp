#include<iostream>
using namespace std;


int meth1()
{
	int i = 345;
	cout << "i = " << i << "  &i = " << &i << endl;
	return i;
	//return 123;
}

int* meth2()
{
	int i = 345;
	cout << "i = " << i << "  &i = " << &i << endl;
	return &i;
	//return 123;
}

int& meth3()
{
	//static int i = 345; // static OK
	int i = 345; // static OK
	cout << "i = " << i << "  &i = " << &i << endl;
	return i;
	//return 123;
}

int sum1(int* arr, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum + arr[i];
	}
	return sum;
}

int sum2rec(int* arr, int n)
{
	if (n == 0)
	{
		return 0;
	}
	return arr[n - 1] + sum2rec(arr, n - 1);
}

int sum3merge(int* arr, int p, int r)
{
	if (p == r)
	{
		return arr[p];
	}
	int q = (p + r) / 2;
	return sum3merge(arr, p, q) + sum3merge(arr, q + 1, r);
}

int main09al()
{
	/*
	//int k = meth1();
	//cout << "k = " << k << "  k = " << &k << endl;
	//
	//int* k = meth2(); // ERROR
	//cout << "k = " << k << "  *k = " << *k << endl;
	//int k = *meth2(); // Ok
	//cout << "k = " << k << "  &k = " << &k << endl;
	// 
	//int& k = meth3(); // Err
	//cout << "k = " << k << "  &k = " << &k << endl;
	//
	int k = meth3(); // Ok
	cout << "k = " << k << "  &k = " << &k << endl;
	cout << "meth3() = " << meth3() << endl; // Err
	*/
	//
	// Sum
	int n = 8;
	int* arr = new int[] { 4, 8, 2, 9, 1, 3, 5, 6 };
	//int sum = 0;
	//
	/*
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum + arr[i];
	}
	*/
	//
	//cout << "sum1() = " << sum1(arr, n) << endl;
	//cout << "sum2rec() = " << sum2rec(arr, n) << endl;
	cout << "sum3merge() = " << sum3merge(arr, 0, n - 1) << endl;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}