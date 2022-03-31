#include <iostream>
using namespace std;

//s=1*(2+3)*(4+5+6)*…*(…+n)

int main() {
  int n;
  cout << "enter n:";
  cin >>n;
  
  long int res=1;
  int sum=0, g=1, h=1;
  
  for (int i=1; i <= n; i++) {
      if(i - h == 0){
          sum += i;
          res *= sum;
          sum = 0;
          g++; h+=g;
      }
      else if (i == n) {
          sum += i;
          res *= sum;
      }
      else sum+=i;
  }
  cout << "result of task A: "<< res;
}
