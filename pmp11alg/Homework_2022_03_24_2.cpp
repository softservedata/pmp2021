#include <iostream>
using namespace std;

int sum(int n) {
  if (n<=0) return 0;
  return n+sum(n-2);
}

int main() {
  int n, s; 
  cout<<"enter n:"; cin>>n;
  s=sum(n);
  cout<<s;
}
