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
void printmatrix(matrix* matr, const char* message);
void transponing(matrix*& matr);

int main(){
    cout<<"transponning matrix"<<endl;
    matrix* matr;
    creating(matr, "Matrix");
    transponing(matr);
    printmatrix(matr, "Matrix");
    deletematr(matr);
    return 0;
}
void deletematr(matrix*& matr){
    delete matr;
}
void printmatrix(matrix* matr, const char* message){
    cout << "\nTransponned " << message << endl;
    for (int i = 0; i < matr->rows; i++)
    {
        for (int j = 0; j < matr->columns; j++)
        {
            cout << matr->arr[i][j] << "\t ";
        }
        cout << endl;
    }
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

void transponing(matrix*& matr){
    cout<<endl<<"transponning..."<<endl<<endl;
    int p=1, s;
    for(int i=0; i<matr->rows; i++){
        for(int j=p; j < matr->columns;j++ ){
            s=matr->arr[i][j];
            matr->arr[i][j]=matr->arr[j][i];
            matr->arr[j][i]=s;
        }
        p+=1;
    }
}