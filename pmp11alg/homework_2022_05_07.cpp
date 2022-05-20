#include<iostream>
using namespace std;

void graphInc5(int**& matrix, int*& vector, int& n)
{
    n = 5;
    matrix = new int* [n] {
            new int[n] { 1, 2 },
            new int[n] { 0, 2 },
            new int[n] { 0, 1, 3 },
            new int[n] { 2, 4 },
            new int[n] { 3 }
    };
    vector = new int[] { 2, 2, 3, 2, 1};
    //
    for (int i = 0; i < n; i++)
    {
        for (int j = vector[i]; j < n; j++)
        {
            matrix[i][j] = -1;
        }
    }
}

void graphMatDel(int** matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}


void graphPrn(int** matrix, int* vector, int n, const char* message)
{
    cout << "\nMatrix " << message << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < vector[i]; j++)
        {
            cout << matrix[i][j] << "\t ";
            //cout << *(*(matrix + i) + j) << "  ";
        }
        cout << endl;
    }
}

void setInit(int*& set, int n)
{
    set = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        set[i] = -1;
    }
}


int lastFreePosSet(const int* set, int n)
{
    int result = n;
    for (int i = 0; i < n; i++)
    {
        if (set[i] < 0)
        {
            result = i;
            break;
        }
    }
    return result;
}

int getFirstElement(const int* set, int n)
{
    int result = -1;
    if (n > 0)
    {
        result = set[0];
    }
    return result;
}

void setAdd(int* set0, int element, int n)
{
    bool isPresent = false;
    int n0 = lastFreePosSet(set0, n);
    //
    for (int i0 = 0; i0 < n0; i0++)
    {
        if (set0[i0] == element)
        {
            isPresent = true;
            break;
        }
    }
    if ((!isPresent) && (n0 < n))
    {
        set0[n0] = element;
        n0 = n0 + 1;
    }
}

void setAdd(int* set0, const int* set1, int n)
{
    bool isPresent = false;
    int n0 = lastFreePosSet(set0, n);
    int n1 = lastFreePosSet(set1, n);
    //
    //setPrn(set0, n0, " set0 ");
    //setPrn(set1, n1, " set1 ");
    // TODO Update method to O(n)
    for (int i1 = 0; i1 < n1; i1++)
    {
        isPresent = false;
        for (int i0 = 0; i0 < n0; i0++)
        {
            if (set1[i1] == set0[i0])
            {
                isPresent = true;
                break;
            }
        }
        if ((!isPresent) && (n0 < n))
        {
            set0[n0] = set1[i1];
            n0 = n0 + 1;
        }
    }
}


void setSub(int* set0, const int* set1, int n)
{
    bool isPresent = false;
    int n0 = lastFreePosSet(set0, n);
    int n1 = lastFreePosSet(set1, n);
    //
    //setPrn(set0, n0, " setSub set0 ");
    //setPrn(set1, n1, " setSub set1 ");
    //
    // TODO Update method to O(n)
    for (int i0 = 0; i0 < n0; i0++)
    {
        isPresent = false;
        for (int i1 = 0; i1 < n1; i1++)
        {
            if (set0[i0] == set1[i1])
            {
                isPresent = true;
                break;
            }
        }
        if (isPresent)
        {
            for (int j = i0; j < n0; j++)
            {
                set0[j] = set0[j + 1];
            }
            n0 = n0 - 1;
            i0--; // Architecture Error
        }
    }
}

bool isSetEmpty(int* set, int n)
{
    return lastFreePosSet(set, n) == 0;
}

bool isSetFull(int* set, int n)
{
    return lastFreePosSet(set, n) == n;
}

bool vertexInSet(int vert, int* arr, int n) {
    bool check = false;
    for(int i = 0; i < n; i++){
        if(arr[i]==vert){
            check = true;
            break;
        }
    }
}


bool isRoute(int** graph, int* vector, int n, int vert0, int vert1)
{
    bool check=false;
    int vertex;
    int* setTodo;
    int* setVisited;
    setInit(setTodo, n);
    setInit(setVisited, n);
    vertex=vert0;
    setAdd(setTodo, vertex, n);
    while (!isSetEmpty(setTodo, n)){
        vertex = getFirstElement(setTodo, n);
        if (vertex < 0){
            break;
        }
        setAdd(setVisited, vertex, n);
        setAdd(setTodo, graph[vertex], n);
        if(vertexInSet(vert1, setTodo, n)){
            check = true;
            break;
        }
        setSub(setTodo, setVisited, n);
    }
    delete[] setTodo;
    delete[] setVisited;
    return check;
}


void read(int& vert, const char* vert_number, int n){
    do {
        cout << vert_number;
        cin >> vert;
    } while ((vert < 0) || (vert>=n));
}

int main()
{
    int n, vert0, vert1;
    int** graph;
    int* vector;

    graphInc5(graph, vector, n);
    cout<<"reading vert0 and vert1 for finding the route"<<endl;
    read(vert0, "first vert= ", n);
    read(vert1, "second vert= ", n);
    string result = isRoute(graph, vector, n, vert0, vert1) > 0 ? "true" : "false";
    cout <<endl<< "Is there route between first and second vert?\n " << result << endl;
    delete[] vector;
}
