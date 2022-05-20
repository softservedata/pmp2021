#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<bool> used;
vector<int> tin, fup;
vector<pair<int, int>> bridges;
int timer;

void read_graph(){
    int n, m;
    cout << "n - numbers of vertex, m - numbers of edge\nn=";
    cin >> n;
    cout << "m=";
    cin >> m;
    g.resize(n), used.resize(n), tin.resize(n), fup.resize(n);
    int v, to;
    for(int i = 0; i < m; ++i){
        cout << "v=";
        cin >> v;
        cout << "to=";
        cin >> to;
        g[v - 1].push_back(to - 1);
    }
}

void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p) {
            continue;
        }
        if (used[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] > tin[v]) {
                bridges.push_back({min(v, to), max(v, to)});
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    for (int i = 0; i < g.size(); ++i) {
        used[i] = false;
    }
    for (int i = 0; i < g.size(); ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    cout << "Bridges:\n";
    for (auto bridge : bridges){
        cout << bridge.first + 1 << " " << bridge.second + 1;
    }
}

int main(){
    read_graph();
    find_bridges();
}