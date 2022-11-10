#include<iostream>
//#include<list>
#include <vector>
#include<algorithm>
#include<fstream>
using namespace std;

void printInt(int number)
{
	cout << "num = " << number << endl;
}

int main()
{
	vector<int> myVec;
	vector<int>::iterator i, first, last;
	//
	for (int i = 0; i < 10; i++)
	{
		myVec.push_back(i);
		//myVec[i] = i; // Create Error
	}
	myVec[1] = 10;
	//
	cout << "\nOrigin myVec:\n";
	for (i = myVec.begin(); i != myVec.end(); i++)
	{
		cout << (*i) << "  ";
	}
	cout << endl;
	//
	first = myVec.begin() + 2;
	last = myVec.begin() + 5;
	myVec.erase(first, last);
	for_each(myVec.begin(), myVec.end(), printInt);
	//
	cout << "done" << endl;
	system("pause");
	return 0;
}