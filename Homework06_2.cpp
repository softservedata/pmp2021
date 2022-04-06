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

void print_matrix (double** matrix, int n)
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

void function(double** matrix, int n)
{
	int a,lichba_main=0,perevirka;
	a = n - 1;
	while (true)
	{
		perevirka = abs(matrix[a][a]);
		for (int i = 0; i < n; i++)
		{
			if (i!=a)
			{
				if (perevirka<matrix[a][i])
				{
					lichba_main++;
				}
			}

			if (lichba_main>0)
			{
				break;
			}

		}
		a--;
		if (a<0 || lichba_main>0)
		{
			break;
		}
	}

	if (lichba_main>0)
	{
		cout << "Does not have a diagonal advantage";
	}
	else
	{
		cout << "Has a diagonal advantage";
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
	cout << "Matrix 1" << endl;
	matrix_1 = input(matrix_1, n);
	cout << "\n";

	print_matrix(matrix_1,n);
	cout << "\n";
	function(matrix_1, n);
	cout << "\n";
}