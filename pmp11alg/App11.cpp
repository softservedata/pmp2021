#include<iostream>
using namespace std;

void graphInc5(int**& matrix, int*& vector, int& n)
{
	matrix = new int* [] {
			new int[] { 1, 2 },
			new int[] { 0, 2 },
			new int[] { 0, 1, 3 },
			new int[] { 2, 4 },
			new int[] { 3 }
	};
	vector = new int[] { 2, 2, 3, 2, 1};
	n = 5;
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

void setPrn(int* set, int n, const char* message)
{
	cout << "\nMatrix " << message << endl;
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
		if (set[i] == -1)
		{
			result = i;
			break;
		}
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
	if (!isPresent)
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
		if (!isPresent)
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
		}
	}
}



int main11a()
{
	// Check Set
	int* set0;
	int* set1;
	int n = 5;
	//
	setInit(set0, n);
	setInit(set1, n);
	setPrn(set0, n, "Origin set0");
	setPrn(set1, n, "Origin set1");
	//
	setAdd(set0, 2, n);
	setAdd(set0, 3, n);
	setAdd(set1, 1, n);
	setAdd(set1, 3, n);
	setPrn(set0, n, "Add Elem set0");
	setPrn(set1, n, "Add Elem set1");
	//
	//setAdd(set0, set1, n);
	//setPrn(set0, n, "Add set0 = set0 + set1");
	// 
	setSub(set0, set1, n);
	setPrn(set0, n, "Add set0 = set0 - set1");
	//
	//
	graphVecDel(set0);
	graphVecDel(set1);
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}