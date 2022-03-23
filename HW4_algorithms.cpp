#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter m: ";
	cin >> m;
	int** aArr = new int* [m];
	for (int i = 0; i < m; i++)
		aArr[i] = new int[n];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "matrA[" << i << "]" << "[" << j << "] = ";
			cin >> aArr[i][j];
		}
	}
	cout << "Matrix A:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << aArr[i][j];
		cout << endl;
	}

	int** bArr = new int* [n];
	for (int i = 0; i < n; i++)
		bArr[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "matrB[" << i << "]" << "[" << j << "] = ";
			cin >> bArr[i][j];
		}
	}
	cout << "Matrix B:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << bArr[i][j];
		cout << endl;
	}

	int** cArr = new int* [n];
	for (int i = 0; i < n; i++)
		cArr[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "matrC[" << i << "]" << "[" << j << "] = ";
			cin >> cArr[i][j];
		}
	}
	cout << "Matrix C:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << cArr[i][j];
		cout << endl;
	}

	int** sumArr = new int* [n];
	for (int i = 0; i < n; i++)
		sumArr[i] = new int[n];
	cout << "A+B+C:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sumArr[i][j] = aArr[i][j] + bArr[i][j] + cArr[i][j];
			cout << sumArr[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}