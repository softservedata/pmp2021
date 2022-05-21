#include <iostream>
using namespace std;

void graphInc5(int**& matrix, int*& vector, int& n)
{
	n = 5;
	matrix = new int* [n] {
		new int[n] { 1, 2 },
			new int[n] { 0, 2 },
			new int[n] { 0, 1, 3 },
			new int[n] { 2},
			new int[n] { 3 }
	};
	vector = new int[] { 2, 2, 3, 1, 1};
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

void graphVecDel(int* vector)
{
	delete[] vector;
}

void graphPrn(int** matrix, int* vector, int n, const char* message)
{
	cout << "\nMatrix " << message << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i << ":\t";
		for (int j = 0; j < vector[i]; j++)
		{
			cout << matrix[i][j] << "\t ";
			//cout << *(*(matrix + i) + j) << "  ";
		}
		cout << endl;
	}
}


bool isRoute1(int** graph, int* vector, int n, int vert0, int vert1,bool*& visited)
{
	// TODO Homework
	if (vert0 == vert1)
	{
		return true;
	}
	visited[vert0] = true;
	for (int i = 0; i < vector[vert0]; i++)
	{
		int v = graph[vert0][i];
		if (!visited[v])
		{
			if (isRoute1(graph, vector, n, v, vert1, visited))
			{
				return true;
			}
		}
	}

	return false;

	return 0;
}

bool isRoute(int** graph, int* vector, int n, int vert0, int vert1)
{
	// TODO Homework
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}

	return isRoute1(graph,vector,n,vert0,vert1,visited);
}


int main()
{
	int n;
	int** graph;
	int* vector;
	//
	graphInc5(graph, vector, n);
	graphPrn(graph, vector, n, "1");

	int vert1;
	cout << "Input vertix 1:" << endl;
	cin >> vert1;

	int vert2;
	cout << "Input vertix 2:" << endl;
	cin >> vert2;

	string result = isRoute(graph, vector, n,vert1,vert2)? "true" : "false";
	cout << "isRoute = " << result << endl;

	graphMatDel(graph, n);
	graphVecDel(vector);
}

