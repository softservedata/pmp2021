#include <iostream>
using namespace std;

int* vvid(int a)
{

	int arr[1000]{};

	for (int i = 0; i < a; i++)
	{
		cout << "set[" << i << "]=";
		cin >> arr[i];
	}

	return arr;

}

void vuvid(int arr[], int a)
{
	for (int i = 0; i < a; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int amount(int a)
{
	return a;
}

void association(int arr_1[], int arr_2[],int n,int m)
{

	int arr[1000];
	bool check = true;
	int temp = 0;

	for (int i = 0; i < n; i++)
	{
		arr[i] = arr_1[i];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr_2[i] == arr_1[j])
			{
				check = false;
				break;
			}
			else
			{
				check = true;
			}
		}

		if (check==true)
		{
			arr[temp+n] = arr_2[i];
			temp++;
		}
		check = true;
	}

	for (int i = 0; i < temp+n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	
}

void crossing(int arr_1[], int arr_2[], int n, int m)
{

	int arr[1000];
	bool check = true;
	int temp = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			if (arr_1[i] == arr_2[j])
			{
				check = true;
				break;
			}
			else
			{
				check = false;
			}

		}

		if (check == true)
		{
			arr[temp] = arr_1[i];
			temp++;
		}
		check = true;
	}


	for (int i = 0; i < temp; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;


}

int main()
{
	int n, m;

	cout << "Enter the number of elements of the set first ";
	cin >> n;
	cout << "Enter the number of elements of the set second ";
	cin >> m;

	int arr_1[1000]{};
	cout << "set 1" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "set[" << i << "]=";
		cin >> arr_1[i];
	}

	int arr_2[1000]{};
	cout << "set 2" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << "set[" << i << "]=";
		cin >> arr_2[i];
	}

	cout << "Association set" << endl;
	association(arr_1, arr_2, n, m);

	cout << "Crossing set" << endl;
	crossing(arr_1, arr_2, n, m);

}