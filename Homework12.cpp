#include <iostream>

using namespace std;

void graphInc7(int**& matrix, int*& vector, int& n)
{
    n = 7;
    matrix = new int* [n] {
            new int[n] { 2, 4},
            new int[n] { 2, 3 },
            new int[n] { 0, 1, 3, 4 },
            new int[n] { 1, 2 },
            new int[n] { 0, 2, 5 },
            new int[n] { 4, 6},
            new int[n] { 5}
    };
    vector = new int[] { 2, 2, 4, 2, 3, 2, 1};
    for (int i = 0; i < n; i++)
    {
        for (int j = vector[i]; j < n; j++)
        {
            matrix[i][j] = -1;
        }
    }
}

bool isRoute(int** graph, int* vector, int vert0, int vert1)
{
    for (int i = 0; i < vector[vert0]; ++i){
        if (graph[vert0][i] == vert1) return true;
    }
    return false;
}

void matrix_delete(int** &matrix, int &n){
    for (int i = 0; i < n; ++i){
        delete [] matrix[i];
    }
    delete [] matrix;
}

void array_delete(int *arr){
    delete[] arr;
}

int main(){
    int n;
    int** graph;
    int* vector;

    graphInc7(graph, vector, n);

    cout << "IsRoute between 4 and 2: " << boolalpha << isRoute(graph, vector, 4, 2) << endl;
    cout << "IsRoute between 5 and 1: " << boolalpha << isRoute(graph, vector, 5, 1) << endl;
    cout << "IsRoute between 6 and 5: " << boolalpha << isRoute(graph, vector, 6, 5) << endl;
    cout << "IsRoute between 0 and 1: " << boolalpha << isRoute(graph, vector, 0, 1) << endl;
    cout << "IsRoute between 3 and 5: " << boolalpha << isRoute(graph, vector, 3, 5) << endl;

    matrix_delete(graph, n);
    array_delete(vector);
    return 0;
}