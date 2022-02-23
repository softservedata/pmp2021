#include<iostream>
using namespace std;

int main() {
	int year;
	cout << "Enter year " << endl;
	cin >> year;
	if (!(year % 4)) {
		if ((year % 100 != 0) || (year % 100 == 0 && year % 400 == 0)) {
			cout << "this year is leap" << endl;
		}
	}
	else
		cout << "this year isn't leap" << endl;
}