#include <iostream>

using namespace std;


int main () {
    int n;
    cout << "n=";
    cin >> n;
    cout << "\n";
    int a[n][n], b[n][n], c[n][n];
    cout << "enter a matrix\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
    cout << "enter b matrix\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> b[i][j];
        }
    }
    cout << "enter c matrix\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> c[i][j];
        }
    }
    int d[n][n];
    cout << "sum of three matrix: \n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            d[i][j] = a[i][j] + b[i][j] + c[i][j];
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

