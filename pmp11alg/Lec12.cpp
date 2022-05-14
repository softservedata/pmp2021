#include<iostream>
using namespace std;

struct TNode2
{
	int i;
	TNode2* l;
	TNode2* r;
};

struct ArrNode
{
	int* arr;
	int i;
	int n;
};

void treeAdd(TNode2*& tree, int element)
{
	TNode2* test = tree;
	//
	TNode2* temp = new TNode2();
	temp->i = element;
	temp->l = NULL;
	temp->r = NULL;
	//
	if (tree == NULL)
	{
		tree = temp;
	}
	else
	{
		while (test != NULL)
		{
			if (element > test->i)
			{
				if (test->r == NULL)
				{
					test->r = temp;
					test = test->r;
				}
				test = test->r;
			}
			else
			{
				if (test->l == NULL)
				{
					test->l = temp;
					test = test->l;
				}
				test = test->l;
			}
		}
	}
}

void treeAddArr(TNode2*& tree, int* elements, int n)
{
	for (int i = 0; i < n; i++)
	{
		treeAdd(tree, elements[i]);
	}
}

void treePrint(TNode2* tree, const char* message)
{
	cout << message;
	if (tree != NULL)
	{
		treePrint(tree->l, "");
		cout << "  " << tree->i; // TODO Use array
		treePrint(tree->r, "");
	}
}

bool arrNodeAddElement(ArrNode* arrNode, int element)
{
	bool isAdd = arrNode->i < arrNode->n;
	if (isAdd)
	{
		arrNode->arr[arrNode->i] = element;
		arrNode->i++;
	}
	return isAdd;
}

void treeReview(TNode2* tree, ArrNode* arrNode)
{
	if (tree != NULL)
	{
		treeReview(tree->l, arrNode);
		arrNodeAddElement(arrNode, tree->i); // TODO get bool result
		treeReview(tree->r, arrNode);
	}
}

void treeDelete(TNode2* tree)
{
	if (tree != NULL)
	{
		treeDelete(tree->l);
		treeDelete(tree->r);
		delete tree;
	}
}

void arrPrint(int* arr, int n, const char* message)
{
	cout << message;
	for (int i = 0; i < n; i++)
	{
		cout << "  " << arr[i];
	}
	cout << endl;
}

void arrNodeCreate(ArrNode*& arrNode, int n)
{
	arrNode = new ArrNode();
	arrNode->arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arrNode->arr[i] = 0;
	}
	arrNode->i = 0;
	arrNode->n = n;
}

void arrNodePrint(ArrNode* arrNode, const char* message)
{
	int count = arrNode->i < arrNode->n ? arrNode->i : arrNode->n;
	arrPrint(arrNode->arr, count, message);
}

void arrNodeDelete(ArrNode* arrNode)
{
	delete arrNode->arr;
	delete arrNode;
}

int main()
{
	int n = 10;
	int* arr = new int[] { 10, 5, 15, 3, 8, 12, 18, 9, 7, 13 };
	TNode2* tree = NULL;
	ArrNode* arrResult = NULL;
	//
	arrPrint(arr, n, "Original Array:");
	treeAddArr(tree, arr, n);
	treePrint(tree, "Tree = ");
	//
	arrNodeCreate(arrResult, n);
	treeReview(tree, arrResult);
	arrNodePrint(arrResult, "\narrResult =");
	arrNodeDelete(arrResult);
	//
	treeDelete(tree);
	delete[] arr;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}