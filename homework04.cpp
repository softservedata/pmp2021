#include<iostream>
using namespace std;

float** readMatr(int n,int m)
{
	float** matr = new float* [n];
	for (int i = 0; i < n; i++) 
	{
		matr[i] = new float[m];
		for (int j = 0; j < m; j++) 
		{
			cout << "Matr[" << i << "][" << j << "] = ";
			cin >> matr[i][j];
		}
	}
	return matr;
} 


void printMatr(float** matr, int n, int m) 
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
}


void delMatr(float** matr, int n) 
{
	for (int i = 0; i < n; i++) 
	{
		delete[] matr[i];
	}
	delete[] matr;
}


float** resMatr(int n,int m) 
{
	float** matr = new float* [n];
	for (int i = 0; i < n; i++) 
	{
		matr[i] = new float[n];

		for (int j = 0; j < m; j++) 
		{
			matr[i][j] = 0;
		}
	}
	return matr;
}



float** sumMatr(float** matr1, float** matr2, float** matr3, int n, int m) 
{
	float** matr = resMatr(n, m);
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) {
			matr[i][j] = matr1[i][j] + matr2[i][j] + matr3[i][j];
		}
	}
	return matr;
}


int main()
{
	
	int n, m;
	cout << "Enter the number of rows of the matrix = ";
	cin >> n;

	cout << "Enter the number of columns in the matrix = ";
	cin >> m;


	cout << "Enter the elements of the first matrix:" << endl;
	float** matr1 = readMatr(n,m);

	cout << "Enter the elements of the second matrix:" << endl;
	float** matr2 = readMatr(n,m);

	cout << "Enter the elements of the third matrix:" << endl;
	float** matr3 = readMatr(n,m);

	cout << "First matrix:" << endl;
	printMatr(matr1, n, m);
	cout << endl;

	cout << "Second matrix:" << endl;
	printMatr(matr2, n, m);
	cout << endl;

	cout << "Third matrix:" << endl;
	printMatr(matr3, n, m);
	cout << endl;


	float** resmatr = sumMatr(matr1, matr2, matr3, n,m);

	cout << "Sum of matrices:" << endl;
	printMatr(resmatr, n, m);


	delMatr(matr1, n);

	delMatr(matr2, n);

	delMatr(matr3, n);

	delMatr(resmatr,n);

	return 0;
	system("pause");
}