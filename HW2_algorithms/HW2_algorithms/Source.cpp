#include<iostream>
using namespace std;
int main()
{
	int n;
	cout << "Enter year ";
	cin >> n;
	if ((n % 400 == 0) || (n % 4 == 0) && (n % 100 != 0))
		cout << "Year is visokosniy" << endl;
	else cout << "Year isn`t visokosniy" << endl;
	system("pause");
	return 0;
}