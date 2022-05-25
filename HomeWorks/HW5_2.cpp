#include <iostream>
using namespace std;

int recursive_sum(int n);

int main(){
    int n;
    cout << "n=";
    cin >> n;
    cout << "sum= " << recursive_sum(n) << endl;
    system("PAUSE");
    return 0;
}

int recursive_sum(int n){
    if(n<=2) return n;
    return recursive_sum(n-2)+n;

}