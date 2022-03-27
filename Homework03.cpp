#include <iostream>
#include <string>

using namespace std;

int Cin(){
    int n;
    cout << "Enter n number:";
    cin >> n;
    return n;
}

void Cout(unsigned long long value, string plaintext){
    cout << plaintext << value << endl;
}

unsigned long long FirstSequence(int &n){
    if (!n) return 0;
    unsigned long long prod = 1, num = 1, sum = 0;
    for (int i = 1; num <= n; ++i){
        for (int j = 0; j < i && num <= n; ++j){
            sum += num++;
        }
        prod *= sum;
        sum = 0;
    }
    return prod;
}

unsigned long long SecondSequence(int  &n) {
    unsigned long long sum = 0, prod = 1;
    for (int i = 1; i <= n; ++i) {
        prod *= i;
        sum += prod;
    }
    return sum;
}

//Here, after 7 result undetermined, because of enough large product
unsigned long long ThirdSequence(int &n){
    unsigned long long sum = 0, prod = 1;
    for (int i = 1; i <= n; ++i){
        for (int j = i; j <= i*i; ++j){
            prod *= j;
        }
        sum += prod;
        prod = 1;
    }
    return sum;
}

int main03()
{
    int n = Cin();
    Cout(FirstSequence(n), "First sequence result: ");
    Cout(SecondSequence(n), "Second sequence result: ");
    Cout(ThirdSequence(n), "Third sequence result: ");
    return 0;
}