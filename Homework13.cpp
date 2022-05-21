#include <iostream>
#include <string.h>
using namespace std;

#define Element int

struct ArrayStack
{
	Element* data;
	int n;
	int sp;
};

void arrStackCreate(ArrayStack*& stack, int n)
{
	stack = new ArrayStack();
	stack->data = new int[n];
	stack->n = n;
	stack->sp = -1;
	for (int i = 0; i < n; i++)
	{
		stack->data[i] = 0;
	}
}

bool arrStackPush(ArrayStack* stack, Element element)
{
	bool result = (stack->sp < stack->n - 1);
	if (result)
	{
		stack->sp++;
		stack->data[stack->sp] = element;
	}
	return result;
}

bool arrStackPushs(ArrayStack* stack, Element* element, int n)
{
	bool result = true;
	for (int i = 0; result && (i < n); i++)
	{
		result = arrStackPush(stack, element[i]);
	}
	if (!result)
	{
		cout << "ERROR: Stack Overflow" << endl;
	}
	return result;
}

bool arrStackIsEmpty(ArrayStack* stack)
{
	return (stack->sp < 0);
}

Element* arrStackPop(ArrayStack* stack, bool* result = NULL)
{
	Element* element = NULL;
	bool status = arrStackIsEmpty(stack);
	if (result == NULL)
	{
		result = &status;
	}
	else
	{
		*result = status;
	}
	if (!*result)
	{
		element = &stack->data[stack->sp];
		stack->sp--;
	}
	return element;
}

void arrStackDelete(ArrayStack* stack)
{
	delete[] stack->data;
	delete stack;
}

void arrStackPrint(ArrayStack* stack, const char* Message)
{
	cout << "\nStack: " << Message << endl;
	cout << "n = " << stack->n << endl;
	cout << "sp = " << stack->sp << endl;
	for (int i = 0; i <= stack->sp; i++)
	{
		cout << "element[" << i << "] = " << stack->data[i] << endl;
	}
}


int main()
{
	int n = 3;
	int nMaxSizeStack = 100;
	ArrayStack** stacks = new ArrayStack * [n];
	for (int i = 0; i < n; i++)
	{
		arrStackCreate(stacks[i], nMaxSizeStack);
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Input count element for adding in stack " << i << ":" << endl;
		int count = 0;
		cin >> count;
		for (int j = 0; j < count; j++)
		{
			cout << "Input element" << endl;
			int element;
			cin >> element;
			arrStackPush(stacks[i], element);
		}
	}
	for (int i = 0; i < n; i++)
	{
		arrStackPrint(stacks[i], " " + i);
	}

	ArrayStack* unionStack;
	arrStackCreate(unionStack, n * nMaxSizeStack);
	for (int i = 0; i < n; i++)
	{
		ArrayStack* help;
		arrStackCreate(help, nMaxSizeStack);
		while (!arrStackIsEmpty(stacks[i]))
		{
			int* el = arrStackPop(stacks[i]);
			arrStackPush(help, *el);
			arrStackPush(unionStack, *el);
		}

		while (!arrStackIsEmpty(help))
		{
			int* el = arrStackPop(help);
			arrStackPush(stacks[i], *el);
		}
	}

	arrStackPrint(unionStack, "Union");
	for (int i = 0; i < n; i++)
	{
		arrStackPrint(stacks[i], "Initialization");
	}

	return 0;
}

