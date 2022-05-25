
#include<iostream>
using namespace std;

//Скопіювати код із App12.cpp. 
// Реалізувати підпрограму об’єднання двох стеків в один. 
// Використовувати лише реалізовані методи для роботи зі стеком (типу pop(); push(); etc.).
// В основній програмі створити три стеки, які об’єднати в один. 
// Початковий стан, та кінцевий результат виводити на екран (скористатися методом). 


struct ArrayStack
{
    int* data;
    int n;
    int sp;
};

void reading(int& n, const char* Message) 
{
    do 
    {
        cout << Message;
        cin >> n;
    } 
    while (n <= 0);
}

void stackCreatingForArray(ArrayStack*& stack, int n)
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

bool stackPushingInArray(ArrayStack* stack, int element)
{
    bool result = (stack->sp < stack->n - 1);
    if (result)
    {
        stack->sp++;
        stack->data[stack->sp] = element;
    }
    return result;
}

bool arrStackPushs(ArrayStack* stack, int* element, int n)
{
    bool result = true;
    for (int i = 0; result && (i < n); i++)
    {
        result = stackPushingInArray(stack, element[i]);
    }
    if (!result)
    {
        cout << "ERROR: Stack is Overflowed" << endl;
    }
    return result;
}

void arrStackRead(ArrayStack*& stack, int n, const char* Message) 
{
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << Message << "[" << i + 1 << "]=";
        cin >> arr[i];
    }
    arrStackPushs(stack, arr, n);
    delete[]arr;
}

bool arrStackIsEmpty(ArrayStack* stack)
{
    return (stack->sp < 0);
}

int* arrStackPop(ArrayStack* stack, bool* result = NULL)
{
    int* element = NULL;
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

ArrayStack* merger(ArrayStack* stack1, ArrayStack* stack2) {
    ArrayStack* stack_merger = nullptr;
    int a1 = stack1->sp; int a2 = stack2->sp;
    int* arr = new int[stack1->n + stack2->n];
    stackCreatingForArray(stack_merger, stack1->n + stack2->n);
    int s = stack1->n - 1;

    while (!arrStackIsEmpty(stack1)) {
        arr[s] = *arrStackPop(stack1);
        --s;
    }
    s = stack1->n + stack2->n - 1;

    while (!arrStackIsEmpty(stack2)) {
        arr[s] = *arrStackPop(stack2);
        --s;
    }

    arrStackPushs(stack_merger, arr, stack1->n + stack2->n);
    delete[]arr;
    stack1->sp = a1;
    stack2->sp = a2;
    return stack_merger;
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
    int n1, n2, n3;

    reading(n1, "First n: ");
    ArrayStack* stack1 = nullptr;

    reading(n2, "Second n: ");
    ArrayStack* stack2 = nullptr;

    reading(n3, "Third n: ");
    ArrayStack* stack3 = nullptr;

    stackCreatingForArray(stack1, n1);
    stackCreatingForArray(stack2, n2);
    stackCreatingForArray(stack3, n3);

    arrStackRead(stack1, n1, "First stack");
    arrStackRead(stack2, n1, "Second stack");
    arrStackRead(stack3, n1, "Third stack");


    arrStackPrint(stack1, "First stack");
    arrStackPrint(stack2, "Second stack");
    arrStackPrint(stack3, "Third stack");

    ArrayStack* first_merger = nullptr;
    first_merger = merger(stack1, stack2);

    arrStackPrint(first_merger, "Merger of first and second stack");
    ArrayStack* result_merger = nullptr;
    result_merger = merger(first_merger, stack3);

    arrStackPrint(result_merger, "Result is: ");
}