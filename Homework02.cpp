#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "Enter year: ";
    cin >> n;
    if((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0)){
        cout << "This is a leap year\n";
    } else  cout << "This is not a leap year\n";
}
