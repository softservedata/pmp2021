#include<iostream>
using namespace std;

int main01() {
	int a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "using temperory variable" << endl;
	int a1 = a, b1 = b, temp;
	temp = a1;
	a1 = b1;
	b1 = temp;
	cout << "a = " << a1 << endl << "b = " << b1 << endl;

	cout << "using + and -" << endl;
	int a2 = a, b2 = b;
	a2 = a2 + b2;
	b2 = a2 - b2;
	a2 = a2 - b2;
	cout << "a = " << a2 << endl << "b = " << b2 << endl;

	cout << "using * and /" << endl;
	int a3 = a, b3 = b;
	a3 = a3 * b3;    
	b3 = a3 / b3;    
	a3= a3 / b3;   
	cout << "a = " << a3 << endl << "b = " << b3 << endl;

	cout << "using & and |" << endl;
	int a4 = a, b4 = b;
	a4 = (a4 & b4) + (a4 | b4);
	b4 = a4 + (~b4) + 1;
	a4 = a4 + (~b4) + 1;
	cout << "a = " << a4 << endl << "b = " << b4 << endl;

	cout << "using shift" << endl;
	int a5 = a, b5 = b;
	for (int i = 0; i < 16; i++)
	{
		if ((a5 & (1 << i)) ^ (b5 & (1 << i)))
		{
			a5 = a5 ^ (1 << i);
			b5 = b5 ^ (1 << i);
		}
	}
	cout << "a = " << a5 << endl << "b = " << b5 << endl;

	cout << "using XOR" << endl;
	int a6 = a, b6 = b;
	a6 = a6 ^ b6, b6 = a6 ^ b6, a6= a6 ^ b6;
	cout << "a = " << a6 << endl << "b = " << b6 << endl;
	return 0;
}
