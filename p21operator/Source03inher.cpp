#include <iostream>
using namespace std;

class A
{
public:
	int i;

	A(int i = 1011)
	{
		cout << "A() constructor" << endl;
		//i=101;
		this->i = i;
	}

	virtual ~A()
	{
		cout << "\tdestructor A()" << endl;
	}

	void m1()
	{
		cout << "A m1() i=" << i << endl;
	}

	virtual void m2()
	{
		cout << "A m2() i=" << i << endl;
	}

	void m3()
	{
		cout << "A m3() running m4()" << endl;
		cout << "\t";
		m4();
	}

	virtual void m4()
	{
		cout << "A m4()" << endl;
	}

	//void m5()
	virtual void m5()
	{
		cout << "A m5() i=" << i << endl;
		cout << "\tA m5() running m8()" << endl;
		cout << "\t";
		m8();
	}

	static void m6()
	{
		cout << "A m6() static" << endl;
	}

	//virtual void m7()=0;

	//virtual void m8()
	void m8()
	{
		cout << "A m8()" << endl;
	}

};


class B : public A
{
public:
	double i;

	B()//:A(101)
	{
		cout << "B() constructor" << endl;
		i = 1.1;
	}

	~B()
	{
		cout << "\tdestructor B()" << endl;
	}

	void m2()
	{
		cout << "B m2() i=" << i << endl;
	}


	void m4()
	{
		cout << "B m4()" << endl;
	}

	void m5()
	{
		cout << "B m5() i=" << i << endl;
		cout << "\tB m5() running m8()" << endl;
		cout << "\t";
		m8();
	}

	static void m6()
	{
		cout << "B m6() static" << endl;
	}

	void m7()
	{
		cout << "B m7()" << endl;
	}

private:

	void m8() // Architecture Error;
	{
		cout << "B m8()" << endl;
	}

};


int main03()
{
	cout << "start" << endl;
	//
	/*
	A* a = new A();
	cout << "a->i = " << a->i << endl;
	a->m1();
	a->m2();
	a->m3();
	a->m4();
	a->m5();
	a->m6(); // Bad solution
	A::m6(); // Best practics
	a->m8();
	delete a;
	*/
	// /*
	A* b = new B();
	cout << "b->i = " << b->i << endl; // Run from A; Architecture Error; Field i not virtual;
	b->m1();
	b->m2();
	b->m3();
	b->m4();
	b->m5(); // Run m8() from B if ...; Architecture Error;
	b->m6(); // from A
	A::m6();
	B::m6();
	//b->m7(); // Compile Error
	if (typeid(B) == typeid(*b))
	{
		((B*)b)->m7(); // Runtime Error if class A
		cout << "((B*)b)->i = " << ((B*)b)->i << endl;
	}
	b->m8(); // Run m8() from A; Architecture Error;
	delete b;
	// */
	
	// 
	//
	cout << "done" << endl;
	system("pause");
	return 0;
}