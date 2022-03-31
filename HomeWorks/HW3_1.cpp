#include <iostream>
using namespace std;

int main()
{
    int n, sum = 1, temp_sum = 0, count = 0, l = 1;
    cout << "n=";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (count == l) {
            sum *= temp_sum;
            cout << "tem_sum1 = " << temp_sum << " i=" << i << endl;
            temp_sum = 0;
            count = 0;
            l++;
        }
        if (i == n) {
            temp_sum += i;
            sum *= temp_sum;
            cout << "tem_sum2 = " << temp_sum << " i=" << i << endl;
        }
        count++;
        temp_sum += i;
        cout << "tem_sum4 = " << temp_sum << " i=" << i<< endl;
    }
    cout << "sum=" << sum;
}
