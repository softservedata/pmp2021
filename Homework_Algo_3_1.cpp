#include <iostream>
using namespace std;
int main(){
    unsigned long long int n,sum=0,prod=1,k=1,sn=1;
    cout<<"1 * (2 + 3) * (4 + 5 + 6) * ... * (... + n)"<<endl;
    cout<<"n=";
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i-sn==0){
            sum=sum+i;
            prod=prod*sum;
            sum=0;
            k=k+1;
            sn=sn+k;
        }
        else if(i==n){
            sum=sum+i;
            prod=prod*sum;
        }
        else{
            sum+=i;
        }
    }
    cout<<"this number="<<prod;
    return 0;
}