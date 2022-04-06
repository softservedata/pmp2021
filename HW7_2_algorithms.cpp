#include <iostream>
using namespace std;

int** read_Matrix(int row, int column)
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

void print_Matrix(int** matr, int row, int column, const char* massage)
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

void delete_Matrix(int**& matr, int row)
{
	for (int i = 0; i < row; i++)
		delete[] matr[i];
	delete[] matr;
}

int** Transposed_matrix(int** matr, int row, int column)
{
	int** matr_new = new int* [column];
	for (int i = 0; i < column; i++)
		matr_new[i] = new int[row];
	for (int i = 0; i < column; i++)
		for (int j = 0; j < row; j++)
		{
			matr_new[i][j] = matr[j][i];
		}
	return matr_new;
}

const char* Cheking (int** matr, int row, int column)
{
	int** temp_matr = Transposed_matrix(matr, row, column);
	for (int i = 0; i < column; i++)
		for (int j = 0; j < row; j++)
			if (matr[i][j] != temp_matr[i][j]) return "Matrix isn't symmetrical";
	return "Matrix is symmetrical";
}

int main07b()
{
	int n;
	cout << "Enter size of matrix: ";
	cin >> n;
	cout << endl;

	int** matr = read_Matrix(n, n);
	print_Matrix(matr, n, n, "Input ");

	cout << Cheking(matr, n, n) << endl;

	delete_Matrix(matr, n);

	system("pause");
	return 0;
}