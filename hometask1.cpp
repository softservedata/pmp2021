#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cout << "Enter a: " << "\n";
	cin >> a;
	cout << "Enter b: " << "\n";
	cin >> b;
	cout << "Enter c: " << "\n";
	cin >> c;
	cout << "Our numbers are: " << a << " " << b << " " << c << endl;


	if (b < a < c) {
		cout << "The order of growth: " << c << " " << a << " " << b << endl;
	}
	else if (b < c < a) {
		cout << "The order of growth: " << a << " " << c << " " << b << endl;
	}
	else if (a < b < c) {
		cout << "The order of growth: " << c << " " << b << " " << a << endl;
	}
	else if (c < a < b) {
		cout << "The order of growth: " << b << " " << a << " " << c << endl;
	}
	return 0;
}