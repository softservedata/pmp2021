
#include <iostream>
using namespace std;

// Прочитати з клавіатури ціле число, яке представляє собою рік. За допомогою операторів if визначити, чи прочитаний рік є високосний. 
// P.S.Рік є високосний, якщо ділиться на 4, але не є високосним, якщо ділиться на  100, але все таки є високосним, якщо ділиться на 400.


int main()
{
    int year;
    cout << "Enter a year: ";
    cin >> year;

    if (year % 400 == 0) 
    {
        cout << year << " is a leap year.";
    }

    else if (year % 100 == 0) 
    {
        cout << year << " is not a leap year.";
    }

    else if (year % 4 == 0) 
    {
        cout << year << " is a leap year.";
    }
    else 
    {
        cout << year << " is not a leap year.";
    }
}
