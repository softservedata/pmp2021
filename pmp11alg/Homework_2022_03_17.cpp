#include <iostream>
using namespace std;


int main() {
  int n, m;
  cout << "enter matrix size, n:";
  cin >> n;
    cout << "enter matrix size, m:";
  cin >> m;

int matr1[n][m], matr2[n][m], matr3[n][m], res_matr[n][m];
  cout<<"Enter Elements of First Matrix: "<<endl;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++) {
        cout<<"matrix element["<<i<<"]["<<j<<"]: ";      
        cin>>matr1[i][j];
      }
    }

  cout<<"Enter Elements of Secont Matrix: "<<endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++) {
      cout<<"matrix element["<<i<<"]["<<j<<"]: ";   
      cin>>matr2[i][j];
    }
  }

  cout<<"Enter Elements of Third Matrix: "<<endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cout<<"matrix element["<<i<<"]["<<j<<"]: ";
      cin>>matr3[i][j];
    }
  }

  //adding
  for(int i=0; i<n; i++){
      for(int j=0; j<m; j++)
        res_matr[i][j] = matr1[i][j]+matr2[i][j]+matr3[i][j];
    }

  cout<<"Result of Given Matrix is:\n";
    for(int i=0; i<n; i++)
    {
      for(int j=0; j<m; j++)
          cout<<res_matr[i][j]<<" ";
      cout<<endl;
    }
  
}
