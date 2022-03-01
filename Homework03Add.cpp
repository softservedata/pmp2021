#include <iostream>
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

unsigned long long UniqueSequence(int &n){
    unsigned long long sum = 0, num = 1, prod = 1;
    for (int i = 1; num <= n; ++i){
        for (int j = 0; j < i && num <= n; ++j){
            prod *= num++;
        }
        sum += prod;
        prod = 1;
    }
    return sum;
}

int main03Add(){
    int n = Cin();
    Cout(UniqueSequence(n), "Unique sequence resul: ");
    return 0;
}