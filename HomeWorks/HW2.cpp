#include <iostream>
using namespace std;

int main(){
    int year;
    cout << "year : ";
    cin >> year;
    if(year%4==0){
        if(year%100==0 && year%400==0) cout << "A leap year";
        else if(year%100!=0) cout << "A leap year";

    }
    else cout << "Is not a leap year";
    system("PAUSE");
    return 0;
}