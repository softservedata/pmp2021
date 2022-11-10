#include<iostream>
using namespace std;

class A1
{
public:
	int i; // Non virtual

	A1(int i = 1011)
	{
		cout << "A1() constructor" << endl;
		//i=101;
		this->i = i;
	}

	virtual ~A1()
	{
		cout << "A1() destructor" << endl;
		//system("pause");
	}

	int getI()
	{
		return i;
	}
};

class B1 : virtual public A1
//class B1 : public A1
{
public:
	//double i;

	B1():A1(102)
	{
		cout << "B1() constructor" << endl;
		//i = 1.1;
	}

	~B1()
	{
		cout << "B1() destructor" << endl;
		cout << "\ti = " << i << endl;
		//system("pause");
	}
};

class D1 : virtual public A1
//class D1 : public A1
{
public:

	D1() :A1(202) // Architecture ERROR
	{
		cout << "D1() constructor" << endl;
		//i = 1.1;
	}

	~D1()
	{
		cout << "D1() destructor" << endl;
		cout << "\ti = " << i << endl;
		system("pause");
	}
};


class C1 : public D1, public B1
{
public:

	C1()//:A1(101)
	{
		cout << "C1() constructor" << endl;
		//i = 1.1;
	}

	~C1()
	{
		cout << "C1() destructor" << endl;
		//cout << "\ti = " << i << endl;
		system("pause");
	}
};

int main05()
{
	cout << "start" << endl;
	//
	//B1 b;
	//cout << "b.i = " << b.i << endl; // Run destructor B, A
	//
	//A1* b = new B1();
	//A1* b = new C1(); // Run destructor C1, D1, B1, A1
	B1* b = new C1(); // Run destructor C1, D1, B1, A1
	//A1* b = new D1(); // Run destructor D1, A1
	// 
	cout << "b->i = " << b->i << endl;
	//
	delete b;
	//
	cout << "done" << endl;
	system("pause");
	return 0;
}
