#include <iostream>
using namespace std;

// Формула виглядає так: 1*(2+3)*(4+5+6)*…*(…+n)

int main()
{
    int n;
    cout << "Please,enter n value : ";
    cin >> n;

    long long int resultValue = 1;
    int sumCounter = 0, end = 1, increment = 1;

    for (int i = 1; i <= n; i++) 
    {
        if (i - end == 0) 
        {
            sumCounter += i;

            resultValue *= sumCounter;
            sumCounter = 0;
            increment++; end += increment;
        }
        else if (i == n) 
        {
            sumCounter += i;
            resultValue *= sumCounter;
        }
        else sumCounter += i;
    }

    cout << "You entered: " << n << ".The result is: " << resultValue;
}
