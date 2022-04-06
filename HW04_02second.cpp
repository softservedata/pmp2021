//Transpose matrix
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



int main()
{
    int n;
    cout << " please enter matrix size: ";
    cin >> n;
    int** matrix1 = read_matrix(n);

    print_matrix(matrix1, n);

    int** transpose = new int* [n];
    for (int i = 0; i < n; i++)
        transpose[i] = new int[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transpose[i][j] = matrix1[j][i];
        }
    }

    print_matrix(transpose, n);

    delete_matrix(matrix1, n);
    delete_matrix(transpose, n);
    system("pause");
    return 0;
}