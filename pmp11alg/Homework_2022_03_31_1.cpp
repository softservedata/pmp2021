#include <iostream>
using namespace std;

int main() {
  int n, m;
  cout << "(a-b)^2 = a^2 - 2ab + b^2"<<endl;
  cout << "enter matrix size, n:"; cin >> n;
  int matrA[n][n], matrB[n][n];
  int res_matr_a[n][n], res_matr_b[n][n], mult_res[n][n], fin_res[n][n];
  
  cout<<"Enter Elements of First Matrix: "<<endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++) {
      cout<<"matrix element["<<i<<"]["<<j<<"]: ";    
      cin>>matrA[i][j];
    }
  }

  cout<<"Enter Elements of Secont Matrix: "<<endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++) {
      cout<<"matrix element["<<i<<"]["<<j<<"]: ";   
      cin>>matrB[i][j];
    }
  }


  // a^2
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      res_matr_a[i][j] = 0;
      for (int k = 0; k < n; k++)
        res_matr_a[i][j] += matrA[i][k] * matrA[k][j];
    }
  }

  //b^2
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      res_matr_b[i][j] = 0;
      for (int k = 0; k < n; k++)
        res_matr_b[i][j] += matrB[i][k] * matrB[k][j];
    }
  }

  //2*a*b
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      mult_res[i][j] = 0;
      for (int k = 0; k < n; k++)
        mult_res[i][j] += matrA[i][k] * matrB[k][j];
    }
  }

  //a^2 - 2ab + b^2
  for(int i=0; i<n; i++){
      for(int j=0; j<n; j++)
        fin_res[i][j] = res_matr_a[i][j]-mult_res[i][j]+res_matr_b[i][j];
  }

    
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++)
      cout << fin_res[i][j] << " ";
    cout << endl;
  }
}
