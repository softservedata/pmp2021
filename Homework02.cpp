#include <iostream>
using namespace std;

int main()
{
	int a;
	cout << "Enter year-";
	cin >> a;
	if (a % 4 == 0)
	{
		if (a % 100 == 0)
		{
			if (a % 400 == 0)
			{
				cout << "High year";
			}
			else
			{
				cout << "The year is not high";
			}
		}
		else
		{
			cout << "High year";
		}
	}
	else
	{
		cout << "The year is not high";
	}
}