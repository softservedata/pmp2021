#include<iostream>
using namespace std;

void getArr1(int*& arr, int& n)
{
	arr = new int[] { 5, 2, 4, 6, 1, 3 };
	//arr = new int[] { 6, 5, 4, 3, 2, 1 };
	//arr = new int[] { 7, 6, 5, 4, 3, 2, 1 };
	//arr = new int[] { 4, 3, 2, 1 };
	//arr = new int[] { 1, 2, 3, 4 };
	n = 6;
}

void readArr(int*& arr, int& n)
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

void deleteArr(int* arr)
{
	delete[] arr;
}

void printArr(int* arr, int n, const char* message)
{
	cout << "\nArray " << message << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t ";
	}
	cout << endl;
}

void merge(int* arr, int p, int q, int r)
{
	int n = r - p + 1;
	int* arrtemp = new int[n];
	//
	int ip = p;
	int iq = q + 1;
	int current = 0;
	//
	for (int i = 0; i < n; i++)
	{
		if ((ip <= q) && (iq <= r))
		{
			if (arr[ip] < arr[iq])
			{
				current = arr[ip];
				ip++;
			}
			else
			{
				current = arr[iq];
				iq++;
			}
		}
		else if (ip <= q)
		{
			current = arr[ip];
			ip++;
		}
		else
		{
			current = arr[iq];
			iq++;
		}
		//
		arrtemp[i] = current;	 // O(n)
	}
	//
	for (int i = 0; i < n; i++)
	{
		arr[p + i] = arrtemp[i]; // O(n)
	}
	//
	delete[] arrtemp;
}

// Overload
void sortByMerge(int* arr, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		//cout << "start index p = " << p << "  midle index q = " << q << "  last index = " << r << endl;
		sortByMerge(arr, p, q);
		sortByMerge(arr, q + 1, r);
		//
		merge(arr, p, q, r);
	}
	//else
	//{
	//	cout << "\tstart index p = " << p << "  last index = " << r << "  element = " << arr[p] << endl;
	//}
}

// Overload
void sortByMerge(int* arr, int n)
{
	cout << "\t\tsorting ..." << endl;
	sortByMerge(arr, 0, n - 1);
	cout << "\t\tsorted done" << endl;
}

int main()
{
	int* arr = NULL;
	int n = 0;
	//
	getArr1(arr, n);
	//readArr(arr, n);
	//
	printArr(arr, n, "Original");
	sortByMerge(arr, n);
	printArr(arr, n, "Sorted");
	//
	deleteArr(arr);
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
