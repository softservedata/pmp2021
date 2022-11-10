#include<iostream>
#include<list>
#include<algorithm>
#include<fstream>
using namespace std;

int main07()
{
	int k, k1;
	//
	cout << "start" << endl;
	//
	ifstream fin;
	fin.open("input.txt");
	//
	list<int> a;
	list<int>::iterator i;
	//
	cout << "\nRead Data ...";
	while (!fin.eof())
	{
		fin >> k;
		cout << " " << k;
		a.push_back(k);
	}
	cout << endl;
	fin.close();
	//
	cout << "\nOrigin List:\n";
	for (i = a.begin(); i != a.end(); i++)
	{
		cout << (*i) << "  ";
	}
	cout << endl;
	//
	// Replace Elements
	cout << "Exist Number, k=";
	cin >> k;
	cout << "New Number, k1=";
	cin >> k1;
	//replace(a.begin(), a.end(), k, k1);
	replace_if(a.begin(), a.end(), [](int a) { return a > 4; }, k1);
	//
	cout << "\nNew List:" << endl;
	for (i = a.begin(); i != a.end(); i++)
	{
		cout << (*i) << "  ";
	}
	cout << endl;
	//
	cout << "done" << endl;
	system("pause");
	return 0;
}
