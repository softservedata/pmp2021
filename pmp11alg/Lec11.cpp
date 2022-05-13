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
	cout << message << "  Node01:" << endl;
	while (x != NULL)
	{
		cout << "address = " << x << "  value = " << x->i << endl;
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
//int main()
{
	/*
	int* k = new int;
	int* l = k;
	*k = 12;
	cout << "k = " << k << "  *k = " << *k << endl;
	cout << "l = " << l << "  *l = " << *l << endl;
	delete k;
	cout << "after delete  l = " << l << "  *l = " << *l << endl;
	//delete l; // Error
	*/
	//
	// f();
	//
	// /*
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
	// 1.
	//b = a;
	//printNode01(a, "after b=a; a");
	//printNode01(b, "after b=a; b");
	//
	// 2.
	//*b = *a;
	//printNode01(a, "after *b=*a; a");
	//printNode01(b, "after *b=*a; b");
	// 3.
	//b->i = a->i;
	//printNode01(a, "after b->i = a->i;; a");
	//printNode01(b, "after b->i = a->i; b");
	//
	// 4.
	b->l = a->l;
	printNode01(a, "after b->l = a->l;; a");
	printNode01(b, "after b->l = a->l;; b");
	//
	deleteNode01(a);
	//deleteNode01(b);
	//
	//*/
	//
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
