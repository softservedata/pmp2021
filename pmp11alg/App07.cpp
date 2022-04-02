#include<iostream>
using namespace std;

struct Matrix
{
	int** arr;
	int rows;
	int columns;
	//
	// Destructor
	~Matrix()
	{
		cout << "\nDestructor" << endl;
		for (int i = 0; i < rows; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}
};

void matrixGet4x3Struct(Matrix*& matrix)
{
	matrix = new Matrix();
	matrix->arr = new int* [] { new int[] {0, 1, 1}, new int[] {1, 1, 1}, new int[] {1, 2, 1}, new int[] {1, 1, 2} };
	(*matrix).rows = 4;
	matrix->columns = 3;
}

void matrixGet2x4Struct(Matrix*& matrix)
{
	matrix = new Matrix();
	matrix->arr = new int* [] { new int[] {1, 1, 0, 0}, new int[] {0, 1, 0, 1} };
	matrix->rows = 2;
	matrix->columns = 4;
}

void matrixReadStruct(Matrix*& matrix, int countRows = 0, int countColumns = 0)
{
	matrix = new Matrix();
	cout << "\nInput new Matrix" << endl;
	if (countRows <= 0)
	{
		do {
			cout << "countRows = ";
			cin >> matrix->rows;
		} while (matrix->rows < 1);
	}
	else
	{
		matrix->rows = countRows;
	}
	if (countColumns <= 0)
	{
		do {
			cout << "countColumns = ";
			cin >> matrix->columns;
		} while (matrix->columns < 1);
	}
	else
	{
		matrix->columns = countColumns;
	}
	//
	cout << "Input Matrix with " << matrix->rows << " rows and " << matrix->columns << " columns" << endl;
	matrix->arr = new int* [matrix->rows];
	for (int i = 0; i < matrix->rows; i++)
	{
		matrix->arr[i] = new int[matrix->columns];
		for (int j = 0; j < matrix->columns; j++)
		{
			cout << "matrix[" << i << "][" << j << "] = ";
			cin >> matrix->arr[i][j];
		}
	}
}

void matrixDeleteStruct(Matrix* matrix)
{
	delete matrix;
}

void matrixPrintStruct(Matrix* matrix, const char* message)
{
	cout << "\nMatrix " << message << endl;
	for (int i = 0; i < matrix->rows; i++)
	{
		for (int j = 0; j < matrix->columns; j++)
		{
			cout << matrix->arr[i][j] << "\t ";
			//cout << *(*((*matrix).arr + i) + j) << "  ";
		}
		cout << endl;
	}
}

void matrixMultiplyStruct(Matrix*& c, Matrix*& a, Matrix*& b)
{
	int m = a->rows;
	int k = a->columns;
	int n = b->columns;
	//
	if (k > b->rows)
	{
		k = b->rows;
	}
	//
	c = new Matrix();
	int sum = 0;
	c->arr = new int* [m];
	for (int i = 0; i < m; i++)
	{
		c->arr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			sum = 0;
			for (int l = 0; l < k; l++)
			{
				sum = sum + a->arr[i][l] * b->arr[l][j];
			}
			c->arr[i][j] = sum;
		}
	}
	c->rows = m;
	c->columns = n;
}

int main()
{
	Matrix* a = NULL; // NULL = 0
	Matrix* b = NULL;
	Matrix* c = NULL;
	//
	matrixReadStruct(a);
	matrixReadStruct(b, a->columns);
	//matrixGet2x4Struct(a);
	//matrixGet4x3Struct(b);
	//
	matrixMultiplyStruct(c, a, b);
	//
	matrixPrintStruct(a, "A");
	matrixPrintStruct(b, "B");
	matrixPrintStruct(c, "C");
	// 
	//
	matrixDeleteStruct(a);
	matrixDeleteStruct(b);
	matrixDeleteStruct(c);
	//
	// Create in Heap
	//Matrix* matr = new Matrix();
	//delete matr;
	//
	// Create in Stack
	//Matrix matr;
	//
	/*
	int k = 123;
	cout << "k = " << k << endl;
	//
	int& k2 = k;
	k2 = 456;
	cout << "k = " << k << endl;
	//
	int* k3;
	k3 = &k;
	*k3 = 678;
	cout << "k = " << k << endl;
	*/
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
