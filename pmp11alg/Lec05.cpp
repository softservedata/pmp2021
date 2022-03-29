#include<iostream>
using namespace std;

void printArr1(int* arr, int n)
//void print(int arr[], int n)
//void print(int arr[4], int n)
{
	cout << "Array:";
	for (int i = 0; i < n; i++)
	{
		cout << "  " << arr[i];
	}
	cout << endl;
}

void printArr2(int** arr, int n)
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

int getMaxArr1(int* arr, int n)
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

int getMaxArr2(int** arr, int n)
{
	int max = arr[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (max < arr[i][j])
			{
				max = arr[i][j];
			}
		}
	}
	return max;
}

int main05al()
{
	/*
	// One Dimension
	// Stack
	//int arr[5];
	//
	// Heap
	int* arr = new int[5];
	arr[0] = 4;
	//arr[1] = 6;
	*(arr + 1) = 6;
	arr[2] = 12;
	arr[3] = 10;
	arr[4] = 11;
	//
	printArr1(arr, 5);
	cout << "max = " << getMaxArr1(arr, 5) << endl;
	*/
	/*
	// Two Dimension. Stack
	int arr[4][4];
	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 3;
	arr[0][3] = 4;
	arr[1][0] = 5;
	arr[1][1] = 6;
	arr[1][2] = 7;
	arr[1][3] = 18;
	arr[2][0] = 9;
	arr[2][1] = 10;
	arr[2][2] = 11;
	arr[2][3] = 12;
	arr[3][0] = 13;
	arr[3][1] = 14;
	arr[3][2] = 15;
	arr[3][3] = 16;
	//
	printArr1((int*)arr, 16);
	cout << "max = " << getMaxArr1((int*)arr, 16) << endl;
	*/
	// Two Dimension. Heap
	int** arr;
	arr = new int* [4];
	arr[0] = new int[4];
	arr[1] = new int[4];
	arr[2] = new int[4];
	arr[3] = new int[4];
	//
	arr[0][0] = 1;
	arr[0][1] = 20;
	arr[0][2] = 3;
	arr[0][3] = 4;
	arr[1][0] = 5;
	arr[1][1] = 6;
	arr[1][2] = 7;
	arr[1][3] = 18;
	arr[2][0] = 9;
	arr[2][1] = 10;
	arr[2][2] = 11;
	arr[2][3] = 12;
	arr[3][0] = 13;
	arr[3][1] = 14;
	arr[3][2] = 15;
	arr[3][3] = 16;
	//
	printArr2(arr, 4);
	cout << "max = " << getMaxArr2(arr, 4) << endl;
	//
	cout << "\ndone" << endl;
	system("pause");
	//delete[] arr; // One Dimension. Heap
	//
	// Two Dimension. Heap
	for (int i = 0; i < 4; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	//
	return 0;
}
