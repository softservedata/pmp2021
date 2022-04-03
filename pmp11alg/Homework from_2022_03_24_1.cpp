#include <iostream>
#include <cmath>
using namespace std;
long double recurent_sum(int n);
long double recursion_sum(int n, int count);
int main() {
  int n, count=0; 
  long double j=n;
  cout<<"enter n:"; cin >> n;
  cout<< recurent_sum(n) <<endl;
  cout<< recursion_sum(n, count) <<endl;
}
long double recurent_sum(int n){
  long double sum=0, h;
  for(int i=1; i<=n; i++){
    h=sin(i);
    for(int j=1; j<=n-i; j++) h=sin(h);
    sum+=h;
  }
  return sum;
}
long double recursion_sum(int n, int count) {
  if (n==1) {
    long double m;
    m=sin(1);
    for(int j=1; j<=count; j++) m=sin(m);
    return m ;
  }
  else {
    long double h;
    h=sin(n);
    for(int j=1; j<=count; j++) h=sin(h);
    return h + recursion_sum(n-1, count+1);
  }
}
