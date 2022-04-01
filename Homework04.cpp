#include<iostream>
using namespace std;



double** read_matr(int n) {
	double** matr = new double* [n];
	for (int i = 0; i < n; ++i) 
	{
		matr[i] = new double[n];
		for (int j = 0; j < n; ++j)
		{
			cin >> matr[i][j];
		}
	}
	return matr;
}


void print_matr(double** matr, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
}


void delet(double** matr, int n) {
	for (int i = 0; i < n; ++i) {
		delete[] matr[i];
	}
	delete[] matr;
}


double** zeros(int n) {
	double** matr = new double* [n];
	for (int i = 0; i < n; ++i) {
		matr[i] = new double[n];
		for (int j = 0; j < n; ++j) {
			matr[i][j] = 0;
		}
	}
	return matr;
}


double** sum_matr(double** matr1, double** matr2, double** matr3, int n) {
	double** matr = zeros(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			matr[i][j] = matr1[i][j] + matr2[i][j] + matr3[i][j];
		}
	}
	return matr;
}


int main()
{
	
	int n;
	cout << "Please enter number of rows and coloms: ";
	cin >> n;
	cout << "Enter first matrix's elements: " << endl;
	double** matr1 = read_matr(n);
	cout << "Enter second matrix's elements: " << endl;
	double** matr2 = read_matr(n);
	cout << "Enter third matrix's elements: " << endl;
	double** matr3 = read_matr(n);
	double** summatr = sum_matr(matr1, matr2, matr3, n);
	cout << "Sum our matrix: " << endl;
	print_matr(summatr, n);


	delet(matr1, n);
	delet(matr2, n);
	delet(matr3, n);
	delet(summatr, n);

	return 0;
	system("pause");
}



