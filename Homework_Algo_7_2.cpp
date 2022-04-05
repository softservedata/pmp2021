#include <iostream>
using namespace std;
struct matrix
{
    int** arr;
    int rows;
    int columns;
    ~matrix()
    {
        cout << "\nDestructor" << endl;
        for (int i = 0; i < rows; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
};

void creating(matrix*& matr, const char* message);
void deletematr(matrix*& matr);
void checking(matrix*& matr);

int main(){
    cout<<"checking if matrix is symmetric along main diagonal"<<endl;
    matrix* matr;
    creating(matr, "Matrix");
    checking(matr);
    deletematr(matr);
    return 0;
}
void deletematr(matrix*& matr){
    delete matr;
}
void creating(matrix*& matr, const char* message){
    matr=new matrix();
    do{
        cout<<"n>0, int n, n=";
        cin>>matr->rows;
    }while(matr->rows<=0);
    matr->columns=matr->rows;
    matr->arr=new int*[matr->rows];
    cout<<message<<endl;
    for (int i = 0; i < matr->rows; i++){
        matr->arr[i]=new int[matr->columns];
        for (int j = 0; j < matr->columns; j++){
            cout<<message<<"["<<i<<"]["<<j<<"]=";
            cin>>matr->arr[i][j];
        }
    }
}

void checking(matrix*& matr){
    cout<<endl<<"checking if symmetric..."<<endl<<endl;
    int p=1, s=0;
    for(int i=0; i<matr->rows; i++){
        for(int j=p; j < matr->columns;j++ ){
            if(matr->arr[i][j]!=matr->arr[j][i]){
                s+=1;
            }
        }
        p+=1;
    }
    if(s>0){
        cout<<"matrix is not symmetric"<<endl;
    }
    else{
        cout<<"matrix is symmetric"<<endl;
    }
}
