#include <iostream>
using namespace std;


class A
{
private:
	int i = 1;
public:
	//A()
	//{
	//	cout << "\tconstructor A()" << endl;
	//}

	A(int i = 111)
	//A(int i)
	{
		this->i = i;
		cout << "\tconstructor A(int i)" << endl;
	}

	~A()
	//virtual ~A()
	{
		cout << "\tdestructor A()" << endl;
	}

	int getI()
	{
		return i;
	}

	//virtual void m1()
	void m1()
	{
		cout << "m1() from A" << endl;
	}
};

class B : public A
{
public:
	int j = 2;

	B(int i = 11, int j = 22) : A(i)
	{
		this->j = j;
		cout << "\tconstructor B(int i, int j):A(i)" << endl;
	}

	~B()
	{
		cout << "\tdestructor B()" << endl;
	}

	void m1()
	{
		cout << "m1() from B" << endl;
	}
};


int main()
{
	//
	/* in stack
	B b0(5,6);
	//A b0(6);
	cout << "b0.getI() = " << b0.getI() << endl;
	b0.m1();
	*/
	//
	// in heap
	B* b0 = new B(5,6);
	//A b0(6);
	cout << "b0.getI() = " << b0->getI() << endl;
	//b0->m1();
	delete b0;
	//
	cout << "done" << endl;
	system("pause");
}
