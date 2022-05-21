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

void arrStackRead(ArrayStack*& stack, int n, const char* message) {
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cout << message << "[" << i + 1 << "]=";
		cin >> arr[i];
	}
	arrStackPushs(stack, arr, n);
	delete[]arr;
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

ArrayStack* suma(ArrayStack* stack1, ArrayStack* stack2) {
	ArrayStack* sum = nullptr;
	int a1 = stack1->sp;
	int a2 = stack2->sp;
	int* arr = new int[stack1->n + stack2->n];
	arrStackCreate(sum, stack1->n + stack2->n);
	int s = stack1->n - 1;
	while (!arrStackIsEmpty(stack1)) {
		arr[s] = *arrStackPop(stack1);
		s = s - 1;
	}
	s = stack1->n + stack2->n - 1;
	while (!arrStackIsEmpty(stack2)) {
		arr[s] = *arrStackPop(stack2);
		s = s - 1;
	}
	arrStackPushs(sum, arr, stack1->n + stack2->n);
	delete[]arr;
	stack1->sp = a1;
	stack2->sp = a2;
	return sum;
}

int main013()
{
	/*int n = 10;
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
	/*arrStackCreate(stack, n);
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
	cout << "\ndone" << endl;*/
	int n1, n2, n3;
	cout << "Enter n1: ";
	cin >> n1;
	ArrayStack* stack1 = nullptr;
	arrStackCreate(stack1, n1);
	arrStackRead(stack1, n1, "Stack1");
	cout << "Enter n2: ";
	cin >> n2;
	ArrayStack* stack2 = nullptr;
	arrStackCreate(stack2, n2);
	arrStackRead(stack2, n2, "Stack2");
	cout << "Enter n3: ";
	cin >> n3;
	ArrayStack* stack3 = nullptr;
	arrStackCreate(stack3, n3);
	arrStackRead(stack3, n3, "Stack3");
	cout << endl << "print check";
	arrStackPrint(stack1, "Stack1");
	arrStackPrint(stack2, "Stack2");
	arrStackPrint(stack3, "Stack3");
	ArrayStack* sum1 = nullptr;
	sum1 = suma(stack1, stack2);
	cout << endl << "check sum 1 2";
	arrStackPrint(sum1, "sum 1 + 2");
	ArrayStack* sum2 = nullptr;
	sum2 = suma(sum1, stack3);
	cout << endl << endl << "final stack" << endl;
	arrStackPrint(sum2, "sum 1 + 2 + 3 ");
	arrStackDelete(stack1);
	arrStackDelete(stack2);
	arrStackDelete(stack3);
	arrStackDelete(sum1);
	arrStackDelete(sum2);

	system("pause");
	return 0;
}
