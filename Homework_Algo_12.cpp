#include<iostream>
using namespace std;

void graphIndentification(int**& matrix, int*& vector, int& n)
{
    do {
        cout << "n = ";
        cin >> n;
    } while (n <= 0);
    cout<<"reading vertex which are neighbouring to each other "<<endl;
    matrix = new int* [n];
    for(int i=0;i<n;i++){
        matrix[i]=new int[n];
    }
    vector = new int[n];
    for(int i=0; i<n; i++){
        cout<<endl<<"number of neighbours for vertex"<<i<<" = ";
        cin>>vector[i];
        cout<<"enter this neighbours please:"<<endl;
        for(int j=0; j<vector[i];j++){
            cout<<"neighbour number "<<j<<" for vertex "<<i<<" = ";
            cin>>matrix[i][j];
        }
        if(vector[i]==0){
            cout<<"no neighbours"<<endl;
        }
    }
    cout<<endl<<endl;
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

void graphVecDel(int* vector)
{
    delete[] vector;
}

void graphPrn(int** matrix, int* vector, int n, const char* message)
{
    cout << "\nMatrix " << message << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < vector[i]; j++)
        {
            cout << matrix[i][j] << "\t ";
        }
        cout << endl;
    }
}

void setInit(int*& set, int n)
{
    set = new int[n+1];
    for (int i = 0; i <= n; i++)
    {
        set[i] = -1;
    }
}

void setPrn(const int* set, int n, const char* message)
{
    cout << "\nSet " << message << endl;
    for (int i = 0; i < n; i++)
    {
        cout << set[i] << "\t ";
    }
    cout << endl;
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
    int n0 = lastFreePosSet(set0, n);
    int n1 = lastFreePosSet(set1, n);
    int* arr1=nullptr;
    int* arr2=nullptr;
    setInit(arr1, n);
    setInit(arr2, n);
    for (int i1 = 0; i1 < n0; i1++){
        arr1[set0[i1]]=1;
    }
    for (int i2 = 0; i2 < n1; i2++){
        arr2[set1[i2]]=1;
    }
    for(int i=0; i<n; i++){
        if((arr1[i]==-1) && (arr2[i]==1) && (n0<n)){
            set0[n0]=i;
            n0=n0+1;
        }
    }
    delete[]arr1;
    delete[]arr2;
}

void setSub(int* set0, int element, int n)
{
    int n0 = lastFreePosSet(set0, n);
    for (int i0 = 0; i0 < n0; i0++)
    {
        if (set0[i0] == element)
        {
            for (int j = i0; j < n0; j++)
            {
                set0[j] = set0[j + 1];
            }
            n0 = n0 - 1;
            break;
        }
    }
}

void setSub(int* set0, const int* set1, int n)
{
    int n0 = lastFreePosSet(set0, n);
    int n1 = lastFreePosSet(set1, n);
    int* arr1=nullptr;
    int* arr2=nullptr;
    setInit(arr1, n);
    setInit(arr2, n);
    for (int i1 = 0; i1 < n0; i1++){
        arr1[set0[i1]]=1;
    }
    for (int i2 = 0; i2 < n1; i2++){
        arr2[set1[i2]]=1;
    }
    for(int i=0; i<n0; i++){
        set0[i]=-1;
    }
    int s=0;
    for(int i=0; i<n; i++){
        if((arr1[i]==1) && (arr2[i]==-1) && s<n0){
            set0[s]=i;
            s=s+1;
        }
    }
    delete[]arr1;
    delete[]arr2;
}

bool isSetEmpty(int* set, int n)
{
    return lastFreePosSet(set, n) == 0;
}

bool isSetFull(int* set, int n)
{
    return lastFreePosSet(set, n) == n;
}


bool vertexInSet(int vert, int* arr, int n){
    bool check=false;
    for(int i=0; i<n; i++){
        if(arr[i]==vert){
            check=true;
            break;
        }
    }
    return check;
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
    while (!isSetEmpty(setTodo, n))
    {
        vertex = getFirstElement(setTodo, n);
        if (vertex < 0)
        {
            break;
        }
        setAdd(setVisited, vertex, n);
        setAdd(setTodo, graph[vertex], n);
        if(vertexInSet(vert1, setTodo, n)){
            check=true;
            break;
        }
        setSub(setTodo, setVisited, n);
    }
    delete[] setTodo;
    delete[] setVisited;
    return check;
}

bool isGraphRoute(int** graph, int* vector, int n)
{
    bool check=false;
    int vertex = -1;
    int* setTodo;
    int* setVisited;
    setInit(setTodo, n);
    setInit(setVisited, n);
    for (int i = 0; i < n; i++)
    {
        if (vector[i] > 0)
        {
            vertex = i;
            break;
        }
    }
    setAdd(setTodo, vertex, n);
    while (!isSetEmpty(setTodo, n))
    {
        vertex = getFirstElement(setTodo, n);
        if (vertex < 0)
        {
            break;
        }

        setAdd(setVisited, vertex, n);
        setAdd(setTodo, graph[vertex], n);
        setSub(setTodo, setVisited, n);
    }
    check=isSetFull(setVisited, n);
    delete[] setTodo;
    delete[] setVisited;
    return check;
}

void readingvert(int& vert, const char* Message, int n){
    do {
        cout << Message;
        cin >> vert;
    } while ((vert < 0) || (vert>=n));
}

void deleting(int**& graph, int n){
    for(int i=0; i<n; i++){
        delete[] graph[i];
    }
    delete[] graph;
}

int main()
{
    int n;
    int** graph;
    int* vector;
    int vert0, vert1;
    graphIndentification(graph, vector, n);
    cout<<"reading vert0 and vert1 for finding the route"<<endl;
    readingvert(vert0, "vert0 = ", n);
    readingvert(vert1, "vert1 = ", n);
    string result = isRoute(graph, vector, n, vert0, vert1) > 0 ? "true" : "false";
    cout <<endl<< "Is there route between vert0 and vert1?  =  " << result << endl;
    delete[] vector;
    deleting(graph, n);
    return 0;
}