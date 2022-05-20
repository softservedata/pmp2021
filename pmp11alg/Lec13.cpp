#include<iostream>
using namespace std;

// - - - - - - - - - - Stack - - - - - - - - - -

#define Item int

struct SNode1
{
	Item data;
	SNode1* link;
};


void itemStackDelete(SNode1*& stack)
{
	SNode1* stemp = NULL;
	while (stack != NULL)
	{
		stemp = stack;
		stack = stack->link;
		delete stemp;
	}
}

// Initialization new Stack
void itemStackCreate(SNode1*& stack)
{
	itemStackDelete(stack);
	stack = NULL;
}

void itemStackPush(SNode1*& stack, Item item)
{
	SNode1* stemp = new SNode1();
	stemp->data = item;
	stemp->link = stack;
	stack = stemp;
}

void itemStackPushs(SNode1*& stack, Item* item, int n)
{
	for (int i = 0; i < n; i++)
	{
		itemStackPush(stack, item[i]);
	}
}

bool itemStackIsEmpty(SNode1* stack)
{
	return stack == NULL;
}

Item itemStackPop(SNode1*& stack, bool* result = NULL)
{
	Item item = NULL;
	bool status = !itemStackIsEmpty(stack);
	//
	if (result == NULL)
	{
		result = &status;
	}
	else
	{
		*result = status;
	}
	if (*result)
	{
		SNode1* stemp = stack;
		item = stack->data;
		stack = stack->link;
		delete stemp;
	}
	return item;
}

void itemStackPrint(SNode1* stack, const char* Message)
{
	cout << "\nStack: " << Message << endl;
	//
	SNode1* stemp = stack;
	while (stemp != NULL)
	{
		cout << stemp->data << "  ";
		stemp = stemp->link;
	}
	cout << endl;
}


int main13al()
//int main()
{
	int n = 10;
	int* arr = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	SNode1* stack = NULL;
	//
	itemStackCreate(stack);
	//
	itemStackPushs(stack, arr, n);
	itemStackPrint(stack, "After Add of Elements");
	//
	cout << "\nelements = ";
	while (!itemStackIsEmpty(stack))
	{
		cout << "  " << itemStackPop(stack);
	}
	cout << endl;
	//
	itemStackPrint(stack, "Before Delete");
	itemStackDelete(stack);
	delete[] arr;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
