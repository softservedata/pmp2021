#include <iostream>
using namespace std;

double** readMatr(int n);
void printMatr(double** matr, int n);
void delMatr(double** matr, int n);
void sortMatr(double**& matr, int n);

int main()
{

	int n;
	cout << "Enter the number of rows and columns of the matrix = ";
	cin >> n;


	cout << "Enter the elements of the matrix:" << endl;
	double** matr = readMatr(n);

	cout << "Result matr: " << endl;

	sortMatr(matr, n);
	printMatr(matr, n);

	delMatr(matr, n);

	
	return 0;
	system("pause");
}


double** readMatr(int n)
{
	double** matr = new double* [n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			cout << "Matr[" << i << "][" << j << "] = ";
			cin >> matr[i][j];
		}
	}
	return matr;
}


void printMatr(double** matr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
}


void delMatr(double** matr, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matr[i];
	}
	delete[] matr;
}


void sortMatr(double**& matr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (matr[j + 1][0] < matr[j][0])
			{
				for (int t = 0; t < n; t++)
				{
					double temp = matr[j][t];
					matr[j][t] = matr[j + 1][t];
					matr[j + 1][t] = temp;
				}
			}
		}
	}
}