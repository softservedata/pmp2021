#include<iostream>
using namespace std;

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
void print_matrix(double** matrix, int& n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
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


double** difference_matr(double** matr1, double** matr2, int n) {
    double** matr = zeros(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matr[i][j] = matr1[i][j] - matr2[i][j] ;
        }
    }
    return matr;
}
double** multiply_matr(double** matrix1, double** matrix2, int& n) {
    double** matrix = new double* [n], sum = 0;
    for (int i = 0; i < n; ++i) {
        *(matrix + i) = new double[n];
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < n; ++l) {
                sum += matrix1[i][l] * matrix2[l][j];
            }
            matrix[i][j] = sum;
            sum = 0;
        }
    }
    return matrix;
}

void delet(double** matr, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matr[i];
    }
    delete[] matr;
}

int main06()
{
	int n;
	cout << "Enter n= ";
	cin >> n;
    cout << "Matr A"<<endl;

    double** A = read_matr(n);

    cout << "Matr B"<<endl;
    double** B = read_matr(n); 
    double** C = difference_matr(A, B, n);
    double** P = multiply_matr(C, C, n);
    print_matrix(P, n);
    delet(A, n);
    delet(B, n);
    delet(C, n);
    delet(P, n);
    
	
}
