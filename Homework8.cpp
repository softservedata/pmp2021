// Homework8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


const int coef = 10000;
void reading(float*& arr, int n)
{
	arr = new float[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

unsigned long int  getMax(unsigned long int* arr, int n)
{
	unsigned long int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}

unsigned long int getMin(unsigned long int* arr, int n)
{
	unsigned long int min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
	}
	return min;
}

void mult(float* arr, int n, unsigned long int*& arrm)
{
	
	for (int i = 0; i < n; i++)
	{
		arrm[i] = arr[i] * coef;
	}
}

unsigned long int getRange(unsigned long int* arr, int n)
{
	return getMax(arr, n) - getMin(arr, n) + 1; // 0 and last element
}

unsigned long int getMaxTwo(int arg0, int arg1)
{
	return arg0 > arg1 ? arg0 : arg1;
}

unsigned long int getMinTwo(unsigned long int arg0, unsigned long int arg1)
{
	return arg0 < arg1 ? arg0 : arg1;
}

unsigned long int getDelta(unsigned long int arg0, unsigned long int arg1)
{
	return getMinTwo(arg0, arg1);
}


unsigned long int hashCode(unsigned long int arg, unsigned long int delta)
{
	return arg - delta;
}

bool isEqual(unsigned long int* hash1, unsigned long int* hash2, int n)
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
	//Hardcode
	int n1 = 5;
	int n2 = 6;
	float* arr1 = new float[] { 21.3,42.567,21.3,26.5,42.567 };
	float* arr2 = new float[] { 26.5,42.567,21.3,26.5, 21.3,26.5}; //our two given arrays 
	

	/*
	//Input variant 
	int n1;
	cout << "n1 = ";
	cin >> n1;

	float* arr1;

	cout << "Input float type numbers of the first array:" << endl;
	reading(arr1, n1);
	//
	int n2;
	cout << "n2 = ";
	cin >> n2;
	
	float* arr2;
	
	cout << "Input float type numbers of the second array:" << endl;
	reading(arr2, n2);
	*/
	//

	unsigned long int* arr1i = new unsigned long int[n1];
	unsigned long int* arr2i = new unsigned long int[n2];
	//
	mult(arr1, n1, arr1i);
	mult(arr2, n2, arr2i);
	//
	int delta = getDelta(getMin(arr1i, n1), getMin(arr2i, n2));
	int n = getMaxTwo(getRange(arr1i, n1), getRange(arr2i, n2));
	unsigned long int* hash1 = new unsigned long int[n];
	unsigned long int* hash2 = new unsigned long int[n]; //addtional arrays 
	//
	for (int  i = 0; i < n; i++)
	{
		hash1[i] = 0;
		hash2[i] = 0;
	}
	//
	for (int i = 0; i < n1; i++)
	{
		hash1[hashCode(arr1i[i], delta)] = arr1i[i];
	}
	//
	for (int i = 0; i < n2; i++)
	{
		hash2[hashCode(arr2i[i], delta)] = arr2i[i];
	}
	//

	cout << "isEqual = " << (isEqual(hash1, hash2, n) ? "true" : "false") << endl;
	return 0;
}
