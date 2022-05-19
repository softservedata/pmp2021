#include <iostream>
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


void delet(double** matr, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matr[i];
    }
    delete[] matr;
}

double** changed_matr(double** matr, int row)
{
    for (int i = 0; i < row; i++)
        for (int start_i = 0; start_i < row - 1; ++start_i)
        {
            int smallest_i = start_i;
            for (int current_i = start_i + 1; current_i < row; ++current_i)
            {
                if (matr[i][current_i] < matr[i][smallest_i])
                    smallest_i = current_i;
            }
            std::swap(matr[i][start_i], matr[i][smallest_i]);
        }
    return matr;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    double** matr = read_matr(n);
    print_matrix(matr, n);
    double** change_matr = changed_matr(matr, n);
    print_matrix(change_matr, n);
    delet(matr, n);
    delet(change_matr, n);
    system("pause");
    return 0;
}
