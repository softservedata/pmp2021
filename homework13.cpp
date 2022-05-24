#include<iostream>
using namespace std;

#define Element int

struct ArrayStack
{
	Element* data;
	int a;
	int sp;
};

void arrStackCreate(ArrayStack*& stack, int a)
{
	stack = new ArrayStack();
	stack->data = new int[a];
	stack->a = a;
	stack->sp = -1;
	for (int i = 0; i < a; i++)
	{
		stack->data[i] = 0;
	}
}

bool arrStackPush(ArrayStack* stack, Element element)
{
	bool result = (stack->sp < stack->a - 1);
	if (result)
	{
		stack->sp++;
		stack->data[stack->sp] = element;
	}
	return result;
}

bool arrStackPushs(ArrayStack* stack, Element* element, int a)
{
	bool result = true;
	for (int i = 0; result && (i < a); i++)
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
	cout << "a = " << stack->a << endl;
	cout << "sp = " << stack->sp << endl;
	for (int i = 0; i <= stack->sp; i++)
	{
		cout << "element[" << i << "] = " << stack->data[i] << endl;
	}
}


ArrayStack* unionStacks(ArrayStack* stack1, ArrayStack* stack2)
{
	ArrayStack* res = NULL;

	int size = stack1->a + stack2->a;
	arrStackCreate(res, size);

	Element* result = new Element[size];

	int i = stack1->a - 1;

	while (!arrStackIsEmpty(stack1))
	{
		result[i] = *arrStackPop(stack1);
		i--;
	}

	i = size - 1;
	while (!arrStackIsEmpty(stack2))
	{
		result[i] = *arrStackPop(stack2);
		i--;
	}

	arrStackPushs(res, result, size);
	delete[]result;
	return res;
}


int main()
{
	int a = 4;

	ArrayStack* stack1 = NULL;
	ArrayStack* stack2 = NULL;
	ArrayStack* stack3 = NULL;

	Element* elemArray1 = new Element[n]{ 1, 2, 3, 4 };
	Element* elemArray2 = new Element[n]{ 5, 6, 7, 8 };
	Element* elemArray3 = new Element[n]{ 9, 10, 11, 12 };

	arrStackCreate(stack1, a);
	arrStackCreate(stack2, a);
	arrStackCreate(stack3, a);

	arrStackPushs(stack1, elemArray1, a);
	arrStackPushs(stack2, elemArray2, a);
	arrStackPushs(stack3, elemArray3, a);

	arrStackPrint(stack1, "After Add Array of Elements stack 1");
	arrStackPrint(stack2, "After Add Array of Elements stack 2");
	arrStackPrint(stack3, "After Add Array of Elements stack 3");

	ArrayStack* unionof2stacks = unionStacks(stack1, stack2);

	ArrayStack* unionof3stacks = unionStacks(unionof2stacks, stack3);
	arrStackPrint(unionof3stacks, "After union of three stacks");

	cout << endl;
	cout << "\nelements union stack1, stack2 and stack3:" << endl;
	while (!arrStackIsEmpty(unionof3stacks))
	{
		cout << "  " << *arrStackPop(unionof3stacks);
	}
	cout << endl;


	arrStackDelete(stack1);
	arrStackDelete(stack2);
	arrStackDelete(stack3);
	arrStackDelete(unionof2stacks);
	arrStackDelete(unionof3stacks);

	cout << "\ndone" << endl;

	return 0;
	system("pause");
}