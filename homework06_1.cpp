#include<iostream>
using namespace std;

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


double** zeroMatr(int n)
{
	double** matr = new double* [n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new double[n];

		for (int j = 0; j < n; j++)
		{
			matr[i][j] = 0;
		}
	}
	return matr;
}



double** subtractionMatr(double** matr1, double** matr2, int n)
{
	double** matr = zeroMatr(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			matr[i][j] = matr1[i][j] - matr2[i][j];
		}
	}
	return matr;
}
double** squareMatr(double** matr1, double** matr2, int n)
{
	double** matr = new double* [n];
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		matr[i] = new double[n];
		for (int j = 0; j < n; j++) 
		{
			for (int l = 0; l < n; l++)
			{
				sum += matr1[i][l] * matr2[l][j];
			}
			matr[i][j] = sum;
			sum = 0;
		}
	}
	return matr;
}


int main()
{

	int n;
	cout << "Enter the number of rows and columns of the matrix = ";
	cin >> n;


	cout << "Enter the elements of the first matrix:" << endl;
	double** matr1 = readMatr(n);

	cout << "Enter the elements of the second matrix:" << endl;
	double** matr2 = readMatr(n);


	cout << "First matrix:" << endl;
	printMatr(matr1, n);
	cout << endl;

	cout << "Second matrix:" << endl;
	printMatr(matr2, n);
	cout << endl;



	double** submatr = subtractionMatr(matr1, matr2, n);
	cout << "Substraction matr:" << endl;
	printMatr(submatr, n);


	double** resmatr = squareMatr(submatr, submatr, n);
	cout << "Result matr:" << endl;
	printMatr(resmatr, n);


	delMatr(matr1, n);

	delMatr(matr2, n);

	delMatr(submatr, n);

	delMatr(resmatr, n);

	return 0;
	system("pause");
}