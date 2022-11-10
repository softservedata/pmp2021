#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool Low(double a, double b)
{
	return a < b;
}

//struct MyFunctor {
class MyFunctor {
public:
    bool operator()(int a, int b)
    {
        return b < a;
    }
	~MyFunctor()
	{
		cout << "\tdestructor MyFunctor()" << endl;
	}
};


int main06()
{
	//
	vector<double> v;
	int n;
	double d;
	cout << "n=";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "v[" << i << "]=";
		cin >> d;
		v.push_back(d);
	}
	for (int i = 0; (unsigned)i < v.size(); i++)
	{
		cout << " " << v[i];
	}
	cout << endl;
	//
	//sort(v.begin(), v.end(), Low);
	// 
	//MyFunctor customLess;
	//sort(v.begin(), v.end(), customLess);
	//
	sort(v.begin(), v.end(), [](double a, double b) { return b < a; });
	//
	cout << "----------------" << endl;
	for (int i = 0; (unsigned)i < v.size(); i++)
	{
		cout << " " << v[i];
	}
	cout << endl;
	system("pause");
	//
	cout << "done" << endl;
	system("pause");
	return 0;
}
