#include<iostream>
using namespace std;

int main() {
	int n;
	cout << "n = ";
	cin >> n;
	cout << "a)" << endl;
	int k = 0;
	int s = 1;
	int l = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i; j++) {
			if (l > n)
				break;
			k += l;
			l++;
		}
		if (k == 0)
			break;
		s *= k;
		k = 0;
	}
	cout << "s = " << s << endl;
	cout << "b)" << endl;
	int p = 0;
	int r = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			r *= j;
		}
		p += r;
		r = 1;
	}
	cout << "p = " << p << endl;
	cout << "c)" << endl;
	int pr;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		pr = 1;
		for (int j = i; j <= (i * i); j++) {
			pr *= j;
		}
		sum += pr;
	}
	cout << "sum = " << sum << endl;
}