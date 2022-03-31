#include<iostream>
using namespace std;

void matrixGet4x3(int**& matrix, int& countRows, int& countColumns)
{
	matrix = new int* [] { new int[] {0, 1, 1}, new int[] {1, 1, 1}, new int[] {1, 2, 1}, new int[] {1, 1, 2} };
	countRows = 4;
	countColumns = 3;
}

void matrixGet2x4(int**& matrix, int& countRows, int& countColumns)
{
	matrix = new int* [] { new int[] {1, 1, 0, 0}, new int[] {0, 1, 0, 1} };
	countRows = 2;
	countColumns = 4;
}

void matrixRead(int**& matrix, int& countRows, int& countColumns)
{
	cout << "\nInput new Matrix" << endl;
	if (countRows <= 0)
	{
		do {
			cout << "countRows = ";
			cin >> countRows;
		} while (countRows < 1);
	}
	if (countColumns <= 0)
	{
		do {
			cout << "countColumns = ";
			cin >> countColumns;
		} while (countColumns < 1);
	}
	//
	cout << "Input Matrix with " << countRows << " rows and " << countColumns << " columns" << endl;
	matrix = new int* [countRows];
	for (int i = 0; i < countRows; i++)
	{
		matrix[i] = new int[countColumns];
		for (int j = 0; j < countColumns; j++)
		{
			cout << "matrix[" << i << "][" << j << "] = ";
			cin >> matrix[i][j];
		}
	}
}

void matrixDelete(int** matrix, int countRows, int countColumns)
{
	for (int i = 0; i < countRows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void matrixPrint(int** matrix, int countRows, int countColumns, const char* message)
{
	cout << "\nMatrix " << message << endl;
	for (int i = 0; i < countRows; i++)
	{
		for (int j = 0; j < countColumns; j++)
		{
			cout << matrix[i][j] << "\t ";
			//cout << *(*(matrix + i) + j) << "  ";
		}
		cout << endl;
	}
}

void matrixMultiply(int**& c, int** a, int** b, int m, int k, int n)
{
	int sum = 0;
	c = new int* [m];
	for (int i = 0; i < m; i++)
	{
		c[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			sum = 0;
			for (int l = 0; l < k; l++)
			{
				sum = sum + a[i][l] * b[l][j];
			}
			c[i][j] = sum;
		}
	}
}

int main06a()
{
	int** a = NULL; // NULL = 0
	int** b = NULL;
	int** c = NULL;
	int m = 0;
	int k = 0;
	int n = 0;
	//
	//matrixRead(a, m, k);
	//matrixRead(b, k, n);
	matrixGet2x4(a, m, k);
	matrixGet4x3(b, k, n);
	//
	matrixMultiply(c, a, b, m, k, n);
	//
	matrixPrint(a, m, k, "A");
	matrixPrint(b, k, n, "B");
	matrixPrint(c, m, n, "C");
	// 
	//
	matrixDelete(a, m, k);
	matrixDelete(b, k, n);
	matrixDelete(c, m, n);
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
