#include<iostream>
using namespace std;

int main08a()
{
	bool isEqual = true;
	bool check = false;
	int n1 = 8;
	int n2 = 5;
	int* arr1 = new int[] { 1, 8, 2, 1, 4, 8, 1, 2 };
	int* arr2 = new int[] { 1, 2, 4, 8, -1 };
	//
	for (int i = 0; isEqual && (i < n1); i++)
	{
		check = false;
		for (int j = 0; j < n2; j++)
		{
			if (arr1[i] == arr2[j])
			{
				check = true;
				break;
			}
		}
		isEqual = check;
	}
	//
	for (int i = 0; isEqual && (i < n2); i++)
	{
		check = false;
		for (int j = 0; j < n1; j++)
		{
			if (arr2[i] == arr1[j])
			{
				check = true;
				break;
			}
		}
		isEqual = check;
	}
	//
	cout << "isEqual = " << (isEqual ? "true" : "false") << endl;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
