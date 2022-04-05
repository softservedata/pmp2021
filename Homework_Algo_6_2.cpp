#include <iostream>
#include <cmath>
using namespace std;
void creating(int**& matr, int n, const char* message);
int checkingrow(int*& arr, int n, int k);
int checkingmatr(int**& matr, int n);
int main(){
    int n;
    do{
        cout<<"n>0 n int n=";
        cin>>n;
    }while(n<=0);
    int** A;
    creating(A, n, "A");
    cout<<endl;
    checkingmatr(A, n);
    cout<<endl<<endl;
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
int checkingrow(int*& arr, int n, int k){
    int s=0;
    for(int i=0; i<n; i++){
        if(abs(arr[i])>abs(arr[k])){
            s+=1;
        }
    }
    return s;
}
int checkingmatr(int**& matr, int n){
    for(int i=0; i<n; i++){
        if(checkingrow(matr[i], n, i)>0){
            cout<<"No diagonal advantage in this matrix";
            return 0;
        }
    }
    cout<<"Diagonal advantage in this matrix";
    return 0;
}
