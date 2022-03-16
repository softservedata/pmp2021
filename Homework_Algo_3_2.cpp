#include <iostream>
using namespace std;
int main(){
    int n,sum=0,prod=1;
    cout<<"n=";
    cin>>n;
    for(int i=1; i<=n;i++){
        prod*=i;
        sum+=prod;
    }
    cout<<"this number="<<sum;
    return 0;
}