#include <iostream>
using namespace std;
int main(){
    //A leap year
    int n;
    cout<<"Введіть Ваш рік...=";
    cin>>n;
    if ((n%400==0)||((n%4==0)&&(n%100!=0))){
        cout<<"Рік, який Ви ввели, високосний.";
    }
    else{
        cout<<"Рік, який Ви ввели, не високосний.";
    }
    return 0;
}