#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;

vector<vector<bool>> incidence_matrix;
vector<bool> visited;
vector<int> disc, low; // час відкриття вершин; масив для перевірки мостів
vector<pair<int, int>> bridges;
int timer = 0;

void dfs(int v, int p = -1) { // алгоритм Тар'яна (Tarjan's algorithm)
    visited[v] = true;
    disc[v] = low[v] = timer++;
    for (int to = 0; to < incidence_matrix.size(); ++to)
        if (incidence_matrix[v][to]) { // equivalent to: for (auto &to: adjacency_list[v])
            if (to == p) // не вертаємося до батьківської вершини
                continue;
            if (visited[to])
                low[v] = min(low[v], disc[to]); // якщо утворився цикл, всім цим вершинам присвоїти час входження першої
            else {
                dfs(to, v);
                low[v] = min(low[v], low[to]); // порівнюємо з дочірнім вузлом бектрекінгом
                if (low[to] > disc[v]) // умова моста, дочірня не з'єднувалася з предками v
                    bridges.emplace_back(min(v, to), max(v, to));
            }
        }
}

void find_bridges() {
    visited.assign(incidence_matrix.size(), false);
    disc.assign(incidence_matrix.size(), -1);
    low.assign(incidence_matrix.size(), -1);
    bridges.reserve(incidence_matrix.size() - 1); // max n - 1 для дерев
    for (int i = 0; i < incidence_matrix.size(); ++i) // якщо ліс
        if (!visited[i])
            dfs(i);
}

// Для заданого зв'язного графа знайти всі мости. Граф представити за допомогою матриці суміжності.
// Мостом в графі називається ребро, за відсутності якого граф перестає бути зв'язним.

int main() {
    size_t n{}, m{};
    cout << "input number of vertices and edges in undirected graph: ";
    cin >> n >> m;
    incidence_matrix.assign(n, vector<bool>(n));
    cout << "input edges (from to) (vertex [0, n-1]):\n";
    for (int tmp1, tmp2, i = 0; i < m; ++i) {
        cin >> tmp1 >> tmp2;
        incidence_matrix[tmp1][tmp2] = true;
        incidence_matrix[tmp2][tmp1] = true; // неорієнтований
    }

    for (const auto &row: incidence_matrix) {
        for (const auto &el: row)
            cout << el << ' ';
        cout << '\n';
    }

    find_bridges();

    ranges::sort(bridges);
    cout << "bridges:\n";
    for (auto &[a, b]: bridges)
        cout << a << ' ' << b << '\n';
    return 0;
}
/*
https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)#/media/File:6n-graf.svg
6 7
0 1
0 4
1 4
1 2
4 3
2 3
3 5
https://en.wikipedia.org/wiki/Tree_(graph_theory)#/media/File:Tree_graph.svg
6 5
0 3
1 3
2 3
3 4
4 5

6 7
0 1
1 2
2 0
2 3
3 4
4 5
5 3
*/
