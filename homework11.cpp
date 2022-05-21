#include <algorithm> 
#include <iostream> 
#include <vector> 
 using namespace std;

int main()
{
    int first[] = { 5, 15, 25, 35, 55 };
    int second[] = { 10, 5, 55, 20, 30 };
    int n = sizeof(first) / sizeof(first[0]);
    cout<< "Sets example:"<<endl;
 
 
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
    it=set_intersection (first, first+5, second, second+5, v.begin());
                                               // 10 20 0  0  0  0  0  0  0  0
  v.resize(it-v.begin());                      // 10 20

  cout << "The intersection :\n";
  for (it=v.begin(); it!=v.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';
    
    
 
    return 0;
}
