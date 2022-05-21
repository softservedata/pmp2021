#include <iostream>

 using namespace std;
int const n =20; 
int timer, tin[n], fup[n];
bool used[n];
int mx[n][n];
 
void find (int v, int p = -1) 
{
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (int i = 0; i < n; ++i)
    {
        if(mx[v][i] == 1)
        {
            int to = i;
            if (to == p)  continue;
            if (used[to]) fup[v] = min (fup[v], tin[to]);
            else
            {
                find (to, v);
                fup[v] = min (fup[v], fup[to]);
                if (fup[to] > tin[v]) cout << "bridge: (" << v << " , " << to << ")\n";
            }
        }
    }
}
 
void find_bridges() // poisk mostov
{
    timer = 0;
    for(int i = 0; i < n; ++i)
    {
        used[i] = false;
    }
    for(int i = 0; i < n; ++i)
    {
        if(!used[i]) find(i);
    }
}
 
int main()
{
    int n;
    cout << " n = ";
    cin >> n ;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> mx[i][j] ;
        }
    }
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << mx[i][j] << "  ";
        }
        cout << "\n";
    }
    find_bridges();
    return 0;
}
/*
0  0  2  1  
0  0  0  1  
1  1  2  1  
1  0  0  0 */
