#include <iostream>
using namespace std;


int** input(int** arr , int n, int m)
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
			cout << matrix[i][j]<<" ";
		}
		cout << "\n";
	}
}


int main()
{
	int n, m;
	cout << "Enter the size of the matrix"<<endl;
	cout << "n=";
	cin >> n ;
	cout << "m=";
	cin >> m;

	int** matrix_1 = new int* [n];
	int** matrix_2 = new int* [n];
	int** matrix_3 = new int* [n];
	int** matrix_4 = new int* [n];

	cout << "Matrix 1" << endl;
	matrix_1 = input(matrix_1,n, m);
	cout << "\n";
	cout << "Matrix 2" << endl;
	matrix_2= input(matrix_2, n, m);
	cout << "\n";
	cout << "Matrix 3" << endl;
	matrix_3= input(matrix_3, n, m);

	cout << "\n";

	for (int i = 0; i < n; i++)
	{
		matrix_4[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			matrix_4[i][j] = matrix_1[i][j] + matrix_2[i][j] + matrix_3[i][j];
		}
	}
	cout << "Sum" << endl;
	print_matrix(matrix_4, n, m);

}