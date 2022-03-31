#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "enter n:";
  cin >> n;
  
  long int res=0, prod=1;

  for(int i=1; i<=n; i++){
    for(int k=i; k<=i*i; k++) prod*=k;
    res+=prod;
    prod=1;
  }
  
  cout << "result of task C: "<< res;
}
