#include<iostream>
using namespace std;
//
double** read_matr(int n)
{
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
//
//
void delet(double** matr, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matr[i];
    }
    delete[] matr;
}
//
//

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
//
//

double** trans(double** matr1, int n)
{
	double** matr = zeros(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			matr[i][j] = matr1[j][i];
		}
	}
	return matr;
}

//
//

bool symetric_Matr(double** matr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matr[i][j] != matr[j][i])
			{
				return false;
			}
		}
	}
	return true;
}


//
//
void print_matr(double** matr, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int n;
	cout << "Enter n= ";
	cin >> n;
	cout << "Matr A" << endl;
    double** A = read_matr(n);
	cout << "Matr A:"<<endl;
	print_matr(A, n);
	//task1
	cout << "Transponovana: "<<endl;
	double** trans_a = trans(A, n);
	
	print_matr(trans_a,n);
	
	delet(trans_a, n);

	//task2
	cout<<"Symetric:"<<symetric_Matr(A, n);
	delet(A, n);

}
