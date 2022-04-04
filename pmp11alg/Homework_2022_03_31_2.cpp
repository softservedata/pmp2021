#include <iostream>

int main() {
  int n;
  std::cout << "enter matrix size, n:"; std::cin >> n;
  float matr[n][n], string[n], max;
  
  std::cout<<"Enter Elements of Matrix: "<<std::endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++) {
      std::cout<<"matrix element["<<i<<"]["<<j<<"]: ";    
      std::cin>>matr[i][j];
    }
  }

  for (int i=0; i<n; i++){
    for (int k=0; k<n; k++) string[k]=0;
    
    for (int h=0; h<n; h++){
      if (h!=i  &&  std::abs(matr[i][i]) < std::abs(matr[i][h])) {
        std::cout<<"Matrix does not possess diagonal advantage";
        break;
      }  
      else if ((i+1==n) && (h+1==n)){
        std::cout<<"Matrix possess diagonal advantage. Congrat!"; 
      }
    }
  }
}
