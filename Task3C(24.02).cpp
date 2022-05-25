#include <iostream>
using namespace std;

// Формула виглядає так: ∑(k=1)^n  k*(k+1)*…*k^2;; 

int main() 
{
    int n;
    cout << "Please,enter n value : ";
    cin >> n;

    long int resultValue = 0, increment = 1;

    for (int i = 1; i <= n; i++) 
    {
        for (int k = i; k <= i * i; k++) increment *= k;

        resultValue += increment;

        increment = 1;
    }

    cout << "You entered: " << n << ".The result is: " << resultValue;
}