#include <iostream>

using namespace std;

// Структура однонапревленого списку(стеку) - обгортка для черги
struct Queue {
    int data;
    Queue *next;

    ~Queue() {
        delete[] next;
    }
};

// Створення нового вузла у кінці черги з даними
void push(Queue *&queue, int node_data) {

    Queue *newNode = new Queue; // Створення вузла
    newNode->data = node_data; // Створення даних
    newNode->next = nullptr;  // Встановлення нового вузла на нуловий вказівник

    if (queue == nullptr)    // Якщо вузол пустий, створення першого вузла
    {
        queue = newNode;
        return;
    }

    Queue *last = queue; // Тимчасовий вказівник
    while (last->next != nullptr) // Пересування до останнього вузла
        last = last->next;

    last->next = newNode; // Змінення вказівника на останній вузол
}

// Видалення останнього вузла з однонапревленого списку
void pop(Queue *&queue) {
    if (queue == nullptr)
        return;

    if (queue->next == nullptr) {
        delete queue;
        queue = nullptr;
        return;
    }

    // Знаходження перед останнього вузла
    Queue *pre_last = queue;
    while (pre_last->next->next != nullptr)
        pre_last = pre_last->next;

    // Видалення останнього вузла
    delete (pre_last->next);

    // Змінення перед останнього вузла на нульовий вказівник
    pre_last->next = nullptr;
}

// Видалення черги
void delete_queue(Queue *&queue) {
    while (queue != nullptr)
        pop(queue);
    delete queue;
}

// Повертає верхні(дані з останнього вузла) дані зі черги
int top(Queue *&queue) {
    Queue *last = queue;
    if (last == nullptr) return 0;
    else
        while (last->next != nullptr) // Рух до останнього вузла
            last = last->next;
    return last->data;
}

// Повертає нажні дані зі черги (першого вузла)
int bottom(Queue *&queue){
    return queue->data;
}

// Перевірка, чи черга пуста
bool is_empty1(Queue *queue) {
    if (queue == nullptr) return true;
    else return false;
}

// Читання черги
void print_queue(Queue *&queue) {
    Queue* temp = queue;
    if (temp == nullptr)
        cout << "Empty queue: error";
    else {
        cout << "Queue: ";
        while (!is_empty1(temp)) {
            cout << bottom(temp) << " ";
            temp = temp->next;
        }
    }
    delete_queue(temp);
    cout << endl;
}

// Створення черги
Queue* read_queue() {
    Queue* queue = nullptr;

    int n = 0;
    cout << "Enter quantity of elements:";
    cin >> n;
    cout << "Enter a queue:";

    int temp;
    for (int i = 0; i < n; ++i){
        cin >> temp;
        push(queue, temp);
    }
    return queue;
}

// Функція об'єднання двох черг по черзі
Queue* union_two_queue(Queue*& queue1, Queue*& queue2){
    Queue* main_stack = nullptr;

    int elem = 0;
    while(!is_empty1(queue1) || !is_empty1(queue2)){
        if (!is_empty1(queue1)) {
            elem = bottom(queue1);
            push(main_stack, elem);
            queue1 = queue1->next;
        }
        if (!is_empty1(queue2)){
            elem = bottom(queue2);
            push(main_stack, elem);
            queue2 = queue2->next;
        }
    }
    delete_queue(queue1);
    delete_queue(queue2);
    return main_stack;
}

int main() {
    Queue *a = read_queue();
    Queue *b = read_queue();

    cout << "First ";
    print_queue(a);
    cout << "Second ";
    print_queue(b);

    Queue* ab = union_two_queue(a, b);

    cout << "United ";
    print_queue(ab);

    delete_queue(ab);
    return 0;
}