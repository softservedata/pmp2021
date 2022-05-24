#include <iostream>

using namespace std;

struct Queue {
    int data;
    Queue *next;

    ~Queue() {
        delete[] next;
    }
};

void que_push(Queue *&queue, int node_data) {
    Queue* que_temp = new Queue();
    que_temp->data = node_data;
    que_temp->next = queue;
    queue = que_temp;
}

void pop(Queue *&queue) {
    if (queue == nullptr)
        return;

    if (queue->next == nullptr) {
        delete queue;
        queue = nullptr;
        return;
    }

    Queue *pre_last = queue;
    while (pre_last->next->next != nullptr)
        pre_last = pre_last->next;

    delete (pre_last->next);

    pre_last->next = nullptr;
}

void que_delete(Queue *&queue) {
    Queue* que_temp = nullptr;
    while (queue != nullptr)
    {
        que_temp = queue;
        queue = queue->next;
        delete que_temp;
    }
}

int bottom(Queue *&queue){
    return queue->data;
}

bool is_empty1(Queue *queue) {
    if (queue == nullptr) return true;
    else return false;
}

void que_print(Queue *&queue) {
    Queue* temp = queue;
    if (temp == nullptr)
        cout << "Empty queue: error";
    else {
        while (!is_empty1(temp)) {
            cout << bottom(temp) << " ";
            temp = temp->next;
        }
    }
    que_delete(temp);
    cout << endl;
}

Queue* que_read() {
    Queue* queue = nullptr;

    int n;
    cout << "Enter quantity of elements:";
    cin >> n;
    cout << "Enter a queue:\n";

    int temp;
    for (int i = 0; i < n; ++i){
        cin >> temp;
        que_push(queue, temp);
    }
    return queue;
}

Queue* que_union(Queue*& queue1, Queue*& queue2){
    Queue* main_stack = nullptr;

    int elem = 0;
    while(!is_empty1(queue1) || !is_empty1(queue2)){
        if (!is_empty1(queue1)) {
            elem = bottom(queue1);
            que_push(main_stack, elem);
            queue1 = queue1->next;
        }
        if (!is_empty1(queue2)){
            elem = bottom(queue2);
            que_push(main_stack, elem);
            queue2 = queue2->next;
        }
    }
    que_delete(queue1);
    que_delete(queue2);
    return main_stack;
}

int main() {
    Queue *first_que = que_read();
    Queue *second_que = que_read();

    cout << "First queue \n";
    que_print(first_que);
    cout << "Second queue \n";
    que_print(second_que);

    Queue* merge = que_union(first_que, second_que);

    cout << "Result \n";
    que_print(merge);

    que_delete(merge);
}
