
#include <iostream>
#include <fstream>
using namespace std;

void matrixGraphRead(int**& matrix, int& n,const char *fileName)
{
	ifstream f(fileName);
	f >> n;
	matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			f >> matrix[i][j];
		}
	}
	f.close();
}

void matrixGraphDelete(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void matrixGraphPrint(int** matrix, int n, const char* message)
{
	cout << "\nMatrix " << message << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << "\t ";
			//cout << *(*(matrix + i) + j) << "  ";
		}
		cout << endl;
	}
}


int** matrixGraphMultiply2(int** a, int** b, int n)
{
	int sum = 0;
	int** c = new int* [n];
	for (int i = 0; i < n; i++)
	{
		c[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			sum = 0;
			for (int l = 0; l < n; l++)
			{
				sum = sum + a[i][l] * b[l][j];
			}
			c[i][j] = sum;
		}
	}
	return c;
}

int** matrixGraphCopy2(int** a, int n) // C++ style
{
	int** c = new int* [n];
	for (int i = 0; i < n; i++)
	{
		c[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			c[i][j] = a[i][j];
		}
	}
	return c;
}
bool isRoute(int** matrix, int n, int vertexBegin, int vertexEnd)
{
	bool result = false;
	int** c = NULL;
	int** temp = NULL;
	//
	if ((n < 1) || (vertexBegin >= n) || (vertexEnd >= n))
	{
		return false;
	}
	if (matrix[vertexBegin][vertexEnd] > 0)
	{
		return true;
	}
	//
	c = matrixGraphCopy2(matrix, n);
	for (int i = 0; !result && (i < n - 1); i++)
	{
		temp = c;
		c = matrixGraphMultiply2(matrix, c, n);
		matrixGraphDelete(temp, n);
		result = (c[vertexBegin][vertexEnd] > 0);
		//cout << "c[vertexBegin][vertexEnd] = " << c[vertexBegin][vertexEnd] << endl;
		//matrixGraphPrint(c, n, "C");
	}
	matrixGraphDelete(c, n);
	return result;
}

bool isConnect(int** matrix, int n)
{
	bool res = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!isRoute(matrix, n, i, j))
			{
				res = false;
				break;
			}
		}
	}
	return res;
}

void printBridges(int** matrix, int n)
{
	bool isBridges = false;//there are no bridges
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i!=j && matrix[i][j]==1)
			{
				matrix[i][j] = 0;
				matrix[j][i] = 0;
				if (!isConnect(matrix, n))
				{
					cout << "Bridge: [" << i+1 << "," << j+1 << "]" << endl;
					isBridges = true;

				}
				matrix[i][j] = 1;
				matrix[j][i] = 1;
			}
		
		}
	}
	if (!isBridges)
	{
		cout << "There are no bridges" << endl;
	}

}
int main()
{
	int** matrix;
	int n;

	matrixGraphRead(matrix, n, "Graph10_2.txt");
	matrixGraphPrint(matrix, n, "Graph 2");

	printBridges(matrix, n);

	matrixGraphDelete(matrix, n);

	return 0;
}
