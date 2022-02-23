#include <iostream>
using namespace std;

int main()
{
    int a , b , temp;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "Before swapping " << endl;
    cout << "a = " << a << ", b = " << b << endl;

    temp = a;
    a = b;
    b = temp;

    cout << "\nAfter swapping using temporary variable" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    
    a = a + b;
    b = a - b;
    a = a - b;

    cout << "\nAfter swapping using addition and subtraction operations" << endl;
    cout << "a = " << a << ", b = " << b << endl;

    a = a * b;    
    b = a / b;    
    a = a / b;    

    cout << "\nAfter swapping using multiplication and division " << endl;
    cout << "a = " << a << ", b = " << b << endl;

    a = (~a & b) | (a & ~b);
    b = (~a & b) | (a & ~b);
    a = (~a & b) | (a & ~b);

    cout << "\nAfter swapping using conjunction and disjunction operations " << endl;
    cout << "a = " << a << ", b = " << b << endl;

    a = a << 1;
    b = b << 2;
    a = a << 2;
    b = b << 1;

    cout << "\nAfter swapping using shift operations " << endl;
    cout << "a = " << a << ", b = " << b << endl;

    a = a ^ b;
    b = b ^ a;
    a = a ^ b;

    cout << "\nAfter swapping using the addition operation according to module 2 " << endl;
    cout << "a = " << a << ", b = " << b << endl;
    
    return 0;
}
