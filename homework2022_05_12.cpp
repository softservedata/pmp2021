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

template <typename T>
class Stack
{
    Node<T> *front;  // points to the head of list
public:
    Stack(){
        front = NULL;
    }
    bool isEmpty(){
        return front == NULL;
    }
    void push(T val)
    {
        Node<T> *temp;
        temp = new Node<T>(val);

        if(front == NULL)
            temp->next = NULL;
        else
            temp->next = front;
        front = temp;
    }
    T pop(){
        if(front == NULL)
            return 0;
        else{
            Node<T> *temp = front;
            T return_val = temp->data;
            front = front->next;
            delete(temp);
            return return_val;
        }
    }
    T top(){
        if(front == NULL)
            return 0;
        else{
            return front->data;
        }
    }
    void display()
    {
        Node<T>* temp;
        if (front == NULL)
            return;
        else{
            temp = front;
            while (temp != NULL){
                cout << temp->data << (temp->next != NULL ? "->" : "\n");
                temp = temp->next;
            }
        }
    }
};

template <typename T>
auto stack_union(initializer_list<Stack<T>*> stacks){
    Stack<T> stack_union;
    for(auto stack : stacks){
        while(!stack->isEmpty()){
            stack_union.push(stack->pop());
        }
    }
    return stack_union;
}

int main(){
    Stack<int> st1, st2, st3;
    int n,a;
    for(auto st : {&st1, &st2, &st3}){
        cout << "size of stack=";
        cin >> n;
        for(int i = 0; i < n; ++i){
            cout << i + 1 << " element=";
            cin >> a;
            st->push(a);
        }
    }
    int cnt = 1;
    for(auto st : {&st1, &st2, &st3}){
        cout << cnt << " stack:\n";
        st->display();
        cnt += 1;
    }
    Stack<int> union_stack = stack_union({&st1, &st2, &st3});
    cout << "Stack union:\n";
    union_stack.display();
}