#include <iostream>
using namespace std;

double** read_matrix(int row, int column)
{
    double** matr = new double* [row];
    for (int i = 0; i < row; i++)
        matr[i] = new double[column];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << "Matr" << "[" << i << "]" << "[" << j << "] = ";
            cin >> matr[i][j];
        }
    }
    return matr;
}

void print_matrix(double** matr, int row, int column, const char* massage)
{
    cout << massage << "matrix" << ":" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            cout << matr[i][j] << '\t';
        cout << endl;
    }
    cout << endl;
}

void delete_matrix(double**& matr, int row)
{
    for (int i = 0; i < row; i++)
        delete[] matr[i];
    delete[] matr;
}
double** changed_matr (double** matr, int row)
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

int main09()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    double** matr = read_matrix(n, n);
    print_matrix(matr, n, n, "Input ");
    double** change_matr = changed_matr(matr, n);
    print_matrix(change_matr, n, n, "Changed ");
    delete_matrix(matr, n);
    delete_matrix(change_matr, n);
	system("pause");
	return 0;
}