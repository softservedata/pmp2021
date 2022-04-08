#include<iostream>
using namespace std;

int getMax(int* arr, int n)
{
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}

int getMin(int* arr, int n)
{
	int min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
	}
	return min;
}

int getRange(int* arr, int n)
{
	return getMax(arr, n) - getMin(arr, n) + 1; // 0 and last element
}

int getMaxTwo(int arg0, int arg1)
{
	return arg0 > arg1 ? arg0 : arg1;
}

int getMinTwo(int arg0, int arg1)
{
	return arg0 < arg1 ? arg0 : arg1;
}

int getDelta(int arg0, int arg1)
{
	return -getMinTwo(arg0, arg1);
}


int hashCode(int arg, int delta)
{
	return arg + delta;
}

bool isEqual(int* hash1, int* hash2, int n)
{
	bool result = true;
	for (int i = 0; result && (i < n); i++)
	{
		result = hash1[i] == hash2[i];
	}
	return result;
}

int main()
{
	int n1 = 8;
	int n2 = 5;
	int* arr1 = new int[] { 1, 8, 2, 1, 4, 8, 1, 2 };
	int* arr2 = new int[] { 1, 2, 4, 8, 2 };
	//
	int delta = getDelta(getMin(arr1, n1), getMin(arr2, n2));
	int n = getMaxTwo(getRange(arr1, n1), getRange(arr2, n2));
	int* hash1 = new int[n];
	int* hash2 = new int[n];
	//
	for (int i = 0; i < n; i++)
	{
		hash1[i] = 0;
		hash2[i] = 0;
	}
	//
	cout << "delta = " << delta << endl;
	// 
	//
	for (int i = 0; i < n1; i++)
	{
		hash1[hashCode(arr1[i], delta)] = arr1[i];
	}
	//
	for (int i = 0; i < n2; i++)
	{
		hash2[hashCode(arr2[i], delta)] = arr2[i];
	}
	//
	cout << "hash1 = ";
	for (int i = 0; i < n; i++)
	{
		cout << hash1[i] << "  ";
	}
	cout << endl;
	//
	//
	cout << "hash2 = ";
	for (int i = 0; i < n; i++)
	{
		cout << hash2[i] << "  ";
	}
	cout << endl;
	//
	cout << "isEqual = " << (isEqual(hash1, hash2, n) ? "true" : "false") << endl;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
