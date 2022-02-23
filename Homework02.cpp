#include <iostream>
using namespace std;
int main() {
    int y;
    cout << "Enter the year you want to check " << "\n";
    cin >> y;

    if ((y % 4 == 0) || (y % 400 == 0) && (y % 100 != 0)) {
        cout << "This year is a leap year" << endl;
    }
    else {
        cout << "This year isn't a leap year" << endl;
    }

    return 0;
}