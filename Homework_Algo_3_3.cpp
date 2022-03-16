#include <iostream>
using namespace std;
int main(){
    unsigned long long int n,sum=0,product=1;
    cout<<"1 + (2 * 3 * 4) + (3 * 4 * 5 * 6 * 7 * 8 * 9) + ... + (n * ... * n^2)"<<endl;
    cout<<"n=";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=i*i;j++){
            product*=j;
        }
        sum+=product;
        product=1;
    }
    cout<<"this number="<<sum;
    return 0;
}