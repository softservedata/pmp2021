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

void diagonal_perev(int** matr, int n)
{
    int countelsatisfy = 0;
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        double sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                sum += matr[i][j];
            }
        }
        if (matr[i][l] >= sum)
        {
            countelsatisfy++;
        }
        l++;
    }
    cout << "Count elem that satisfy: " << countelsatisfy;
    if (countelsatisfy == n)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

}


int main()
{
    int n;
    cout << " please enter matrix size: ";
    cin >> n;
    cout << "First matrix: " << endl;
    int** matrix1 = read_matrix(n);
    print_matrix(matrix1, n);
    


    diagonal_perev(matrix1, n);


    delete_matrix(matrix1, n);

    system("pause");
    return 0;
}