#include <iostream>
using namespace std;
int recurssum(int n);
int main(){
    int n;
    cout << " n + (n - 2) + (n - 4) + ... + 0 \n (n >= 0) \n n = ";
    cin>>n;
    cout<<"recurs sum="<<recurssum(n);
    return 0;
}
int recurssum(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return n+recurssum(n-2);
    }
}