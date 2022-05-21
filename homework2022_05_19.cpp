#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        next = NULL;
    }
};

template<typename T>
class Queue{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;
public:
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void push(T data) {
        Node<T> *newnode = new Node<T>(data);
        if(tail == NULL){
            head = newnode;
            tail = newnode;
        }else{
            tail->next = newnode;
            tail = tail->next;
        }
        size++;
    }
    int getSize() {
        return size;
    }
    bool isEmpty() {
        return size == 0;
    }
    T pop() {
        if(head == NULL){
            return 0;
        }
        Node<T> *help = head;
        T ans = head->data;
        head = head->next;
        delete help;
        size--;
        if(size == 0){
            head = NULL;
            tail = NULL;
        }
        return ans;
    }

    T front()  {
        if(head == NULL){
            return 0;
        }
        return head->data;
    }
};

int main(){
    Queue<int> q1, q2, final_q;
    for(int i = 0; i < 8; ++i) {
        q1.push(i + 1);
    }
    for(int i = 0; i < 5; ++i){
        q2.push(8 + i);
    }
    while(!q1.isEmpty() or !q2.isEmpty()){
        if(!q1.isEmpty())
            final_q.push(q1.pop());
        if(!q2.isEmpty())
            final_q.push(q2.pop());
    }
    cout << "Union queue:\n";
    while(!final_q.isEmpty()){
        cout << final_q.pop() << " ";
    }
}