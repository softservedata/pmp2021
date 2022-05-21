/*#include<iostream>
using namespace std;
int n;
int** readGraph(int& n);
int min(int a, int b);
void bridgeFind(int start, bool visited[], int disc[], int low[], int parent[], int**& graph);
void Bridges(int**& graph);

int main() {
    int** graph = readGraph(n);
    cout << "Bridges in given graph:" << endl;
    Bridges(graph);
}
int** readGraph(int& n) {
    cout << "\nInput new Graph:\n";
    do {
        cout << "n =";
        cin >> n;
    } while (n < 1);

    cout << "Input Graph with n = " << n << endl;
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}
int min(int a, int b) {
    return (a < b) ? a : b;
}
void Bridges(int**& graph) {
    bool* vis = new bool[n];
    int* disc = new int[n];
    int* low = new int[n];
    int* parent = new int[n];

    for (int i = 0; i < n; i++) {
        vis[i] = false;
        parent[i] = -1;
    }

    for (int i = 0; i < n; i++)
        if (!vis[i])
            bridgeFind(i, vis, disc, low, parent, graph);
}
void bridgeFind(int start, bool visited[], int disc[], int low[], int parent[], int**& graph) {
    static int time = 0;
    visited[start] = true;
    disc[start] = low[start] = ++time;

    for (int v = 0; v < n; v++) {
        if (graph[start][v]) {
            if (!visited[v]) {
                parent[v] = start;
                bridgeFind(v, visited, disc, low, parent, graph);

                low[start] = min(low[start], low[v]);
                if (low[v] > disc[start])
                    cout << "Bridge " << start << "--" << v << endl;
            }
            else if (v != parent[start])
                low[start] = min(low[start], disc[v]);
        }
    }
}*/