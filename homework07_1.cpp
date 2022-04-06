#include<iostream>
using namespace std;

void createMatr(int** matr, int n)
{
	for (int i = 0; i < n; i++)
	{
		matr[i] = new int[n];
	}
}

void readMatr(int** matr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Matr[" << i << "][" << j << "] = ";
			cin >> matr[i][j];
		}
	}
}

void printMatr(int** matr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
}


void delMatr(int** matr, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matr[i];
	}
	delete[] matr;
}

void transponMatr(int** matr1, int** matr2, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matr2[i][j] = matr1[j][i];
		}
	}
}


int main()
{

	int n;
	cout << "Enter the number of rows and columns of the matrix = ";
	cin >> n;

	int** matr = new int* [n];
	int** matrT = new int* [n];

	createMatr(matr, n);
	readMatr(matr, n);

	cout << "Matrix:" << endl;
	printMatr(matr, n);
	cout << endl;

	createMatr(matrT, n);
	transponMatr(matr,matrT,n);
	cout << "Transposed matrix:" << endl;
	printMatr(matrT, n);
	

	delMatr(matr, n);
	delMatr(matrT, n);

	return 0;
	system("pause");
}