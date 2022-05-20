#include <iostream>
using namespace std;

double** vvid_matr(int n)
{
	double** matrix = new double* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[n];

		for (int j = 0; j < n; j++)
		{
			cout << "matrix[" << i << "][" << j << "]= ";
			cin >> matrix[i][j];
		}
	}
	return matrix;
}

void vuvid_matr(double** matrix, int n)
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

void alhor(double** matrix, int n)
{
	int copy_n = n - 1;
	int a = 0;
	int start = 1;
	bool check = true;

	while (copy_n!=0)
	{
		for (int i = start; i < n; i++)
		{
			if (matrix[a][i]!=matrix[i][a])
			{
				check = false;
			}
		}

		a++;
		start++;
		copy_n--;
	}

	if (check==false)
	{
		cout << "The matrix isn't symmetric";
	}
	else
	{
		cout << "The matrix is symmetric";
	}

}


int main()
{
	int n;
	cout << "Enter n ";
	cin >> n;

	double** matrix = vvid_matr(n);
	vuvid_matr(matrix, n);
	alhor(matrix, n);

}