#include<iostream>
using namespace std;
int main()
{
	//s=1+(1*2)+(1*2*3)+...+(1*2*..n)
	double n;
	double s;
	int firstnum=1;
	int d=1;
	cout << "enter n: ";
	cin >> n;
	s = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			d *= j;
		}
		s += d;

	}
	cout << "sum = " << s;
	
	//s=1*(2+3)*(4+5+6)*…*(…+n)
	double n;
	cin >> n;
	int d = 1;
	int r = 0;
	for (int i = 1; r < n; ++i) {
		int s = 0;
		for (int j = 0; j < i && r < n; ++j) {
			s += ++r;
		}
		d *= s;
	}
	cout << "d = " << d << endl;

	

	system("pause>0");
	return 0;
}