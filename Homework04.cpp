#include <iostream>
using namespace std;


int** input(int** arr, int n, int m)
{

	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			cout << "[" << i << "][" << j << "]=";
			cin >> arr[i][j];
		}
	}
	return arr;
}

void print_matrix(int** matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}


int main()
{
	int n, m;
	cout << "size:" << endl;
	cout << "n=";
	cin >> n;
	cout << "m=";
	cin >> m;

	int** matrix_first = new int* [n];
	int** matrix_second = new int* [n];
	int** matrix_third = new int* [n];
	int** matrix_fourth = new int* [n];

	cout << "Matrix 1" << endl;
	matrix_first = input(matrix_first, n, m);
	cout << "\n";
	cout << "Matrix 2" << endl;
	matrix_second = input(matrix_second, n, m);
	cout << "\n";
	cout << "Matrix 3" << endl;
	matrix_third = input(matrix_third, n, m);

	cout << "\n";

	for (int i = 0; i < n; i++)
	{
		matrix_fourth[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			matrix_fourth[i][j] = matrix_first[i][j] + matrix_second[i][j] + matrix_third[i][j];
		}
	}
	cout << "sum" << endl;
	print_matrix(matrix_fourth, n, m);