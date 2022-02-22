#include <iostream>

using namespace std;

int main() {
    int year;
    cin >> year;
    cout << year;
    if ((!(year % 4) && year % 100) || !(year % 400)) cout << " високосний";
    else cout << " не високосний";
    cout << endl;
    return 0;
}