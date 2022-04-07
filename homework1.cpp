#include <iostream>
#include <cmath>

using namespace std;

int main() {
  // a
    int a; 
    int b;
    cout << "a = " ;
    cin >> a;
    cout << "b = " ;
    cin >> b; 
    int c = a;
   
    c = b;
    cout << "додаткова змінна - " << c << endl;
    
  // b
   
    int sum = a + b;
    int min = a - b;
    int min2 = b- a;
    cout << "додавання та віднімання - " << sum << " " << min << " " <<   min2 << endl;
    
  // c
    
    int k = a * b;
    int l = a / b;
    int p = b / a;
    cout << "множення та ділення - " << k << " " << l << " "  << p << endl;
    
// d
  
    a = (a & ~b) | (~a & b);
    b = (a & ~b) | (~a & b);
    cout << "кон’юнкція та диз’юнкція - " << a << " " << b << endl;
  
  
  // e
  int suv;
  int suv2;
  suv = a >> 3; 
  suv2 = b >> 1;
 cout << "зсув - " << a << " " << b << endl;   
    
    
  // f
  
  int j;
  
  j = (a+b)%2 == (a+b)&1 == (a^b)&1;
    cout << "додавання по модулю 2 - " << j << endl;
    return 0;
  }
