#include<iostream>
#include<cmath>
using namespace std;
int main01 ()
{
	//за допомогою додаткової змінної
	/*int a, b, x;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	x = a;
	a = b;
	b = x;
	cout << "a=" << a << ", " << "b=" << b << endl;*/

	//за допомогою операцій додавання, віднімання
	/*int a, b;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	a = a + b;
	b = a - b;
	a = a - b;
	cout << "a=" << a << ", " << "b=" << b << endl;*/

	//за допомогою операцій множенняя, ділення
	/*int a, b;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	a = a * b;
	b = a / b;
	a = a / b;
	cout << "a=" << a << ", " << "b=" << b << endl;*/

	//за допомогою кон'юнкції, диз'юнкції
	/*int a, b, x;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	x = a;
	a = b & (a | b); 
	b = x & (b | x); 
	cout << "a=" << a << ", " << "b=" << b << endl;*/

	//за допомогою операції зсуву
	/*int a, b, x;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	x = (a << 32) | b;
	b = a >> 32; //ok 
	a = (x << 32) >> 32;
	cout << "a=" << a << ", " << "b=" << b << endl;*/

	//за допомогою операції додавання по модулю 2
	/*int a, b;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	a = a xor b;
	b = b xor a;
	a = a xor b;
	cout << "a=" << a << ", " << "b=" << b << endl;*/

	//три числа в порядку зростання
	/*int a, b, c;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;
	if ((a > b) && (b > c))
		cout << "Answer: " << c << b << a << endl;
	else if ((b > a) && (a > c))
		cout << "Answer: " << c << a << b << endl;
	else if ((c > b) && (b > a))
		cout << "Answer: " << a << b << c << endl;
	else if ((b > c) && (c > a))
		cout << "Answer: " << a << c << b << endl;
	else if ((a > c) && (c > b))
		cout << "Answer: " << b << c << a << endl;
	else if ((c > a) && (a > b))
		cout << "Answer: " << b << a << c << endl;*/

	system("pause");
	return 0;

}