#include <iostream>
using namespace std;

void create_matrix(int ** matrix,int n);
bool symmetrical_matrix(int **matrix,int n);

int main(){
    int n;
    cout << "n=";
    cin >> n;
    int** A = new int* [n];
    create_matrix(A,n);
    if(symmetrical_matrix(A,n)) cout << "Yes, matrix is symmetrical about the diagonal \n";
    else cout << "No matrix is not symmetrical about the diagonal\n";
    system("PAUSE");
    return 0;
}


bool symmetrical_matrix(int **matrix,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]!=matrix[n-1-i][n-1-j] && j!=i) return false;
        }
    }
    return true;
}

void create_matrix(int ** matrix,int n){
    unsigned int k;
    for(int i =0;i<n;i++) matrix[i]=new int [n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> k;
            matrix[i][j] = k;
        }
    cout << "\n\n";
}