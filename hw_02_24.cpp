#include <iostream>

using namespace std;
int sum(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    return n + sum(n - 1);
}
int fact(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

long task_1(int n){
    if (n!=1){
        return sum(n)*task_1(n-1);
    }
    else{
        return 1;
    }
}
long task_2(int n){
    if (n!=1){
        return fact(n)+task_2(n-1);
    }
    else{
        return 1;
    }
}
int task_3(int n)
{
    int s = 0;
    for (int k = 1; k <= n; k++)
    {
        int p = 1;
        for (int i = 0; i <= ((k - 1) * k); i++)
            p *= (k + i);
        s += p;
    }
    return s;
}
int main(){
    int n = 5;
    cout << task_1(n) << "\n";
    cout << task_2(n) << "\n";
    cout << task_3(n) << "\n";
};