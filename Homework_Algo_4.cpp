#include <iostream>
using namespace std;
void reading(int** arr, int n, int m);
void print(int** arr, int n ,int m);
void sumus(int** arr1, int** arr2 ,int** arr3, int** arr4, int n, int m);
void del(int** arr, int n);
int main(){
    int n,m;
    cout<<"n="; cin>>n;
    cout<<"m="; cin>>m;
    int** A= new int*[n];
    for (int i = 0; i < n; i++)
        A[i] = new int[m];
    int** B= new int*[n];
    for (int i = 0; i < n; i++)
        B[i] = new int[m];
    int** C= new int*[n];
    for (int i = 0; i < n; i++)
        C[i] = new int[m];
    int** D= new int*[n];
    for (int i = 0; i < n; i++)
        D[i] = new int[m];
    cout<<"mass A:"<<endl;
    reading(A, n, m);
    cout<<"mass B:"<<endl;
    reading(B, n, m);
    cout<<"mass C:"<<endl;
    reading(C, n, m);
    sumus(D, A, B, C, n, m);
    cout<<"mass D:"<<endl;
    print(D,n,m);
    del(A, n);
    del(B , n);
    del(C, n);
    del(D, n);
    return 0;
}
void reading(int** arr, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << "elem[" << i << "]" << "[" << j << "] = ";
            cin >> *(*(arr+i)+j);
        }
    }
}
void print(int** arr, int n ,int m){
    for(int i=0; i<n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<*(*(arr+i)+j)<<"\t";
        }
        cout<<"\n";
    }
}
void sumus(int** arr1, int** arr2 ,int** arr3, int** arr4, int n, int m){
    for(int i=0; i<n; i++) {
        for (int j = 0; j < m; j++){
            *(*(arr1+i)+j)=*(*(arr2+i)+j)+*(*(arr3+i)+j)+*(*(arr4+i)+j);
        }
    }
}
void del(int** arr, int n){
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
}
