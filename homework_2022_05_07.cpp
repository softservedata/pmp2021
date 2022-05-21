#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> used;

void init_graph(){
    int n,m, v;
    cout << "n - numbers of vertex\nn=";
    cin >> n;
    graph.resize(n);
    used.resize(n, false);
    cout << "m - numbers of neighbours for vertex\n";
    for(int i = 0; i < n; ++i){
        cout << "m for " << i + 1 << " vertex=";
        cin >> m;
        for(int j = 0; j < m; ++j){
            cout << j + 1 << " neighbour for vertex " << i + 1 << "=";
            cin >> v;
            graph[i].push_back(v - 1);
        }
    }
}

void dfs(int v){
    used[v] = true;
    for(int neighbour : graph[v]){
        if(!used[neighbour]){
            dfs(neighbour);
        }
    }
    return;
}

int main(){
    init_graph();
    int from, to;
    cout << "from - route start; to - route end\nfrom=";
    cin >> from;
    cout << "to=";
    cin >> to;
    dfs(from - 1);
    if(used[to - 1]){
        cout << "Route exist";
    } else{
        cout << "Route doesn't exist";
    }
}