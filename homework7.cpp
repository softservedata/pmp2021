1)
#include <iostream>
using namespace std;
int main() {
    int n;
    cout << " n = ";
    cin >> n ;
    int a[n][n];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> a[i][j];
        }
    }
    int b[n][n];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            b[i][j] = a[j][i];
        }
    }
    cout<< "Transposed matrix : "<<endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}	








2)
	
#include <iostream>
#include <math.h>
using namespace std;

	
int main()
{
    int n;
    cout << " n = ";
    cin >> n;
    int a[n][n];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(a[i][j] != a[j][i]){
                cout << "Не симетрична"<< endl;
                return 0;
            }
        }
    }
    cout << "Cиметрична"<< endl;
    return 0;
}
