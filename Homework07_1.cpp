#include <iostream>
using namespace std;

double** input(double** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			cout << "[" << i << "][" << j << "]=";
			cin >> arr[i][j];
		}
	}
	return arr;
}

void print_matrix(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

void func (double** matrix, int n)
{
	int a=0, b=0;
	while (true)
	{
		for (int i = 0; i < n; i++)
		{
			cout<<matrix[i][a]<<" ";
		}

		cout << "\n";

		a++;

		if (a==n)
		{
			break;
		}
	}
}

int main()
{
	int n;
	cout << "Enter the size of the matrix" << endl;
	cout << "n=";
	cin >> n;
	const int m = n;

	double** matrix_1 = new double* [n];
	double** matrix_2 = new double* [n];
	cout << "Matrix 1" << endl;
	matrix_1 = input(matrix_1, n);
	cout << "\n";

	print_matrix(matrix_1, n);
	cout << "\n";
	func(matrix_1,n);
}