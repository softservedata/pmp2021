#include<iostream>
#include<string>

using namespace std;

int main03b()
{
	int* arr = new int[] { 4, 6, 8, 10 };
	//
	int n = 4;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		//sum = sum + arr[i];
		sum = sum + *(arr + i);
	}
	cout << "sum = " << sum << endl;
	//
	cout << "\ndone02" << endl;
	delete[] arr;
	system("pause");
	return 0;
}
