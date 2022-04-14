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
  
  cout << " n = ";
    cin >> n;
    int matrix3[n][n];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> matrix3[i][j];
  
  int matrix_sum[n][n] ;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         matrix_sum[i][j] = matrix1[i][j] + matrix2[i][j] + matrix3[i][j];
         cout <<"сума матриць = "<< matrix_sum[i][j]  ;
      }
      cout << endl;
   }


  
    return 0;
}
