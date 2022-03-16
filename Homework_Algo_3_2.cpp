#include <iostream>
using namespace std;
int main(){
    unsigned long long int n,sum=0,prod=1;
    cout<<"1 + (1 * 2) + (1 * 2 * 3) + ... + (1 * 2 * ... * n)"<<endl;
    cout<<"n=";
    cin>>n;
    for(int i=1; i<=n;i++){
        prod*=i;
        sum+=prod;
    }
    cout<<"this number="<<sum;
    return 0;
}