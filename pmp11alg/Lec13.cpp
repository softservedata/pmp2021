#include<iostream>
using namespace std;

// - - - - - - - - - - Stack - - - - - - - - - -

#define Item int

struct SNode1
{
	Item data;
	SNode1* link;
};


void itemStackDelete(SNode1* stack)
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
void itemStackCreate(SNode1*& stack, int n)
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

void itemStackPushs(SNode1* stack, Item* item, int n)
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

Item itemStackPop(SNode1* stack, bool* result = NULL)
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
	//cout << "\nStack: " << Message << endl;
	//cout << "n = " << stack->n << endl;
	//cout << "sp = " << stack->sp << endl;
	//for (int i = 0; i <= stack->sp; i++)
	//{
	//	cout << "element[" << i << "] = " << stack->data[i] << endl;
	//}
}


int main()
{
	//int n = 10;
	//int* arr = new int[] { 10, 5, 15, 3, 8, 12, 18, 9, 7, 13 };
	//TNode2* tree = NULL;
	//ArrNode* arrResult = NULL;
	////
	//arrPrint(arr, n, "Original Array:");
	//treeAddArr(tree, arr, n);
	//treePrint(tree, "Tree = ");
	////
	//arrNodeCreate(arrResult, n);
	//treeReview(tree, arrResult);
	//arrNodePrint(arrResult, "\narrResult =");
	//arrNodeDelete(arrResult);
	////
	//treeDelete(tree);
	//delete[] arr;

	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
