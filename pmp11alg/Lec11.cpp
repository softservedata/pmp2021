#include<iostream>
using namespace std;

//#define PNode Node* // void*

struct Node01
{
	int i;
	Node01* l;
	//PNode l;
	//
};

void printNode01(Node01* x, const char* message)
{
	cout << message << "  Node01:";
	while (x != NULL)
	{
		cout << "  value = " << x->i;
		x = x->l;
	}
	cout << endl;
}

void deleteNode01(Node01*& x)
{
	Node01* t;
	while (x != NULL)
	{
		t = x;
		x = x->l;
		delete t;
	}
}


//void f()
//{
//	cout << "\nf()" << endl;
//}

//void f();

int main11al()
{
	Node01* a = NULL;
	Node01* b = NULL;
	//
	a = new Node01();
	a->i = 1;
	a->l = new Node01();
	a->l->i = 2;
	a->l->l = NULL;
	b = new Node01();
	b->i = 3;
	b->l = NULL;
	//
	printNode01(a, "start a");
	printNode01(b, "start b");
	//
	//b = a;
	//printNode01(a, "after b=a; a");
	//printNode01(b, "after b=a; b");
	//
	*b = *a;
	printNode01(a, "after *b=*a; a");
	printNode01(b, "after *b=*a; b");
	// 
	deleteNode01(a);
	//deleteNode01(b);
	//
	//f();
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}

/*
void f()
{
	cout << "\nf()" << endl;
}
*/
