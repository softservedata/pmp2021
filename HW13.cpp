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

//// ��������� ���������������� ������(�����)
//struct stack {
//    int data;
//    stack* next;
//
//    ~stack() {
//        delete[] next;
//    }
//};
//
//
//
//// ��������� ������ ����� � ���� ����� � ������
//void push(stack*& head, int node_data) {
//
//    stack* newNode = new stack; // ��������� �����
//    newNode->data = node_data; // ��������� �����
//    newNode->next = nullptr;  // ������������ ������ ����� �� ������� ��������
//
//    if (head == nullptr)    // ���� ����� ������, ��������� ������� �����
//    {
//        head = newNode;
//        return;
//    }
//
//    stack* last = head; // ���������� ��������
//    while (last->next != nullptr) // ����������� �� ���������� �����
//        last = last->next;
//
//    last->next = newNode; // ������� ��������� �� ������� �����
//}
//
//// ��������� ���������� ����� � ���������������� ������
//void pop(stack*& head) {
//    if (head == nullptr)
//        return;
//
//    if (head->next == nullptr) {
//        delete head;
//        head = nullptr;
//        return;
//    }
//
//    // ����������� ����� ���������� �����
//    stack* pre_last = head;
//    while (pre_last->next->next != nullptr)
//        pre_last = pre_last->next;
//
//    // ��������� ���������� �����
//    delete (pre_last->next);
//
//    // ������� ����� ���������� ����� �� �������� ��������
//    pre_last->next = nullptr;
//}
//
//// ��������� �����
//void delete_stack(stack*& head) {
//    while (head != nullptr)
//        pop(head);
//    delete head;
//}
//
//// ������� �����(��� � ���������� �����) ��� � �����
//int top(stack*& head) {
//    stack* last = head;
//    if (last == nullptr) return 0;
//    else
//        while (last->next != nullptr) // ��� �� ���������� �����
//            last = last->next;
//    return last->data;
//}
//
//// ��������, �� ���� ������
//bool is_empty1(stack* head) {
//    if (head == nullptr) return true;
//    else return false;
//}
//
//// ��������� ��� �����
//void print_stack(stack*& head) {
//    if (head == nullptr)
//        cout << "Empty list: error";
//    else {
//        while (!is_empty1(head)) {
//            cout << top(head) << " ";
//            pop(head);
//        }
//    }
//    cout << endl;
//}
//
//// ��������� �����
//stack* read_stack() {
//    stack* stack = nullptr;
//
//    int n = 0;
//    cout << "Enter quantity of elements:";
//    cin >> n;
//    cout << "Enter a string:";
//
//    int temp;
//    for (int i = 0; i < n; ++i) {
//        cin >> temp;
//        push(stack, temp);
//    }
//    return stack;
//}
//
//// ������� ���� ��� � ����� (������� �����)
//int bottom(stack*& head) {
//    return head->data;
//}
//
//// ������� ��'������� ���� �����
//stack* union_two_stacks(stack*& stack1, stack*& stack2) {
//    stack* main_stack = nullptr;
//
//    int elem = 0;
//    while (!is_empty1(stack1)) {
//        elem = bottom(stack1);
//        push(main_stack, elem);
//        stack1 = stack1->next;
//    }
//    while (!is_empty1(stack2)) {
//        elem = bottom(stack2);
//        push(main_stack, elem);
//        stack2 = stack2->next;
//    }
//    delete_stack(stack1);
//    delete_stack(stack2);
//    return main_stack;
//}

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