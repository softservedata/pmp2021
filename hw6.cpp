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

void diagonal_perevMatr(double** matr, int n)
{
	int countelsatisfy = 0;
	int l = 0;
	for (int i = 0; i < n; i++)
	{
		double sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				sum += matr[i][j];
			}
		}
		if (matr[i][l] >= sum)
		{
			countelsatisfy++;
		}
		l++;
	}
	cout << "Count elem that satisfy: " << countelsatisfy;
	if (countelsatisfy == n)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

}


int main()
{

	int n;
	cout << "Enter the number of rows and columns of the matrix = ";
	cin >> n;


	cout << "Enter the elements of the matrix:" << endl;
	double** matr = readMatr(n);

	cout << "Matrix:" << endl;
	printMatr(matr, n);
	cout << endl;


	 diagonal_perevMatr(matr, n);

	delMatr(matr, n);

	return 0;
	system("pause");
}