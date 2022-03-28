#include<iostream>
using namespace std;

void read(int** arr, const int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "elem[" << i + 1 << "] [" << j + 1 << "] = ";
			cin >> arr[i][j];
		}
	}
}
void print(int** arr, const int n) {
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
	cout << "\nenter A matrix : " << endl;
	int** a = new int* [n];
	for (int i = 0; i < n; ++i)
		a[i] = new int[n];
	read(a, n);
	cout << "\nA matrix is:" << endl;
	print(a, n);
	cout << "\nenter B matrix:" << endl;
	int** b = new int* [n];
	for (int i = 0; i < n; ++i)
		b[i] = new int[n];
	read(b, n);
	cout << "\nB matrix is:" << endl;
	print(b, n);
	cout << "\nenter C matrix:" << endl;
	int** c = new int* [n];
	for (int i = 0; i < n; ++i)
		c[i] = new int[n];
	read(c, n);
	cout << "\nC matrix is:" << endl;
	print(c, n);
	int** d;
	d = new int* [n];
	for (int i = 0; i < n; ++i)
		d[i] = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = *(*(a + i) + j) + *(*(b + i) + j) + *(*(c + i) + j);
		}
	}
	cout << "\nResult" << "\nD matrix :" << endl;
	print(d, n);
	return 0;
}