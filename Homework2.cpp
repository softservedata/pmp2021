#include<iostream>
using namespace std;


int main()
{
	int year;
	cout << "year - ";
	cin >> year;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		cout << "This year is leap" << endl;
	}
	else
	{
		cout << "This year isn't leap" << endl;
	}

	return 0;
}