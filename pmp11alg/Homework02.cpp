#include <iostream>
using namespace std;

int main() {
    int year;
    cout << "Enter year:";
    cin >> year;

    if (year%4 == 0) {
        if (year%100 == 0 && year%400 != 0) {
            cout << "This year is not leap" << endl;
        }
        else {
            cout << "Its leap year!" << endl;
        }

    }
    else {
        cout << "This year is not leap" << endl;
    }
}
