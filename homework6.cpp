#include <iostream>
#include <math.h>
using namespace std;

	
int main()
{
    int n;
    cout << " n = ";
    cin >> n;
    int matrix1[n][n];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> matrix1[i][j];
    
    cout << " n = ";
    cin >> n;
    int matrix2[n][n];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> matrix2[i][j];

   int matrix_dif[n][n] ;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         matrix_dif[i][j] = matrix1[i][j] - matrix2[i][j] ;
         cout << matrix_dif[i][j]<<" "  ;
      }
      cout << endl;
   }
  
  int matrix_multi[n][n] ;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        matrix_multi[i][j] += matrix_dif[i][j] * matrix_dif[i][j] ;
         cout << matrix_multi[i][j]<<" "  ;
      }
      cout << endl;
   }





  return 0;
  }


