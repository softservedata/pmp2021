#include <iostream>
using namespace std;

struct Matrix
{
	int** matr;
	int row;
	int column;
	~Matrix()
	{
		//cout << "\nDestructor" << endl;
		for (int i = 0; i < row; i++)
		{
			delete[] matr[i];
		}
		delete[] matr;
	}
};

void Read_Matrix_Struct(Matrix*& matrix, int row = 0, int column = 0)
{
	matrix = new Matrix();
	//cout << "\nInput new Matrix" << endl;
	if (row <= 0)
	{
		do {
			cout << "row = ";
			cin >> matrix->row;
		} while (matrix->row < 1);
	}
	else matrix->row = row;
	if (column <= 0)
	{
		do {
			cout << "column = ";
			cin >> matrix->column;
		} while (matrix->column < 1);
	}
	else matrix->column = column;
	//cout << "Input Matrix with " << matrix->row << " rows and " << matrix->column << " columns" << endl;
	matrix->matr = new int* [matrix->row];
	for (int i = 0; i < matrix->row; i++)
	{
		matrix->matr[i] = new int[matrix->column];
		for (int j = 0; j < matrix->column; j++)
		{
			cout << "matrix[" << i << "][" << j << "] = ";
			cin >> matrix->matr[i][j];
		}
	}
}

void Print_Matrix_Struct(Matrix*& matrix, const char* message)
{
	cout << message << "matrix" << endl;
	for (int i = 0; i < matrix->row; i++)
	{
		for (int j = 0; j < matrix->column; j++)
		{
			cout << matrix->matr[i][j] << "\t "; //cout << *(*((*matrix).arr + i) + j) << "  ";
		}
		cout << endl;
	}
}

void Delete_Matrix_Struct(Matrix*& matrix)
{
	delete matrix;
}

void Transposed_Matrix_Struct(Matrix*& matr_new)
{
	matr_new = new Matrix();
	matr_new->matr = new int* [matr_new->row];
	for (int i = 0; i < matr_new->row; i++)
	{
		matr_new->matr[i] = new int[matr_new->column];
		for (int j = 0; j < matr_new->column; j++)
				matr_new->matr[i][j] = matr_new->matr[j][i];
	}
	Print_Matrix_Struct(matr_new, "Transposed ");
	Delete_Matrix_Struct(matr_new);
}

int** read_matrix(int row, int column)
{
	int** matr = new int* [row];
	for (int i = 0; i < row; i++)
		matr[i] = new int[column];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << "Matr" << "[" << i << "]" << "[" << j << "] = ";
			cin >> matr[i][j];
		}
	}
	return matr;
}

void print_matrix(int** matr, int row, int column, const char* massage)
{
	cout << massage << "matrix:" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			cout << matr[i][j] << '\t';
		cout << endl;
	}
	cout << endl;
}

void delete_matrix(int** matr, int row, int column)
{
	for (int i = 0; i < row; i++)
		delete[] matr[i];
	delete[] matr;
}

void transposed_matrix(int** matr, int row, int column)
{
	int** matr_new = new int* [column];
	for (int i = 0; i < column; i++)
		matr_new[i] = new int[row];
	for (int i = 0; i < column; i++)
		for (int j = 0; j < row; j++)
		{
			matr_new[i][j] = matr[j][i];
		}
	print_matrix(matr_new, row, column, "Transposed ");
	delete_matrix(matr_new, row, column);
}

int main()
{
	int n;
	cout << "Enter size of matrix: ";
	cin >> n;
	cout << endl;

	int** matr = read_matrix(n, n);
	print_matrix(matr, n, n, "Input ");
	transposed_matrix(matr, n, n);
	delete_matrix(matr, n, n);

	cout << "Input new matrix:" << endl;
	Matrix* matrix = NULL;
	Read_Matrix_Struct(matrix, n, n);
	Print_Matrix_Struct(matrix, "Input ");
	Transposed_Matrix_Struct(matrix);
	Delete_Matrix_Struct(matrix);

	system("pause");
	return 0;
}
