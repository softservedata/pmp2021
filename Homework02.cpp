#include<iostream>
using namespace std;

int main()
{
	int y;
	cout << "Enter year:";
	cin >> y;

	if (!(y % 4 && y%100) || !(y % 400))
		cout << "The year is high";
	else
		cout << "The year is  not high";
}