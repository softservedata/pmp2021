#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;

bool isRoute(const vector<vector<int>> &graph, const int vertex_from, const int vertex_to) {
    return ranges::find(graph.at(vertex_from), vertex_to) != graph.at(vertex_from).end();
}

int main() {
    vector<vector<int>> adj_lis = {{2, 4},
                                   {2, 3},
                                   {0, 1, 3, 4},
                                   {1, 2},
                                   {0, 2, 5},
                                   {4, 6},
                                   {5}};
    cout << boolalpha <<
         "\nIsRoute between 4 and 2: " << isRoute(adj_lis, 4, 2) <<
         "\nIsRoute between 5 and 1: " << isRoute(adj_lis, 5, 1) <<
         "\nIsRoute between 6 and 5: " << isRoute(adj_lis, 6, 5) <<
         "\nIsRoute between 0 and 1: " << isRoute(adj_lis, 0, 1) <<
         "\nIsRoute between 3 and 5: " << isRoute(adj_lis, 3, 5) << endl;
    return 0;
}