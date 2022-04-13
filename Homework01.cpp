#include <iostream>
using namespace std;

int main()
{
	//a
	int a;
	int b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	int c = a;
	c = b;
	cout << "Додаткова змінна = " << c << endl;


	//b
	int k, l, n, m, f;
	cout << "k = ";
	cin >> k;
	cout << "l = ";
	cin >> l;
	n = k + l;
	m = k - l;
	f = l - k;
	cout << "n = " << n << " m =" << m << " f =" << f << endl;
	//c
	int u, p, mn, di, di_2;
	cout << "u = ";
	cin >> u;
	cout << "p = ";
	cin >> p;
	mn = u * p;
	di = u / p;
	di_2 = p / u;
	cout << "mn = " << mn << "di = " << di << "di_2 = " << di_2 << endl;
	//d
	int o, q;

	o = (o & ~q) | (~o & q);
	q = (o & ~q) | (~o & q);
	cout << "Кон'юнкція = " << o << "Диз'юнкція = " << q << endl;

	//e
	int a, b;
	int suv;
	int suv2;
	suv = a >> 2;
	suv2 = b >> 6;
	cout << "Zsuv = " << a << " " << b << endl;

	// f
	int m;

	j = (a + b) % 2 == (a + b) & 1 == (a ^ b) & 1;
	cout << "Sum of mod2 = " << m << endl;
	return 0;

}