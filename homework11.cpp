#include <algorithm> 
#include <iostream> 
#include <vector> 
 using namespace std;

int main()
{
    int first[] = { 5, 10, 15, 20, 25 };
    int second[] = { 50, 40, 30, 20, 10 };
    int n = sizeof(first) / sizeof(first[0]);
    cout<< "sets:"<<endl;
 
 
    for (int i = 0; i < n; i++)
        cout << " " << first[i];
    cout << "\n";
 
    
    for (int i = 0; i < n; i++)
        cout << " " << second[i];
    cout << "\n";
 
    vector<int> v(10);
    vector<int>::iterator it, st;
 
    sort(first, first + n);
    sort(second, second + n);
 
    
    it = set_union(first, first + n, second,
                        second + n, v.begin());
 
    cout << "The union:\n";
    for (st = v.begin(); st != it; ++st)
        cout << ' ' << *st;
    cout << '\n';
    
    
 
    return 0;
}
