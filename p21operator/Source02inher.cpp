#include <iostream>
using namespace std;


class Acls
{
private:
	int i = 1;
public:
	//Acls()
	//{
	//	cout << "\tconstructor Acls()" << endl;
	//}

	Acls(int i = 111)
	//A(int i)
	{
		this->i = i;
		cout << "\tconstructor Acls(int i)" << endl;
	}

	Acls(const Acls& other)
	{
		i = other.i;
		//
		cout << "\tconstructor Acls(const Acls& other)" << endl;
	}

	//~Acls()
	virtual ~Acls()
	{
		cout << "\tdestructor Acls()" << endl;
	}

	int getI()
	{
		return i;
	}

	virtual void m1()
	//void m1()
	{
		cout << "m1() from Acls" << endl;
	}
};

class Bcls : public Acls
{
public:
	int j = 2;

	Bcls(int i = 11, int j = 22) : Acls(i)
	{
		this->j = j;
		cout << "\tconstructor Bcls(int i, int j):A(i)" << endl;
	}

	Bcls(const Bcls& other) : Acls(other)
	{
		j = other.j;
		//
		cout << "\tconstructor Bcls(const Bcls& other)" << endl;
	}

	~Bcls()
	{
		cout << "\tdestructor Bcls()" << endl;
	}

	void m1()
	{
		cout << "m1() from Bcls" << endl;
	}
};


int main02()
{
	/*
	int k = 1;
	double d = 2.5;
	cout << "k = " << k << endl;
	cout << "d = " << d << endl;
	//
	//d = k;
	k = d;
	cout << "updated k = " << k << endl;
	cout << "updated d = " << d << endl;
	*/
	//
	/* in stack
	Bcls b0(5,6);
	Acls a0 = b0;
	cout << "a0.getI() = " << a0.getI() << endl;
	cout << "b0.getI() = " << b0.getI() << endl;
	a0.m1();
	b0.m1();
	*/
	//
	// /*
	// in heap
	//Bcls* b0 = new Bcls(5,6);
	Acls* b0 = new Bcls(5,6);
	//Acls* b0 = new Acls(5);
	cout << "b0.getI() = " << b0->getI() << endl;
	b0->m1();
	//
	cout << "typeid(b0) = " << typeid(b0).name() << endl;
	if (typeid(Bcls) == typeid(*b0))
	{
		Bcls* b1 = (Bcls*)b0; // Code Small;
		cout << "b1.j = " << b1->j << endl;
	}
	delete b0;
	// */
	cout << "done" << endl;
	system("pause");
	return 0;
}
