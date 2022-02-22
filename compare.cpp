#include <iostream>

using namespace std;

int main() {
    int a,b,c;
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    cout<<"c=";
    cin>>c;
    if (a<b){
        if (b<c){
            cout<<a<<"<"<<b<<"<"<<c;
        }
        else if (a<c){
            cout<<a<<"<"<<c<<"<"<<b;
        }
        else{
            cout<<c<<"<"<<a<<"<"<<b;
        }
    }
    else{
        if (b>c){
            cout<<c<<"<"<<b<<"<"<<a;
        }
        else if(c>a){
            cout<<b<<"<"<<a<<"<"<<c;
        }
        else{
            cout<<b<<"<"<<c<<"<"<<a;
        }
    }
    return 0;
}

