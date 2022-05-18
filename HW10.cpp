#include<iostream>
#define NODE 7
using namespace std;

int graph[NODE][NODE] = {
   {0, 1, 1, 0, 0, 0, 0 },
   {1, 0, 1, 1, 1, 0, 1},
   {1, 1, 0, 0, 0, 0, 0},
   {0, 1, 0, 0, 0, 1, 0},
   {0, 1, 0, 0, 0, 1, 0},
   {0, 0, 0, 1, 1, 0, 0},
   {0, 1, 0, 0, 0, 0, 0}
};

int min(int a, int b) {
    return (a < b) ? a : b;
}

void bridgeFind(int start, bool visited[], int disc[], int low[], int parent[]) {
    static int time = 0;
    visited[start] = true;
    disc[start] = low[start] = ++time;

    for (int v = 0; v < NODE; v++) {
        if (graph[start][v]) {
            if (!visited[v]) {
                parent[v] = start;
                bridgeFind(v, visited, disc, low, parent);

                low[start] = min(low[start], low[v]);
                if (low[v] > disc[start])
                    cout << "Bridge " << start << "--" << v << endl;
            }
            else if (v != parent[start])
                low[start] = min(low[start], disc[v]);
        }
    }
}

void bridges() {
    bool* vis = new bool[NODE];
    int* disc = new int[NODE];
    int* low = new int[NODE];
    int* parent = new int[NODE];

    for (int i = 0; i < NODE; i++) {
        vis[i] = false;
        parent[i] = -1;
    }

    for (int i = 0; i < NODE; i++)
        if (!vis[i])
            bridgeFind(i, vis, disc, low, parent);
}

int main() {
    cout << "Bridges in given graph:" << endl;
    bridges();
}