#include<iostream>
using namespace std;
int main1()
{
	int year;
	cout << "Please enter year";
	cin >> year;
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0) {
				cout << "intercalary year";
			}
			else
				cout << "simple year";
		}
		else
			cout << "intercalary year";
	}
	else
		cout << "simple year";

	system("pause>0");
	return 0;
}