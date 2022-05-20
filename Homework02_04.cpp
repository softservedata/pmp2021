#include <iostream>

using namespace std;


int main()
{
    int n;
    cout << " n = ";
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            if (a[i][j] != a[j][i]) 
            {
                cout << "Not symmetrical" << endl;
                return 0;
            }
        }
    }
    cout << "Symmetrical" << endl;
    return 0;
}