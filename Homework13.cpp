#include <iostream>

using namespace std;

// Структура однонапревленого списку(стеку)
struct stack {
    int data;
    stack *next;

    ~stack() {
        delete[] next;
    }
};

// Створення нового вузла у кінці стеку з даними
void push(stack *&head, int node_data) {

    stack *newNode = new stack; // Створення вузла
    newNode->data = node_data; // Створення даних
    newNode->next = nullptr;  // Встановлення нового вузла на нуловий вказівник

    if (head == nullptr)    // Якщо вузол пустий, створення першого вузла
    {
        head = newNode;
        return;
    }

    stack *last = head; // Тимчасовий вказівник
    while (last->next != nullptr) // Пересування до останнього вузла
        last = last->next;

    last->next = newNode; // Змінення вказівника на останній вузол
}

// Видалення останнього вузла з однонапревленого списку
void pop(stack *&head) {
    if (head == nullptr)
        return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    // Знаходження перед останнього вузла
    stack *pre_last = head;
    while (pre_last->next->next != nullptr)
        pre_last = pre_last->next;

    // Видалення останнього вузла
    delete (pre_last->next);

    // Змінення перед останнього вузла на нульовий вказівник
    pre_last->next = nullptr;
}

// Видалення стеку
void delete_stack(stack *&head) {
    while (head != nullptr)
        pop(head);
    delete head;
}

// Повертає верхні(дані з останнього вузла) дані зі стеку
int top(stack *&head) {
    stack *last = head;
    if (last == nullptr) return 0;
    else
        while (last->next != nullptr) // Рух до останнього вузла
            last = last->next;
    return last->data;
}

// Перевірка, чи стек пустий
bool is_empty1(stack *head) {
    if (head == nullptr) return true;
    else return false;
}

// Виведення усіх вузлів
void print_stack(stack *&head) {
    if (head == nullptr)
        cout << "Empty list: error";
    else {
        while (!is_empty1(head)) {
            cout << top(head) << " ";
            pop(head);
        }
    }
    cout << endl;
}

// Створення стеку
stack* read_stack() {
    stack* stack = nullptr;

    int n = 0;
    cout << "Enter quantity of elements:";
    cin >> n;
    cout << "Enter a string:";

    int temp;
    for (int i = 0; i < n; ++i){
        cin >> temp;
        push(stack, temp);
    }
    return stack;
}

// Повертає нажні дані зі стеку (першого вузла)
int bottom(stack *&head){
    return head->data;
}

// Функція об'єднання двох стеків
stack* union_two_stacks(stack*& stack1, stack*& stack2){
    stack* main_stack = nullptr;

    int elem = 0;
    while(!is_empty1(stack1)){
        elem = bottom(stack1);
        push(main_stack, elem);
        stack1 = stack1->next;
    }
    while(!is_empty1(stack2)){
        elem = bottom(stack2);
        push(main_stack, elem);
        stack2 = stack2->next;
    }
    delete_stack(stack1);
    delete_stack(stack2);
    return main_stack;
}

int main() {
    stack *a = read_stack();
    stack *b = read_stack();
    stack *c = read_stack();

    stack* ab = union_two_stacks(a, b);
    stack* abc = union_two_stacks(ab, c);

    print_stack(abc);

    delete_stack(abc);
    return 0;
}
