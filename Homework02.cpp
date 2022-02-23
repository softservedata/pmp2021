#include <iostream>
using namespace std;

int main()
{
    int year;
    cout << "Enter year:";
    cin >> year;

    if (year%4 == 0 && year%100 != 0 )
    {
        cout << "This year is high" << endl;
    }
    else if (year%400 == 0)
    {
        cout << "This year is high" << endl;
    }
    else
    {
        cout << "This year is not high" << endl;
    }
}