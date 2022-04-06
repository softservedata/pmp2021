//Symetrix matrix or not?
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

bool isSymmetric(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != matrix[j][i]) return false;
        }
    }
    return true;
}


int main()
{
    int n;
    cout << " please enter matrix size: ";
    cin >> n;
    int** matrix1 = read_matrix(n);

    print_matrix(matrix1, n);

    if (isSymmetric(matrix1, n))
        cout << "Symmetric";
    else
        cout << "Not Symmetric";



    delete_matrix(matrix1, n);

    system("pause");
    return 0;
}