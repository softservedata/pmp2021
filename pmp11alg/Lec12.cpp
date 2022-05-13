#include<iostream>
using namespace std;

struct TNode2
{
	int i;
	TNode2* l;
	TNode2* r;
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

void treeDelete(TNode2* tree)
{
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

int main()
{
	int n = 10;
	int* arr = new int[] { 10, 5, 15, 3, 8, 12, 18, 9, 7, 13 };
	TNode2* tree = NULL;
	//
	arrPrint(arr, n, "Original Array:");
	treeAddArr(tree, arr, n);
	treePrint(tree, "Tree = ");
	//
	treeDelete(tree);
	delete[] arr;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}