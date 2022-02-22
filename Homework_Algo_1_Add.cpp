#include <iostream>

using namespace std;

int main() {
    double a,b,c,t;
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    cout<<"c=";
    cin>>c;
    cout<<"sorted"<<endl;
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

    cout<<endl<<"Another way"<<endl;
    if (a>b){
        t=a;
        a=b;
        b=t;

    }
    if (b>c){
        t=b;
        b=c;
        c=t;

    }
    if (a>b){
        t=a;
        a=b;
        b=t;

    }
    cout<<a<<"<"<<b<<"<"<<c<<endl;

    return 0;
}
