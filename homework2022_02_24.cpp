#include <iostream>

using namespace std;


int main () {
    int n;
    cin >> n;
    int ans = 1, sum = 0, cnt_now = 0, cnt_max = 1;
    for(int i = 1; i <= n; ++i){
        sum += i;
        ++cnt_now;
        if(cnt_now == cnt_max){
            ans *= sum;
            cnt_now = 0;
            cnt_max++;
            sum = 0;
        }
    }
    if(sum != 0) ans *= sum;
    cout << "answer for a: " << ans << "\n";
    ans = 1, sum = 0;
    for(int i = 1; i <= n; ++i){
        ans *= i;
        sum += ans;
    }
    cout << "answer for b: " << sum << "\n";
    ans = 0, sum = 0;
    for(int k = 1; k <= n; ++k){
        ans = 1;
        for(int i = k; i <= k * k; ++i){
            ans *= i;
        }
        sum += ans;
    }
    cout << "answer for c: " << sum;
    return 0;
}

