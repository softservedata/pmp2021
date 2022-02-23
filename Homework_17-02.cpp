//
// Created by gnatk on 23.02.2022.
//
#include <iostream>
using namespace std;

int main() {
    int y;
    cout << "Введіть рік: ";
    cin >> y;
    if (( y % 100 != 0 && y % 4 == 0 ) || ( y / 400  == 0 )) {
        cout << "Рік є високосним" << endl;
    }
    else {
        cout << "Рік не є високосним" << endl;
    }

    return 0;
}

