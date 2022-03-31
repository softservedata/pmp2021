#include<iostream>
using namespace std;
void ReadMatrix(int** arr, const int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Element [" << i + 1 << "] [" << j + 1 << "] = ";
			cin >> arr[i][j];
		}
	}

}

void PrintMatrix(int** arr, const int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

}

int main() {
	int n;
	cout << "n = ";
	cin >> n;
	cout << "\nEnter 1 matrix A >> " << endl;

	int** a = new int* [n];
	for (int i = 0; i < n; ++i)
		a[i] = new int[n];

	ReadMatrix(a, n);
	cout << "\nA matrix: " << endl;
	PrintMatrix(a, n);

	cout << "\nEnter 2 matrix B >>  " << endl;

	int** b = new int* [n];
	for (int i = 0; i < n; ++i)
		b[i] = new int[n];

	ReadMatrix(b, n);
	cout << "\nB matrix: " << endl;

	PrintMatrix(b, n);

	cout << "\nEnter 3 matrix C >>" << endl;

	int** c = new int* [n];
	for (int i = 0; i < n; ++i)
		c[i] = new int[n];

	ReadMatrix(c, n);

	cout << "\nC matrix is:" << endl;

	PrintMatrix(c, n);

	int** d;
	d = new int* [n];

	for (int i = 0; i < n; ++i)
		d[i] = new int[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = *(*(a + i) + j) + *(*(b + i) + j) + *(*(c + i) + j);
		}
	}

	cout << "\nResult is: " << "\nD matrix = " << endl;

	PrintMatrix(d, n);

	return 0;

}