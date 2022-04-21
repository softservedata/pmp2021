#include <iostream>
using namespace std;
void creating(int**& matr, int n, const char* message);
void simple_creating(int**& matr, int len, int n);
int compare_arrays(int*& arr1, int*& arr2, int n);
void print(int**& matr, int n, const char* message);
void deleting(int**& matr, int n);
void merge(int**& matr, int p, int q, int r, int n);
void sortByMerge(int**& matr, int p, int r, int n);
void sortByMergeGlobal(int**& matr, int n);
int main(){
    cout<<"sorting matrix A for the first element of each row"<<endl;
    int n;
    do{
        cout<<"n>0, n int, n=";
        cin>>n;
    }while(n<=0);
    int** A;
    creating(A, n, "A");
    sortByMergeGlobal(A, n);
    print(A, n, "A");
    deleting(A, n);
    return 0;
}
void creating(int**& matr, int n, const char* message){
    matr=new int*[n];
    cout<<"matrix "<<message<<endl;
    for(int i=0; i<n; i++){
        matr[i]=new int[n];
        for(int j=0; j<n; j++){
            cout<<message<<"["<<i+1<<"]["<<j+1<<"]=";
            cin>>matr[i][j];
        }
    }
    cout<<endl;
}
void simple_creating(int**& matr, int len, int n){
    matr=new int*[len];
    for(int i=0; i<len; i++){
        matr[i]=new int[n];
        for(int j=0; j<n; j++){
            matr[i][j]=0;
        }
    }
}
int compare_arrays(int*& arr1, int*& arr2, int n){
    int p=0;
    while((arr1[p]==arr2[p])&&(p<=n-1)){
        p+=1;
    }
    if(p==n){
        return 0;
    }
    else if(arr1[p]>arr2[p]){
        return 1;
    }
    else{
        return -1;
    }
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
void deleting(int**& matr, int n){
    for(int i=0; i<n; i++){
        delete[] matr[i];
    }
    delete[] matr;
}
void merge(int**& matr, int p, int q, int r, int n){
    int len = r - p + 1;
    int** arrtemp;
    simple_creating(arrtemp, len, n);
    int ip = p;
    int iq = q + 1;
    for (int i = 0; i < len; i++){
        if ((ip <= q) && (iq <= r)){
            if (compare_arrays(matr[ip], matr[iq], n)<0){
                swap(arrtemp[i],matr[ip]);
                ip++;
            }
            else{
                swap(arrtemp[i],matr[iq]);
                iq++;
            }
        }
        else if (ip <= q){
            swap(arrtemp[i],matr[ip]);
            ip++;
        }
        else if (iq <= r){
            swap(arrtemp[i],matr[iq]);
            iq++;
        }
    }
    for (int i = 0; i < len; i++){
        swap(matr[p + i], arrtemp[i]);
    }
    deleting(arrtemp, len);
}
void sortByMerge(int**& matr, int p, int r, int n){
    if (p < r)
    {
        int q = (p + r) / 2;
        sortByMerge(matr, p, q, n);
        sortByMerge(matr, q + 1, r, n);
        merge(matr, p, q, r, n);
    }
}
void sortByMergeGlobal(int**& matr, int n){
    cout << "\t\tsorting ..." << endl;
    sortByMerge(matr, 0, n - 1, n);
    cout << "\t\tsorted done" << endl;
}
