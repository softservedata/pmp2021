#include <iostream>


using namespace std;

int main()
{
	int year;

	cout << "Enter year: ";
	cin >> year;

	if (!(year % 4) && year % 100)
	{
		cout << "This is leap year\n";
	}
	else if (!(year % 400))
	{
		cout << "This is leap year\n";
	}
	else
	{
		cout << "This is not leap year\n";
	}

	return 0;
}