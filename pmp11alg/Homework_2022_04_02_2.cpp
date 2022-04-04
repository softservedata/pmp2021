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

  for (int i=0; i<n; i++) {
    for(int j=0; j<n; j++){
      std::cout<<matr[i][j]<<" ";
    }
    std::cout<<std::endl;
  }
  
  for (int i=0; i<n; i++){
    for (int j=0;j<n;j++){
      if (matr[i][j]!=matr[j][i]){
        std::cout<<"Matrix is not symmetric"; return 0; }
      else continue;
    }
  }
  std::cout<<"Congratulations! Your matrix is symmetrical:";
}
