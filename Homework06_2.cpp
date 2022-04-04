#include<iostream>
using namespace std;

bool diagonal(double** matrix, int& n)
{
    double d, sum = 0;
    for (int i = 0; i < n; ++i) {
        d = *(*(matrix + i) + i);
        for (int j = 0; j < n; ++j) {
            if (j == i) ++j;
            sum += fabs(*(*(matrix + i) + j));
        }
        if (fabs(d) < sum) return false;
        sum = 0;
    }
    return true;
}

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

void delet(double** matr, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matr[i];
    }
    delete[] matr;
}

int main()
{
    int n;
    cout << "Enter n= ";
    cin >> n;
    cout << "Matr A" << endl;

    double** A = read_matr(n);
    cout<<"res="<<diagonal(A, n);
    delet(A, n);
}
