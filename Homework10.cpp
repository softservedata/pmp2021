#include <iostream>
#include <list>

#define NIL -1

// Зауваження: Матрицю суміжності, вводити коректно

using namespace std;

// Приклад:
/*void matrix_Graph5(int **&matrix, int &n) {
    matrix = new int *[]{
            new int[] {0, 2, 0, 0, 0},
            new int[] {2, 0, 1, 0, 0},
            new int[] {0, 1, 0, 3, 0},
            new int[] {0, 0, 3, 0, 1},
            new int[] {0, 0, 0, 1, 0},
    };
    n = 5;
}*/
// Відповідь: 2-3, 4-5.

// Клас неорієнтованого графа
class Graph {
    int V;
    list<int> *adj;
    void bridgeUtil(int v, bool visited[], int disc[], int low[],
                    int parent[]);

public:
    Graph(int V);
    void add_Edges(int **matrix, int n);

    void bridge();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::add_Edges(int **matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (matrix[i][j] == 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}

// DFS
void Graph::bridgeUtil(int u, bool visited[], int disc[],
                       int low[], int parent[]) {
    static int time = 0;

    visited[u] = true;

    disc[u] = low[u] = ++time;

    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i;

        if (!visited[v]) {
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent);

            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u]) {
                cout << u + 1 << "-" << v + 1 << endl;
            }
        }

        else if (v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}

// Функція на базі DFS для пошуку мостів
void Graph::bridge() {
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    list<int> vertices1;
    list<int> vertices2;

    for (int i = 0; i < V; i++) {
        parent[i] = NIL;
        visited[i] = false;
    }

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent);
}

int** read_matrix(int &n){
    cout << "\nInput new Matrix:\n";
    do {
        cout << "n =";
        cin >> n;
    } while (n < 1);

    cout << "Input Matrix with n = " << n << endl;
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i){
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j){
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

void delete_matrix(int **&matrix, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int n;
    int** matrix = read_matrix(n);

    cout << "\nBridges in graph:\n";
    Graph g1(n);
    g1.add_Edges(matrix, n);
    g1.bridge();

    delete_matrix(matrix, n);

    return 0;
}