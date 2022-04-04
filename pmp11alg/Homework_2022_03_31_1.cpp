#include <iostream>

int main() {
  int n;
  std::cout << "(a-b)^2 = a^2 - 2ab + b^2"<<std::endl;
  std::cout << "enter matrix size, n:"; std::cin >> n;
  int matrA[n][n], matrB[n][n];
  int res_matr_a[n][n], res_matr_b[n][n], mult_res[n][n], fin_res[n][n];
  
  std::cout<<"Enter Elements of First Matrix: "<<std::endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++) {
      std::cout<<"matrix element["<<i<<"]["<<j<<"]: ";    
      std::cin>>matrA[i][j];
    }
  }

  std::cout<<"Enter Elements of Secont Matrix: "<<std::endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++) {
      std::cout<<"matrix element["<<i<<"]["<<j<<"]: ";   
      std::cin>>matrB[i][j];
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
      std::cout << fin_res[i][j] << " ";
    std::cout << std::endl;
  }
}
