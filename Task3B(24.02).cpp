#include <iostream>
#include <cmath>
using namespace std;

// Формула виглядає так: 1+(1*2)+(1*2*3)+⋯+(1*2*…*n); 


int main() 
{
    int n;
    cout << "Please,enter n value : ";
    cin >> n;

    long int resultValue = 0, increment = 1;

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= i; j++) 
        {
            increment *= j;
        }

        resultValue += increment;

        increment = 1;
    }
    cout << "You entered: " << n << ".The result is: " << resultValue;
}