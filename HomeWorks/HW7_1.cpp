#include <iostream>
using namespace std;

void create_matr(int **matrix,int n);
void fill_matr(int **matrix,int n);
void t_matr(int **matrix1,int** matrix2,int n);
void print_matr(int** matr, int n);

int main(){
     int n;
    cout << "n=";
    cin >> n;
    int** A = new int* [n];
    int** AT = new int* [n];
    create_matr(A,n); fill_matr(A,n);
    create_matr(AT,n);
    t_matr(A,AT,n);
    cout << "transported matrix:\n";
    print_matr(AT,n);
    system("PAUSE");
    return 0;
}

void t_matr(int **matrix1,int** matrix2,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix2[i][j]=matrix1[j][i];

        }
    }

}

void print_matr(int** matr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void create_matr(int **matrix,int n){
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];
}

void fill_matr(int **matrix,int n){
    unsigned int k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> k;
            matrix[i][j] = k;
        }
    cout << "\n\n";
}
