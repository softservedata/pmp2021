#include<iostream>
#include<string>

using namespace std;

int myRead(string s)
{
	int value = 0;
	cout << s << " ";
	cin >> value;
	return value;
}

void myPrint(string s, int value)
{
	cout << s << " " << value;
}

int myMax(int a, int b)
{
	int max = a;
	if (max < b)
	{
		max = b;
	}
	return max;
}

int main03a()
{
	int a = myRead("a = ");
	int b = myRead("b = ");
	myPrint("max = ", myMax(a, b));
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
