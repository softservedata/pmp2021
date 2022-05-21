#include <iostream>
using namespace std;

int** vvid_matr(int n, int m)
{
	int** matrix = new int* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];

		for (int j = 0; j < m; j++)
		{
			cout << "matrix[" << i << "][" << j << "]= ";
			cin >> matrix[i][j];
		}
	}
	return matrix;
}


void vuvid_matr(int** matrix, int n, int m)
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

void program(int** matrix, int n, int m)
{

	int arr_temp[100];

	int n_copy = n;

	int a = 0;

	while (n_copy!=0)
	{
		for (int i = 0; i < m; i++)
		{
			arr_temp[i] = matrix[a][i];
		}

		int imax = 0;
		int max = 0;
		for (int i = 0; i < m - 1; i++)
		{
			imax = 0;
			max = arr_temp[imax];
			for (int j = 0; j < m - i; j++)
			{
				if (max < arr_temp[j])
				{
					imax = j;
					max = arr_temp[imax];
				}
			}
			arr_temp[imax] = arr_temp[m - i - 1];
			arr_temp[m - i - 1] = max;
			
		}

		for (int i = 0; i < m; i++)
		{
			cout << arr_temp[i] << " ";
		}
		cout << endl;

		a++;
		n_copy--;
	}
}

int main()
{
	int n, m;
	cout << "Enter a size of matrix ";
	cout << endl;
	cout << "n=";
	cin >> n;
	cout << "m=";
	cin >> m;

	int** matrix = vvid_matr(n, m);

	cout << "Matrix" << endl;
	vuvid_matr(matrix, n, m);
	cout << "Sorted matrix"<<endl;
	program(matrix, n, m);

}