#include <iostream>
#include <cmath>

// 1) Написати код обчислення виразу 
//       S = sin(n) + sin(sin(n - 1)) + sin(sin(sin(n - 2))) + … + sin(sin(… sin(1)))
//  A) Використовуючи рекурентні вкладення;
//   B) За допомогою рекурсії.



using namespace std;

// 1.a Використовуючи рекурентні вкладення

double recurAdding(int& n) 
{
    double counter = 0, encrement;
    for (int i = n; i >= 1; --i) 
    {
        encrement = sin(i);
        for (int j = i; j < n; ++j) 
        {
            encrement = sin(encrement);
        }
        counter += encrement;
    }
    return counter;
}

// 1.b За допомогою рекурсії

double sumByRecursion(int n, int nInBegin) 
{
    double tempCounter = sin(n);
    for (int i = n; i < nInBegin; ++i) 
    {
        tempCounter = sin(tempCounter);
    }
    if (n == 1) 
    {
        return tempCounter;
    }
    return tempCounter + sumByRecursion(n - 1, nInBegin);
}


// 2) Написати код обчислення суми S=n+(n-2)+(n-4)+...+0 за допомогою рекурсії. 

int recursionCalculating(int n) 
{
    if (n <= 0) 
    {
        return 0;
    }
    return n + recursionCalculating(n - 2);
}

int main()
{
    int n;
    double resultOfCalculating;
    cin >> n;
    resultOfCalculating = recurAdding(n);
    cout << resultOfCalculating << "\n";
    return 0;
}