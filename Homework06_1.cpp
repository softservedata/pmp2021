#include <iostream>
using namespace std;


int** input(int** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cout << "[" << i << "][" << j << "]=";
			cin >> arr[i][j];
		}
	}
	return arr;
}

void print_matrix(int** matrix, int n)
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

int** mno(int** arr, int n)
{
	int* element[1000]{};
	long long a=0, b=0,c=0, chuslo_1,chuslo_2,sum=0,lichba;
	lichba = n * n;
	while (true)
	{
		for (int i = 0; i < n; i++)
		{
			chuslo_1 = arr[a][i];
			chuslo_2 = arr[i][b];
			sum += chuslo_1 * chuslo_2;
		}

		cout << sum << " ";
		c++;
		if (c==3)
		{
			cout << "\n";
			c = 0;
		}

		b++;
		if (b >= n)
		{
			b = 0;
			a++;
		}
		sum = 0;

		lichba--;
		if (lichba==0)
		{
			break;
		}
	}
	return 0;
}



int main()
{
	int n;
	cout << "Enter the size of the matrix" << endl;
	cout << "n=";
	cin >> n;
	const int m = n;

	int** matrix_1 = new int* [n];
	int** matrix_2 = new int* [n];
	int** matrix_3 = new int* [n];
	int** matrix_4 = new int* [n];

	cout << "Matrix 1" << endl;
	matrix_1 = input(matrix_1, n);
	cout << "\n";
	cout << "Matrix 2" << endl;
	matrix_2 = input(matrix_2, n);

	for (int i = 0; i < n; i++)
	{
		matrix_3[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			matrix_3[i][j] = matrix_1[i][j] - matrix_2[i][j];
		}
	}

	mno(matrix_3, n);

}