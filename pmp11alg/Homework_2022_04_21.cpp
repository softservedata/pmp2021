#include <iostream>
#include <queue>
int graph[1001][1001], d[1001];
std::queue <int> q;

int main() {
    std::ios_base::sync_with_stdio(false);
    int n, x, v;
    std::cout << "Enter adjacency matrix n amd m size: ";
    std::cin >> n >> x;
    x--;
    std::cout << "Enter matrix"<< std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "adjacency matrix element[" << i << "][" << j << "]: ";
            std::cin >> graph[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        d[i] = -1;
    }
    q.push(x);
    d[x] = 0;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (d[i] == -1 && graph[v][i]) {
                q.push(i);
                d[i] = d[v] + 1;
            }
        }
    }
    std::cout << "\nYour result" << std::endl;
    for(int i = 0; i < n; i ++) {
        std::cout << d[i] << " ";
    }
}
