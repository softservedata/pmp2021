//matrix is diagonal or not?
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

int sumdisgonal(int** matrix, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            if (i == j)
                sum += abs(matrix[i][j]);
        }
    }
    return sum;
}
int sum_without_diagonal(int** matrix, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            if (i != j)
                sum += abs(matrix[i][j]);
        }
    }
    return sum;
}


int main()
{
    int n;
    cout << " please enter matrix size: ";
    cin >> n;
    cout << "First matrix: " << endl;
    int** matrix1 = read_matrix(n);
    print_matrix(matrix1, n);
    int sum_diagonal = sumdisgonal(matrix1, n);
    //cout << " sum diagonal: " << sum_diagonal << endl;
    int sum_without_diagonals = sum_without_diagonal(matrix1, n);
    //cout << " sum without diagonal: " << sum_without_diagonals << endl;
   
    if (sum_diagonal > sum_without_diagonals) 
        cout << " It's diagonal matrix";
    else
        cout << " It isn't diagonal matrix";



    delete_matrix(matrix1, n);

    system("pause");
    return 0;
}