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
	set = new int[n + 1];
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
	bool isPresent = false;
	int n0 = lastFreePosSet(set0, n);
	int n1 = lastFreePosSet(set1, n);
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
	bool isPresent = false;
	int n0 = lastFreePosSet(set0, n);
	int n1 = lastFreePosSet(set1, n);
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

bool isRoute(int** graph, int* vector, int n, int vert0, int vert1)
{
	// TODO Homework *done*

	for (int i = 0; i < vector[vert0]; i++) {
		if (graph[vert0][i] == vert1)
			return true;
	}
	return false;
}

bool isGraphRoute(int** graph, int* vector, int n)
{
	int vertex = -1;
	int* setTodo;
	int* setVisited;

	graphPrn(graph, vector, n, "isGraphRoute Graph ");

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
		cout << " vertex = " << vertex << endl;

		setAdd(setVisited, vertex, n);


		setSub(setTodo, setVisited, n);

	}

	return isSetFull(setVisited, n);
}


int main()
{

	int n;
	int** graph;
	int* vector;
	graphInc5(graph, vector, n);
	string result = isGraphRoute(graph, vector, n) > 0 ? "true" : "false";
	cout << "isGraphRoute = " << result << endl;
	//example of working first isn't route, second is route
	cout << "is vertex 2 and vertex 4 route " << boolalpha << isRoute(graph, vector, n, 2, 4) << endl;
	cout << "is vertex 0 and vertex 2 route " << boolalpha << isRoute(graph, vector, n, 0, 2) << endl;
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}