#include <iostream>
using namespace std;

//Засобами C++ написати код для зміни контенту двох змінних за допомогою підходів
// A) Використовуючи додаткову змінну;
// B) Використовуючи операції додавання та віднімання;
// C) Використовуючи операції множення та ділення;
// D) Використовуючи операції кон’юнкції та диз’юнкції;
// E) Використовуючи операції зсуву;
// F) Використовуючи операцію додавання по модулю 2.

int main01()
{
	int a, b, c;

	cout << "Please,enter a value : ";
	cin >> a;

	cout << "Please,enter b value : ";
	cin >> b;


	/* 
	
	// A

	c=a;
	a=b;
	b=c;

	*/

	/* 
	
	// B

	a+=b;
	b=a-b;
	a-=b;

	*/

	/* 
	
	// C

	a*=b;
	b=a/b;
	a/=b;
	
	*/

	/*

	// D

    a = (a & ~b) | (~a & b);
    b = (a & ~b) | (~a & b);
    a = (a & ~b) | (~a & b);
    cout << "\n conjunction/disjunction : " << a << " " << b;

	*/

	/*
	
	// F
	
    a = 2, b = 3;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "Result is: " << a << " " << b;
    return 0;
	
	
	*/

	return 0;

}