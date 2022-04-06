//matrix (A-B)^2
#include<iostream>
using namespace std;
int** read_matrix(int n)
{
    int** Arr = new int* [n];
    for (int i = 0; i < n; i++)
        Arr[i] = new int[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Matr" << "[" << i << "]" << "[" << j << "] = ";
            cin >> Arr[i][j];
        }
    }
    return Arr;
}
void print_matrix(int** Arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << Arr[i][j] << '\t';
        cout << endl;
    }
    cout << endl;
}

void delete_matrix(int** Arr, int n)
{
    for (int i = 0; i < n; i++)
        delete[] Arr[i];
    delete[] Arr;
}

int** subtraction_matrix_and_raising(int** matrix1, int** matrix2, int n) {
    int** substractmatr = new int* [n];
    for (int i = 0; i < n; i++)
        substractmatr[i] = new int[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int b = matrix1[i][j] - matrix2[i][j];
            substractmatr[i][j] = b * b;
        }
    }
    return substractmatr;
}


int main()
{
    int n;
    cout << " please enter matrix size: ";
    cin >> n;
    cout << "First matrix: ";
    int** matrix1 = read_matrix(n);
    //print_matrix(matrix1, n);
    cout << "Second matrix: ";
    int** matrix2 = read_matrix(n);
    //print_matrix(matrix2, n);
    int** smatr = subtraction_matrix_and_raising(matrix1, matrix2, n);
    print_matrix(smatr, n);



    delete_matrix(matrix1, n);
    delete_matrix(matrix2, n);
    delete_matrix(smatr, n);
    system("pause");
    return 0;
}