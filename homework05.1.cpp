#include <iostream>
#include <math.h>
using namespace std;


double Recurrent(int n)
{
    int n0 = n;
    double sum = 0;

    for (int i = 1; i <= n0; i++)
    {
        double k1 = i;
        for (int j = n; j >= 1; j--)
        {
            k1 = sin(k1);
        }
        n--;
        sum += k1;
    }
    return sum;
}

double Recursion(int n, int count) 
{
    if (n == 1) 
    {
        double k2 = sin(1);
        for (int j = 1; j <= count; j++)
        {
            k2 = sin(k2);
        }
        return k2;
    }

    else 
    {
        double k3 = sin(n);
        for (int j = 1; j <= count; j++)
        {
            k3 = sin(k3);
        }
        return k3 + Recursion(n - 1, count + 1);
    }
}

int main()
{
    int n;
    cout << "Input n = ";
    cin >> n;

    cout << "Task 1.a" << endl;
    cout << "Result: " << Recurrent(n) << endl;

    int k, count = 0;
    cout << "Input n = ";
    cin >> k;

    cout << "Task 2.b" << endl;
    cout << "Result: " << Recursion(k, count) << endl;

    return 0;
    system("pause");
}