#include <iostream>
#include <cmath>
using namespace std;
long double recurentsum(int n);
long double recurssum(int n, int k, int p, int f);
int main(){
    int n;
    cout<<"sin(n) + sin(sin(n - 1)) + sin(sin(sin(n - 2))) + ... + sin(sin(...sin(1))) \n (n >= 1) \n n = ";
    cin>>n;
    cout<<"recurent sum = "<<recurentsum(n)<<endl;
    cout<<"recurs sum = "<<recurssum(n, n, 1, 1)<<endl;
    return 0;
}
long double recurentsum(int n){
    long double s=0,p;
    for(int i=1; i<=n;i++){
        p=sin(i);
        for(int j=1; j<=n-i;j++){
            p=sin(p);
        }
        s+=p;
    }
    return s;
}
long double recurssum(int n, int k, int p, int f){
    if(k==1){
        if(p==n){
            return (long double) sin(1);
        }
        else{
            return (long double) sin(recurssum(n, k,p+1, 0));
        }
    }
    else if(f==0){
        if(k+p==n+1){
            return (long double) sin(k);
        }
        else{
            return (long double) sin(recurssum(n, k, p+1, 0));
        }
    }
    else if(f==1){
        return (long double) recurssum(n, k, p, 0) + (long double) recurssum(n, k-1, p, 1);
    }
}