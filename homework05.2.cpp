#include <iostream>
using namespace std;

double Recursion(int n) 
{
    if (n < 0)
    {
        return 0;
    }
    return Recursion(n - 2) + n;
}

int main() 
{
    int n;
    cout << "Input n = ";
    cin >> n;

    cout << "Result: " << Recursion(n) << endl;

    return 0;
    system("pause");
}