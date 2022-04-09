#include<iostream>
using namespace std;

void getArrays1(int*& arr, int& n)
{
	arr = new int[] { 5, 2, 4, 6, 1, 3 };
	//arr = new int[] { 6, 5, 4, 3, 2, 1 };
	//arr = new int[] { 4, 3, 2, 1 };
	//arr = new int[] { 1, 2, 3, 4 };
	n = 6;
}

void readArray(int*& arr, int& n)
{
	cout << "\nInput new Array" << endl;
	do {
		cout << "n = ";
		cin >> n;
	} while (n < 1);

	//
	cout << "Input Array with n = " << n << endl;
	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "array[" << i << "] = ";
		cin >> arr[i];
	}
}

void deleteArray(int* arr)
{
	delete[] arr;
}

void printArray(int* arr, int n, const char* message)
{
	cout << "\nArray " << message << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t ";
	}
	cout << endl;
}

void sortByInsert(int* arr, int n)
{
	int j = 0;
	int current = 0;
	//cout << endl;
	for (int i = 1; i < n; i++)
	{
		current = arr[i];
		j = i - 1;
		for (j = i - 1; (current > arr[j]) && (j >= 0); j--)
		{
			arr[j + 1] = arr[j];
			//cout << ".";
		}
		arr[j + 1] = current;
	}
	//cout << endl;
}

void sortByBubble(int* arr, int n)
{
	int temp;
	bool isSorted = false;
	cout << endl;
	for (int i = 0; !isSorted && (i < n - 1); i++)
	{
		isSorted = true;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				isSorted = false;
				cout << ".";
			}
		}
		cout << "|";
	}
	cout << endl;
}

void sortByMax(int* arr, int n)
{
	int imax = 0;
	int max = 0;
	for (int i = 0; i < n - 1; i++)
	{
		imax = 0;
		max = arr[imax];
		for (int j = 0; j < n - i; j++)
		{
			if (max < arr[j])
			{
				imax = j;
				max = arr[imax];
			}
		}
		arr[imax] = arr[n - i - 1];
		arr[n - i - 1] = max;
	}
}

int main()
{
	int* arr = NULL;
	int n = 0;
	//
	getArrays1(arr, n);
	//readArray(arr, n);
	//
	printArray(arr, n, "Original");
	//sortByInsert(arr, n);
	//sortByBubble(arr, n);
	sortByMax(arr, n);
	printArray(arr, n, "Sorted");
	//
	deleteArray(arr);
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
