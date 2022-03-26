// Homework4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#define sizeMax 100

using namespace std;


void read(int matr[sizeMax][sizeMax], int& n, int& m)
{
	cout << "n=";
	cin >> n;

	cout << "m=";
	cin >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> matr[i][j];
		}
	}
}

void print(int matr[sizeMax][sizeMax], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			cout<<setw(3)<<matr[i][j]<<" ";
		}
		cout << endl;
	}
}

void sumMatr(int matr1[sizeMax][sizeMax],int matr2[sizeMax][sizeMax], int matr3[sizeMax][sizeMax],int n,int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matr3[i][j] = matr1[i][j] + matr2[i][j];
		}
	}
}


int main()
{
	int a[sizeMax][sizeMax];
	int nA;
	int mA;
	read(a, nA, mA);

	int b[sizeMax][sizeMax];
	int nB;
	int mB;
	read(b, nB, mB);

	int c[sizeMax][sizeMax];
	int nC;
	int mC;
	read(c, nC, mC);

	if (nA == nB && nA == nC && mA == mB && mA == mC)
	{
		int d[sizeMax][sizeMax];
		sumMatr(a, b, d, nA, mA);
		sumMatr(d, c, d, nA, mA);
		cout << "Sum of the matrix:"<<endl;
		print(d, nA, mA);

	}
	else
	{
		cout << "incorrect size"<<endl;
	}





}

