#include <iostream>
using namespace std;

// Порівняти вміст двох дійсних масивів. 
//  Використати за основу код із заняття.
//  Створити hash функцію для дійсних чисел. 


int getMax(double* arr, int n)
{
	double max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}

int getMin(double* arr, int n)
{
	double min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
	}
	return min;
}


double* input(int n)
{
	double arr[1000]{};

	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]=";
		cin >> arr[i];
	}

	return arr;
}


void output(double arr[], int a)
{
	for (int i = 0; i < a; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


int getRange(double* arr, int n)
{
	return getMax(arr, n) - getMin(arr, n) + 1;
}

int getMaxTwo(double arg0, double arg1)
{
	return arg0 > arg1 ? arg0 : arg1;
}

int getMinTwo(double arg0, double arg1)
{
	return arg0 < arg1 ? arg0 : arg1;
}

int getDelta(double arg0, double arg1)
{
	return -getMinTwo(arg0, arg1);
}


int hashCode(double arg, double delta)
{
	return arg + delta;
}

bool isEqual(double* hash1, double* hash2, int n)
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
	int n1;
	int n2;

	cout << "Enter count of elements in first array ";
	cin >> n1;

	double* arr1 = input(n1);

	cout << "Enter count of elements in second array ";
	cin >> n2;

	double* arr2 = input(n2);

	output(arr1, n1);
	output(arr2, n2);
	cout << endl;


	int delta = getDelta(getMin(arr1, n1), getMin(arr2, n2));
	int n = getMaxTwo(getRange(arr1, n1), getRange(arr2, n2));
	double* hash1 = new double[n];
	double* hash2 = new double[n];

	for (int i = 0; i < n; i++)
	{
		hash1[i] = 0;
		hash2[i] = 0;
	}

	cout << "delta = " << delta << endl;

	for (int i = 0; i < n1; i++)
	{
		hash1[hashCode(arr1[i], delta)] = arr1[i];
	}

	for (int i = 0; i < n2; i++)
	{
		hash2[hashCode(arr2[i], delta)] = arr2[i];
	}

	cout << "first hash equal = ";
	for (int i = 0; i < n; i++)
	{
		cout << hash1[i] << "  ";
	}
	cout << endl;

	cout << "second hash equal = ";
	for (int i = 0; i < n; i++)
	{
		cout << hash2[i] << "  ";
	}
	cout << endl;

	cout << "is Equal? = " << (isEqual(hash1, hash2, n) ? "true" : "false") << endl;

	return 0;

}