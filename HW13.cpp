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
ArrayStack* unionof2stacks(ArrayStack* stack1, ArrayStack* stack2) {
	ArrayStack* result = NULL;
	int p1 = stack1->sp;
	int p2 = stack2->sp;
	int len = stack1->n + stack2->n;
	Element* unite = new Element[len];
	arrStackCreate(result, len);
	int i = stack1->n - 1;
	while (!arrStackIsEmpty(stack1)) {
		unite[i] = *arrStackPop(stack1);
		i--;
	}
	i = len - 1;
	while (!arrStackIsEmpty(stack2)) {
		unite[i] = *arrStackPop(stack2);
		i--;
	}
	arrStackPushs(result, unite, len);
	delete[]unite;
	stack1->sp = p1;
	stack2->sp = p2;
	return result;
}

int main()
{
	int n = 10;
	int l = 9;
	int m = 4;
	ArrayStack* stack1 = NULL;
	ArrayStack* stack2 = NULL;
	ArrayStack* stack3 = NULL;

	Element* elemArray1 = new Element[n]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Element* elemArray2 = new Element[l]{ 11, 12, 13, 14, 15, 16, 17, 18, 19 };
	Element* elemArray3 = new Element[m]{ 22, 23, 24, 25 };

	arrStackCreate(stack1, n);
	arrStackCreate(stack2, l);
	arrStackCreate(stack3, m);

	arrStackPushs(stack1, elemArray1, n);
	arrStackPushs(stack2, elemArray2, l);
	arrStackPushs(stack3, elemArray3, m);

	arrStackPrint(stack1, "After Add Array of Elements stack 1");
	arrStackPrint(stack2, "After Add Array of Elements stack 2");
	arrStackPrint(stack3, "After Add Array of Elements stack 3");

	ArrayStack* union1and2 = unionof2stacks(stack1, stack2);
	arrStackPrint(union1and2, "After union stack1 and stack2");

	ArrayStack* unionof3stacks = unionof2stacks(union1and2, stack3);
	arrStackPrint(unionof3stacks, "After union of three stacks");

	cout << "\nelements stack 1 = ";
	while (!arrStackIsEmpty(stack1))
	{
		cout << "  " << *arrStackPop(stack1);
	}
	cout << endl;
	cout << "\nelements stack 2 = ";
	while (!arrStackIsEmpty(stack2))
	{
		cout << "  " << *arrStackPop(stack2);
	}
	cout << endl;

	cout << "\nelements stack 3 = ";
	while (!arrStackIsEmpty(stack3))
	{
		cout << "  " << *arrStackPop(stack3);
	}
	cout << endl;
	cout << "\nelements union stack1 and stack2 = ";
	while (!arrStackIsEmpty(union1and2))
	{
		cout << "  " << *arrStackPop(union1and2);
	}
	cout << endl;
	cout << "\nresult union elements = ";
	while (!arrStackIsEmpty(unionof3stacks))
	{
		cout << "  " << *arrStackPop(unionof3stacks);
	}
	cout << endl;


	arrStackDelete(stack1);
	arrStackDelete(stack2);
	arrStackDelete(stack3);
	arrStackDelete(union1and2);
	arrStackDelete(unionof3stacks);

	cout << "\ndone" << endl;
	system("pause");
	return 0;
}