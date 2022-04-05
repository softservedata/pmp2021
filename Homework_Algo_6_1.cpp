#include <iostream>
using namespace std;
void creating(int**& matr, int n, const char* message);
void print(int**& matr, int n, const char* message);
void simplecreating(int**& matr, int n);
void subtraction(int**& matr1, int**&matr2, int**& matr3, int n);
int elemofmultiply(int**& matr1, int**&matr2, int n, int k, int p);
void multiplying(int**& matr1, int**& matr2, int**& matr3, int n);
void deleting(int**& matr, int n);
int main(){
    cout<<"counting (A-B)**2"<<endl;
    int n;
    do{
        cout<<"n>0 n int n=";
        cin>>n;
    }while(n<=0);
    int** A;
    int** B;
    int** C;
    int** D;
    creating(A, n, "A");
    creating(B, n , "B");
    simplecreating(C, n);
    simplecreating(D, n);
    subtraction(A, B, C, n);
    multiplying(C, C, D, n);
    print(D, n, "(A-B)**2");
    deleting(A, n);
    deleting(B, n);
    deleting(C, n);
    deleting(D, n);
    return 0;
}
void creating(int**& matr, int n, const char* message){
    matr=new int*[n];
    cout<<"matrix "<<message<<endl;
    for(int i=0; i<n; i++){
        matr[i]=new int[n];
        for(int j=0; j<n; j++){
            cout<<message<<"["<<i<<"]["<<j<<"]=";
            cin>>matr[i][j];
        }
    }
    cout<<endl;
}
void print(int**& matr, int n, const char* message){
    cout<<"matrix "<<message<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matr[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}
void subtraction(int**& matr1, int**&matr2, int**& matr3, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matr3[i][j]=matr1[i][j]-matr2[i][j];
        }
    }
}
void simplecreating(int**& matr, int n){
    matr=new int*[n];
    for(int j=0; j<n; j++){
        matr[j]=new int[n];
        }
}
int elemofmultiply(int**& matr1, int**&matr2, int n, int k, int p){
    int s=0;
    for(int j=0; j<n; j++){
        s+=matr1[k][j]*matr2[j][p];
    }
    return s;
}
void multiplying(int**& matr1, int**& matr2, int**& matr3, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matr3[i][j]=elemofmultiply(matr1, matr2, n, i, j);
        }
    }
}
void deleting(int**& matr, int n){
    for(int i=0; i<n; i++){
        delete[] matr[i];
    }
    delete[] matr;
}