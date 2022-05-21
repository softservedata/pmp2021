#include <iostream>;

using namespace std;
int sum_2(int n, int m);
int main(){
    int n;
    cin >> n;
    sum_2(n,0);
    return 0;
}
int sum_2(int n, int m)
{
    int sum;
    if (n==0){
        return 0;
    }
    else{
        sum += sum_2(n - (m+2), );
    }
    return sum;
}
