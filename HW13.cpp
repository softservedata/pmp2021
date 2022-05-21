#include <iostream>

using namespace std;
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


ArrayStack* union_two_stacks(ArrayStack*& stack1, ArrayStack*& stack2) {
    ArrayStack* stack = nullptr;

    Element elem = 0;
    while (!arrStackIsEmpty(stack1)) {
        elem = stack1->sp;
        arrStackPush(stack, elem);
        stack1 = stack1->data;
    }
    while (!arrStackIsEmpty(stack2)) {
        elem = stack1->sp;
        arrStackPush(stack, elem);
        stack2 = stack2->data;
    }
    arrStackDelete(stack1);
    arrStackDelete(stack2);
    return stack;
}



int main() {
    int n = 5;
    ArrayStack* stack1 = NULL;
    ArrayStack* stack2 = NULL;
    ArrayStack* stack3 = NULL;
    //
    Element* elemArray1 = new Element[n]{ 1, 2, 3, 4, 5 };
    Element* elemArray2 = new Element[n]{ 6, 7, 8, 9, 10 };
    Element* elemArray3 = new Element[n]{ 1, 6, 2, 9, 5 };
    //
    arrStackCreate(stack1, n);
    arrStackCreate(stack2, n);
    arrStackCreate(stack3, n);

    arrStackPushs(stack1, elemArray1, n);
    arrStackPushs(stack2, elemArray2, n);
    arrStackPushs(stack3, elemArray3, n);



    ArrayStack* ab = union_two_stacks(stack1, stack2);
    ArrayStack* abc = union_two_stacks(ab, stack3);

    arrStackPrint(abc, " stack ");
    

    arrStackDelete(abc);
    return 0;
}