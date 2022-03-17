#include<iostream>
using namespace std;

void print(int* arr, int n)
//void print(int arr[], int n)
//void print(int arr[4], int n)
{
	cout << "Array:";
	for (int i = 0; i < n; i++)
	{
		cout << "  " << arr[i];
	}
}

void print2(int arr[4][4], int n)
//void print2(int* arr, int n)
{
	cout << "Array:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "  ";
			//cout << *(arr + i * n + j) << "  ";
		}
		cout << endl;
	}
}

void print3(int** arr, int n)
{
	cout << "Array:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//cout << arr[i][j] << "  ";
			cout << *(*(arr + i) + j) << "  ";
		}
		cout << endl;
	}
}

void printMax(int** arr, int n)
{
	int max = arr[0][0];
	int min = arr[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (max < arr[i][j])
			{
				max = arr[i][j];
			}
			if (min > arr[i][j])
			{
				min = arr[i][j];
			}
		}
	}
	cout << "max = " << max << "  min = " << min;
}

struct CMax
{
	int max;
	int i;
	int j;
};

//int getMax(int** arr, int n)
CMax getMax(int** arr, int n)
{
	CMax cmax;
	cmax.max = arr[0][0];
	cmax.i = 0;
	cmax.j = 0;
	//int max = arr[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (cmax.max < arr[i][j])
			{
				cmax.max = arr[i][j];
				cmax.i = i;
				cmax.j = j;
			}
		}
	}
	//return max;
	return cmax;
}


int main()
{
	// One Dimension
	// Stack
	//int arr[5];
	//arr[0] = 4;
	//arr[1] = 6;
	//arr[2] = 8;
	//arr[3] = 10;
	//arr[4] = 11;
	//
	// Heap
	//int* arr = new int[] { 4, 6, 8, 10 };
	// 
	// Two Dimension
	// Stack
	//int arr[4][4];
	//arr[0][0] = 1;
	//arr[0][1] = 2;
	//arr[0][2] = 3;
	//arr[0][3] = 4;
	//arr[1][0] = 5;
	//arr[1][1] = 6;
	//arr[1][2] = 7;
	//arr[1][3] = 8;
	//arr[2][0] = 9;
	//arr[2][1] = 10;
	//arr[2][2] = 11;
	//arr[2][3] = 12;
	//arr[3][0] = 13;
	//arr[3][1] = 14;
	//arr[3][2] = 15;
	//arr[3][3] = 16;
	//
	// Heap
	// 
	/*
	int** arr;
	arr = new int* [4];
	arr[0] = new int[4];
	arr[1] = new int[4];
	arr[2] = new int[4];
	arr[3] = new int[4];
	//
	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 3;
	arr[0][3] = 4;
	arr[1][0] = 5;
	arr[1][1] = 6;
	arr[1][2] = 7;
	arr[1][3] = 8;
	arr[2][0] = 9;
	arr[2][1] = 10;
	arr[2][2] = 11;
	arr[2][3] = 12;
	arr[3][0] = 13;
	arr[3][1] = 14;
	arr[3][2] = 15;
	arr[3][3] = 16;
	*/
	int** arr = new int*[] { new int[] {4, 9, 8, 10}, new int[] {4, 1, 8, 12}, new int[] {4, 6, 3, 11}, new int[] {4, 5, 8, 10} };
	//
	//print((int*)arr, 16);
	//print2(arr, 4);
	//print2((int*)arr, 4)
	print3(arr, 4);
	//
	//printMax(arr, 4);
	//cout << "max = " << getMax(arr, 4);
	CMax cmax = getMax(arr, 4);
	cout << "max is arr[" << (cmax.i + 1) << "][" << (cmax.j + 1) << "] = " << cmax.max;
	//
	cout << "\ndone" << endl;
	system("pause");
	//
	for (int i = 0; i < 4; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}
