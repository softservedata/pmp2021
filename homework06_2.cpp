#include <iostream>
using namespace std;

double** Read_matrix(int row, int column)
{
	double** matr = new double* [row];
	for (int i = 0; i < row; i++)
		matr[i] = new double[column];
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

void Print_matrix(double** matr, int row, int column, const char* massage)
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

void Delete_matrix(double** matr, int row, int column)
{
	for (int i = 0; i < row; i++)
		delete[] matr[i];
	delete[] matr;
}

void Checking(double** matr, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (abs(matr[i][i]) > abs(matr[i][j])) count++;
	if (count==n)
		cout << "Matrix has diagonal advantage" << endl;
	else cout << "Matrix hasn't diagonal advantage" << endl;
}

int main06b()
{
	int n;
	cout << "Enter size of matrix: ";
	cin >> n;
	cout << endl;

	double** matr = Read_matrix(n, n);
	Print_matrix(matr, n, n, "Input ");

	Checking(matr, n);

	Delete_matrix(matr, n, n);

	system("pause");
	return 0;
}