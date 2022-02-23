#include <iostream>
using namespace std;
int main()
{
	int year, result;
	cout << "enter year=";
	cin >> year;
	result = year / 100;
	result = year - result;
	result = result % 4;
	cout << result << endl;
	return 0;
}