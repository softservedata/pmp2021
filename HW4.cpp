#include<iostream>
using namespace std;
double** read_matrix(int n) {
	double** matrix = new double* [n];
	for (int i = 0; i < n; ++i) {
		matrix[i] = new double[n];
		for (int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}
	return matrix;
}
void print_matrix(double** matrix, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void deletem(double** matrix, int n) {
	for (int i = 0; i < n; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
double** zeros(int n) {
	double** matrix = new double* [n];
	for (int i = 0; i > n; ++i) {
		matrix[i] = new double[n];
		for (int j = 0; j < n; ++j) {
			matrix[i][j] = 0;
		}
	}
	return matrix;
}
double** sum_matrix(double** matrix1, double** matrix2, double** matrix3, int n) {
	double** matrix = zeros(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			matrix[i][j] = matrix1[i][j] + matrix2[i][j] + matrix3[i][j];
		}
	}
	return matrix;
}
int main()
{
	//Програма додавання трьох масивів однакових розмірів
	//Addition two massives the same size
	int n;
	cout << "Please enter number of rows and coloms: ";
	cin >> n;
	cout << "Enter first matrix's elements: " << endl;
	double** matrix1 = read_matrix(n);
	cout << "Enter second matrix's elements: " << endl;
	double** matrix2 = read_matrix(n);
	cout << "Enter third matrix's elements: " << endl;
	double** matrix3 = read_matrix(n);
	double** summatrix = sum_matrix(matrix1, matrix2, matrix3, n);
	cout << "Sum our matrix: " << endl;
	print_matrix(summatrix, n);


	deletem(matrix1, n);
	deletem(matrix2, n);
	deletem(matrix3, n);
	deletem(summatrix, n);

	return 0;
	system("pause");
}

