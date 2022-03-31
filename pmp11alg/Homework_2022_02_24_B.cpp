#include <iostream>
#include <cmath>
using namespace std;


int main() {
  int n;
  cout << "enter n:";
  cin >>n;
  
  long int res=0, prod=1;

  for (int i=1; i <= n; i++) {
    for(int j=1; j<=i; j++){
      prod*=j;
    }
    res+=prod;
    prod = 1;   
  }
  cout << "result of task B: "<< res;
}
