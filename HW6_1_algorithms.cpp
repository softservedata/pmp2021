#include <iostream>
using namespace std;

int** Read_Matrix(int row, int column, const char* massage)
{
	int** matr = new int* [row];
	for (int i = 0; i < row; i++)
		matr[i] = new int[column];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << "Matr_" << massage << "[" << i << "]" << "[" << j << "] = ";
			cin >> matr[i][j];
		}
	}
	return matr;
}

void Print_Matrix(int** matr, int row, int column, const char* massage)
{
	cout << massage << "matrix" << ":" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			cout << matr[i][j] << '\t';
		cout << endl;
	}
	cout << endl;
}


void Delete_Matrix(int** Arr, int row, int column)
{
	for (int i = 0; i < row; i++)
		delete[] Arr[i];
	delete[] Arr;
}

void Pow_Matrix(int** a, int** b, int row, int column)
{
	int sum = 0;
	int** c = new int* [column];
	for (int i = 0; i < column; i++)
		c[i] = new int[row];

	int** d = new int* [column];
	for (int i = 0; i < column; i++)
		d[i] = new int[row];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			c[i][j] = a[i][j] - b[i][j];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
		{
			sum = 0;
			for (int l = 0; l < column; l++)
				sum += c[i][l] * c[l][j];
			d[i][j] = sum;
		}

	Print_Matrix(d, row, column, "(A-B)^2");
	Delete_Matrix(d, row, column);
}


int main06a()
{
	do
	{
		int n;
		cout << "Enter size of matrix: ";
		cin >> n;
		cout << endl;

		int** matr_a = Read_Matrix(n, n, "A");
		Print_Matrix(matr_a, n, n, "A");

		int** matr_b = Read_Matrix(n, n, "B");
		Print_Matrix(matr_b, n, n, "B");

		Pow_Matrix(matr_a, matr_b, n, n);

		Delete_Matrix(matr_a, n, n);
		Delete_Matrix(matr_b, n, n);
	} while (true);

	system("pause");
	return 0;
}