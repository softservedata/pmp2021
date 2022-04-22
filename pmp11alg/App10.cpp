#include<iostream>
using namespace std;

void matrixGraphGet5(int**& matrix, int& n)
{
	matrix = new int* [] {
			new int[] {1, 1, 0, 0, 0},
			new int[] {1, 1, 1, 0, 0},
			new int[] {0, 1, 1, 1, 0},
			new int[] {0, 0, 1, 1, 1},
			new int[] {0, 0, 0, 1, 1}
		};
	n = 5;
}

void matrixGraphRead(int**& matrix, int& n)
{
	cout << "\nInput new Matrix" << endl;
	if (n <= 0)
	{
		do {
			cout << "n = ";
			cin >> n;
		} while (n < 1);
	}
	//
	cout << "Input Matrix with " << n << " rows and " << n << " columns" << endl;
	matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cout << "matrix[" << i << "][" << j << "] = ";
			cin >> matrix[i][j];
		}
	}
}

void matrixGraphDelete(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void matrixGraphPrint(int** matrix, int n, const char* message)
{
	cout << "\nMatrix " << message << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << "\t ";
			//cout << *(*(matrix + i) + j) << "  ";
		}
		cout << endl;
	}
}

void matrixGraphMultiply(int**& c, int** a, int** b, int n)
{
	int sum = 0;
	c = new int* [n];
	for (int i = 0; i < n; i++)
	{
		c[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			sum = 0;
			for (int l = 0; l < n; l++)
			{
				sum = sum + a[i][l] * b[l][j];
			}
			c[i][j] = sum;
		}
	}
}

int** matrixGraphMultiply2(int** a, int** b, int n)
{
	int sum = 0;
	int** c = new int* [n];
	for (int i = 0; i < n; i++)
	{
		c[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			sum = 0;
			for (int l = 0; l < n; l++)
			{
				sum = sum + a[i][l] * b[l][j];
			}
			c[i][j] = sum;
		}
	}
	return c;
}

void matrixGraphCopy(int**& c, int** a, int n) // C style
{
	c = new int* [n];
	for (int i = 0; i < n; i++)
	{
		c[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			c[i][j] = a[i][j];
		}
	}
}

int** matrixGraphCopy2(int** a, int n) // C++ style
{
	int** c = new int* [n];
	for (int i = 0; i < n; i++)
	{
		c[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			c[i][j] = a[i][j];
		}
	}
	return c;
}

bool isRoute(int** matrix, int n, int vertexBegin, int vertexEnd)
{
	bool result = false;
	int** c = NULL;
	int** temp = NULL;
	//
	if ((n < 1) || (vertexBegin >= n) || (vertexEnd >= n))
	{
		return false;
	}
	if (matrix[vertexBegin][vertexEnd] > 0)
	{
		return true;
	}
	//
	c = matrixGraphCopy2(matrix, n);
	for (int i = 0; !result && (i < n - 1); i++)
	{
		temp = c;
		c = matrixGraphMultiply2(matrix, c, n);
		matrixGraphDelete(temp, n);
		result = (c[vertexBegin][vertexEnd] > 0);
		cout << "c[vertexBegin][vertexEnd] = " << c[vertexBegin][vertexEnd] << endl;
		matrixGraphPrint(c, n, "C");
	}
	matrixGraphDelete(c, n);
	return result;
}

int main10a()
{
	/*
	int** a = NULL; // NULL = 0
	int** b = NULL;
	int** c = NULL;
	int n = 0;
	//
	//matrixGraphRead(a, n);
	matrixGraphGet5(a, n);
	matrixGraphPrint(a, n, "Origin A");
	//
	matrixGraphMultiply(c, a, a, n);
	matrixGraphPrint(c, n, "A^2");
	//
	//matrixGraphCopy(b, c, n);
	b = matrixGraphCopy2(c, n);
	matrixGraphPrint(b, n, "B=C=A^2");
	matrixGraphMultiply(c, a, b, n);
	matrixGraphPrint(c, n, "A^3");
	//
	matrixGraphDelete(a, n);
	matrixGraphDelete(b, n);
	matrixGraphDelete(c, n);
	*/
	//
	int** a = NULL; // NULL = 0
	int n = 0;
	matrixGraphGet5(a, n);
	cout << "isRoute = " << isRoute(a, n, 0, 4) << endl;
	matrixGraphDelete(a, n);
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
