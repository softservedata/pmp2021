#include <iostream>

int main() {
  int n;
  std::cout << "enter matrix size, n:"; std::cin >> n;
  int matr[n][n];
  
  std::cout<<"Enter Elements of Matrix: "<<std::endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++) {
      std::cout<<"matrix element["<<i<<"]["<<j<<"]: ";    
      std::cin>>matr[i][j];
    }
  }
  
  int T_matrix[n][n];
  for(int i = 0; i<n; i++){
      for(int j = 0; j<n; j++){
        T_matrix[i][j] = matr[j][i];
      }
  }
  
  std::cout<<"Your matrix:"<<std::endl;
  for (int i=0; i<n; i++) {
    for(int j=0; j<n; j++){
      std::cout<<matr[i][j]<<" ";
    }
    std::cout<<std::endl;
  }
  std::cout<<"Result:"<<std::endl;
  for (int i=0; i<n; i++) {
    for(int j=0; j<n; j++){
      std::cout<<T_matrix[i][j]<<" ";
    }
    std::cout<<std::endl;
  }
