#include <iostream>
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
void arrPrintStack(ArrayStack* stack) {
	int size = stack->n;
	if (size == 0) {
		cout << "Stack is empty" << endl;
		return;
	}
	for (int i = 0; i < size; i++) {
		cout << stack->data[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n1 = 12, n2 = 10, n3 = n1 + n2;
	ArrayStack* stack1 = NULL;
	ArrayStack* stack2 = NULL;
	ArrayStack* stack3 = NULL;
	Element* elemArray1 = new Element[n1]{ 2, 2, 3, 4, 3, 6, 7, 1, 9, 10,66,101 };
	Element* elemArray2 = new Element[n2]{ 7, 2, 4, 4, 5, 6, 7, 8, 9, 10 };
	arrStackCreate(stack1, n1);
	arrStackCreate(stack2, n2);
	arrStackCreate(stack3, n3);
	arrStackPushs(stack1, elemArray1, n1);
	arrStackPushs(stack2, elemArray2, n2);
	arrStackPushs(stack3, elemArray1, n1);
	arrStackPushs(stack3, elemArray2, n2);
	//arrStackPrint(stack1, "After Add Array of Elements");
	cout << "stack 1 = ";
	arrPrintStack(stack1);
	cout << "stack 2 = ";
	arrPrintStack(stack2);
	cout << "stack 3 = ";
	while (!arrStackIsEmpty(stack3))
	{
		cout << *arrStackPop(stack3)<< " ";
	}
	cout << endl;
	arrStackDelete(stack1);
	arrStackDelete(stack2);
	arrStackDelete(stack3);
	//
	cout << "\ndone" << endl;
	return 0;
}