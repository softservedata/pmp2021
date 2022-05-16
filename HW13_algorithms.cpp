#include<iostream>
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

int main013()
{
	int n = 10;
	ArrayStack* stack = NULL;
	//
	Element* elemArray = new Element[n]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//
	/*
	do {
		cout << "n = ";
		cin >> n;
	} while (n <= 0);
	*/
	arrStackCreate(stack, n);
	//
	arrStackPushs(stack, elemArray, n);
	arrStackPrint(stack, "After Add Array of Elements");
	//
	cout << "\nelements = ";
	while (!arrStackIsEmpty(stack))
	{
		cout << "  " << *arrStackPop(stack);
	}
	cout << endl;
	//
	arrStackPrint(stack, "Before Delete");
	arrStackDelete(stack);
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}