#include<iostream>
using namespace std;


struct TreeNode2
{
	int data;
	TreeNode2* left;
	TreeNode2* right;
};

struct StackNode1
{
	bool first;
	TreeNode2* item;
	StackNode1* link;
};

// * * * Stack * * *

void treeStackDelete(StackNode1*& stack)
{
	StackNode1* stemp = NULL;
	while (stack != NULL)
	{
		stemp = stack;
		stack = stack->link;
		delete stemp;
	}
}

void treeStackCreate(StackNode1*& stack)
{
	treeStackDelete(stack);
	stack = NULL;
}

void  treeStackPush(StackNode1*& stack, TreeNode2* item, bool first)
{
	StackNode1* stemp = new StackNode1();
	stemp->item = item;
	stemp->first = first;
	stemp->link = stack;
	stack = stemp;
}

bool  treeStackIsEmpty(StackNode1* stack)
{
	return stack == NULL;
}

TreeNode2* treeStackPop(StackNode1*& stack, bool& first, bool* result = NULL)
{
	TreeNode2* node = NULL;
	bool status = !treeStackIsEmpty(stack);
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
		StackNode1* stemp = stack;
		node = stack->item;
		first = stack->first;
		stack = stack->link;
		delete stemp;
	}
	return node;
}

// * * * Tree * * *

void treeNodeAdd(TreeNode2*& tree, int element)
{
	TreeNode2* test = tree;
	//
	TreeNode2* temp = new TreeNode2();
	temp->data = element;
	temp->left = NULL;
	temp->right = NULL;
	//
	if (tree == NULL)
	{
		tree = temp;
	}
	else
	{
		while (test != NULL)
		{
			if (element > test->data)
			{
				if (test->right == NULL)
				{
					test->right = temp;
					test = test->right;
				}
				test = test->right;
			}
			else
			{
				if (test->left == NULL)
				{
					test->left = temp;
					test = test->left;
				}
				test = test->left;
			}
		}
	}
}

void treeNodeAddArr(TreeNode2*& tree, int* elements, int n)
{
	for (int i = 0; i < n; i++)
	{
		treeNodeAdd(tree, elements[i]);
	}
}

void treeStackPrint(TreeNode2* tree, const char* message)
{
	bool first = false;
	TreeNode2* temp = NULL;
	StackNode1* stack = NULL;
	treeStackCreate(stack);
	//
	cout << message;
	treeStackPush(stack, tree, true);
	while (treeStackIsEmpty(stack))
	{
		temp = treeStackPop(stack, first);
		if (first)
		{
			treeStackPush(stack, temp, false);
			if (temp->left != NULL)
			{
				treeStackPush(stack, temp->left, true);
			}
		}
		else
		{
		}
	}
	
}


// TODO delete
void treeRecPrint(TreeNode2* tree, const char* message)
{
	cout << message;
	if (tree != NULL)
	{
		treeRecPrint(tree->left, "");
		cout << "  " << tree->data; // TODO Use array
		treeRecPrint(tree->right, "");
	}
}

// TODO delete
void treeRecDelete(TreeNode2* tree)
{
	if (tree != NULL)
	{
		treeRecDelete(tree->left);
		treeRecDelete(tree->right);
		delete tree;
	}
}

void arrNodePrint(int* arr, int n, const char* message)
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
	TreeNode2* tree = NULL;
	//
	arrNodePrint(arr, n, "Original Array:");
	treeNodeAddArr(tree, arr, n);
	treeRecPrint(tree, "Tree = ");
	//
	//
	treeRecDelete(tree);
	delete[] arr;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}