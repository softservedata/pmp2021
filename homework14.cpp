// Задати дві черги з різною кількістю елементів (можна захардкодити). Об’єднати ці дві черги в одну чергуючи елементи.
// Якщо елементи якоїсь черги закінчилися, тоді просто додаються всі елементи іншої черги. Надрукувати результівну чергу.

#include <iostream>

using namespace std;

template<class T>
struct DoublyLinkedNode { // нод - одиниця двонапрямного списку
    T data{};
    DoublyLinkedNode *next{}, *prev{}; // пойнтер на наступний і попередній ноди; області пам'яті звільняються в списку

    DoublyLinkedNode(const T &d, DoublyLinkedNode<T> *n, DoublyLinkedNode<T> *p);
};

template<class T>
struct Iter { // ітератор по нодах списку; перегрузка операторів !=, *, ++ необхідна, щоб працював range-based for loop
    // відповідно друкування списку буде виглядати як for (auto el: list) cout << el << ' ';
    DoublyLinkedNode<T> *node{}; // пойнтер на нод; область пам'яті звільняється в списку

    explicit Iter(DoublyLinkedNode<T> *n); // explicit, бо 1 аргумент в конструкторі

    bool operator!=(const Iter &other) const noexcept; // порівнює з іншим ітератором (чи не дорівнює кінцю)

    T &operator*() const noexcept; // перевантаження дереференсу для доступу до даних

    const Iter &operator++() noexcept; // перевантаження інкременту ітератора
};

template<class T>
class DoublyLinkedList { // сам двонапрямний список
private:
    DoublyLinkedNode<T> *head{}, *tail{}; // пойнтер на нод-початок і нод-кінець
    size_t list_size{}; // розмір

    void insertBefore(DoublyLinkedNode<T> *node, const T &new_data); // вставлення нового ноду перед певним нодом

    void insertAfter(DoublyLinkedNode<T> *node, const T &new_data); // вставлення нового ноду після певного ноду

    void remove(DoublyLinkedNode<T> *node); // видалення певного ноду

public:
    DoublyLinkedList();

    DoublyLinkedList(initializer_list<T> init); // конструктор-ініціалізатор

    DoublyLinkedList(const DoublyLinkedList<T> &list); // конструктор копіювання

    T &at(size_t pos) const; // доступ до референса на елемент за позицією за O(n)

    T &operator[](size_t pos) const; // доступ за квадратними дужками

    Iter<T> begin() const noexcept; // ітератор на початок

    Iter<T> end() const noexcept; // ітератор на кінець (tail->next)

    bool empty() noexcept; // перевірка чи пустий

    size_t size() noexcept; // розмір

    T &front() const; // доступ до першого елемента

    T &back() const; // доступ до останнього елемента

    void push_front(const T &new_data) noexcept; // додати спереду

    void push_back(const T &new_data) noexcept; // додати ззаду

    void pop_front(); // видалити спереду

    void pop_back(); // видалити ззаду

    ~DoublyLinkedList(); // звільняю пам'ять в циклі
};

template<class T>
class Queue { // сама черга
private:
    DoublyLinkedList<T> container; // обгортає двонапрямний список
public:
    Queue();

    Queue(initializer_list<T> init);

    Queue(const Queue<T> &other);

    explicit Queue(const DoublyLinkedList<T> &other);

    bool empty() noexcept;

    size_t size() noexcept;

    T &front() const;

    T &back() const;

    void push(const T &new_data) noexcept;

    void pop();
};

template<class T>
DoublyLinkedNode<T>::DoublyLinkedNode(const T &d, DoublyLinkedNode<T> *n, DoublyLinkedNode<T> *p)
        : data{d}, next{n}, prev{p} {}

template<class T>
Iter<T>::Iter(DoublyLinkedNode<T> *n) : node{n} {} // explicit, бо 1 аргумент в конструкторі

template<class T>
bool Iter<T>::operator!=(const Iter<T> &other) const noexcept { // порівнює з іншим ітератором (чи не дорівнює кінцю)
    return node != other.node;
}

template<class T>
T &Iter<T>::operator*() const noexcept { // перевантаження дереференсу для доступу до даних
    return node->data;
}

template<class T>
const Iter<T> &Iter<T>::operator++() noexcept { // перевантаження інкременту ітератора
    node = node->next;
    return *this; // заведено повертати значення при інкременті
}

template<class T>
// вставлення нового ноду перед певним нодом
void DoublyLinkedList<T>::insertBefore(DoublyLinkedNode<T> *node, const T &new_data) {
    auto newNode = new DoublyLinkedNode<T>(new_data, node, nullptr); // створення нового ноду з пойнтером на даний
    if (node->prev == nullptr) // якщо створюється перед першим нодом
        head = newNode;
    else { // зв'язування попереднього ноду з новим
        newNode->prev = node->prev;
        node->prev->next = newNode;
    }
    node->prev = newNode; // зв'язування даного ноду з новим
    ++list_size; // збільшення розміру
}

template<class T>
// вставлення нового ноду після певного ноду
void DoublyLinkedList<T>::insertAfter(DoublyLinkedNode<T> *node, const T &new_data) {
    auto newNode = new DoublyLinkedNode<T>(new_data, nullptr, node); // створення нового ноду з пойнтером на даний
    if (node->next == nullptr) // якщо створюється після останнього ноду
        tail = newNode;
    else { // зв'язування наступного ноду з новим
        newNode->next = node->next;
        node->next->prev = newNode;
    }
    node->next = newNode; // зв'язування даного ноду з новим
    ++list_size; // збільшення розміру
}

template<class T>
void DoublyLinkedList<T>::remove(DoublyLinkedNode<T> *node) { // видалення певного ноду
    if (node->prev == nullptr) // якщо видаляється перший нод
        head = node->next;
    else
        node->prev->next = node->next; // зв'язування попереднього ноду з наступним
    if (node->next == nullptr)// якщо видаляється останній нод
        tail = node->prev;
    else // зв'язування наступного ноду з попереднім
        node->next->prev = node->prev;
    delete node; // звільнення пам'яті
    --list_size; // зменшення розміру
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() = default; // стандартний конструктор

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const initializer_list<T> init) { // конструктор-ініціалізатор
    for (auto &el: init)
        this->push_back(el);
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> &list) { // конструктор копіювання
    for (auto node = list.head; node != nullptr; node = node->next) // проходження циклом по списку
        this->push_back(node->data);
}

template<class T>
T &DoublyLinkedList<T>::at(const size_t pos) const { // доступ до референса на елемент за позицією за O(n)
    if (pos >= list_size) // якщо позиція більша за розмір
        throw out_of_range("size is shorter");
    // в залежності від індексу, обираю з якої сторони рухатись, щоб прискорити пошук у 2 рози
    auto node = (pos <= list_size / 2 ? head : tail);
    if (pos <= list_size / 2)
        for (size_t i = 0; i < pos; ++i, node = node->next) {} // інкремент ноду pos разів
    else
        for (size_t i = 0; i < list_size - pos - 1; ++i, node = node->prev) {} // інкремент ноду list_size - pos разів
    return node->data;
}

template<class T>
T &DoublyLinkedList<T>::operator[](const size_t pos) const { // доступ за квадратними дужками
    return this->at(pos);
}

template<class T>
Iter<T> DoublyLinkedList<T>::begin() const noexcept { // ітератор на початок
    return Iter<T>(head);
}

template<class T>
Iter<T> DoublyLinkedList<T>::end() const noexcept { // ітератор на кінець (tail->next)
    return Iter<T>(nullptr);
}

template<class T>
bool DoublyLinkedList<T>::empty() noexcept { // перевірка чи пустий
    return head == nullptr;
}

template<class T>
size_t DoublyLinkedList<T>::size() noexcept { // розмір
    return list_size;
}

template<class T>
T &DoublyLinkedList<T>::front() const { // доступ до першого елемента
    if (head == nullptr)
        throw logic_error("Error, list is empty"); // якщо пустий
    else
        return head->data;
}

template<class T>
T &DoublyLinkedList<T>::back() const { // доступ до останнього елемента
    if (tail == nullptr)
        throw logic_error("error, list is empty"); // якщо пустий
    else
        return tail->data;
}

template<class T>
void DoublyLinkedList<T>::push_front(const T &new_data) noexcept { // додати спереду
    if (head == nullptr) { // якщо список пустий
        head = tail = new DoublyLinkedNode<T>(new_data, nullptr, nullptr); // створення нового ноду
        ++list_size; // збільшення розміру
    } else
        insertBefore(head, new_data);
}

template<class T>
void DoublyLinkedList<T>::push_back(const T &new_data) noexcept { // додати ззаду
    if (tail == nullptr) // якщо список пустий
        push_front(new_data);
    else
        insertAfter(tail, new_data);
}

template<class T>
void DoublyLinkedList<T>::pop_front() { // видалити спереду
    if (head == nullptr) // якщо список пустий
        throw logic_error("error, list is empty");
    else
        remove(head);
}

template<class T>
void DoublyLinkedList<T>::pop_back() { // видалити ззаду
    if (tail == nullptr) // якщо список пустий
        throw logic_error("error, list is empty");
    else
        remove(tail);
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() { // звільняю пам'ять в циклі
    for (DoublyLinkedNode<T> *node = head, *tmp; node != nullptr; node = tmp) {
        tmp = node->next;
        delete node;
    }
}

template<class T>
Queue<T>::Queue() = default;

template<class T>
Queue<T>::Queue(const initializer_list<T> init) : container(init) {} // конструктор-ініціалізатор

template<class T>
Queue<T>::Queue(const Queue<T> &other) : container(other.container) {} // конструктор копіювання

template<class T>
Queue<T>::Queue(const DoublyLinkedList<T> &other) : container(other) {} // конструктор зі списку

template<class T>
bool Queue<T>::empty() noexcept {
    return container.empty();
}

template<class T>
size_t Queue<T>::size() noexcept {
    return container.size();
}

template<class T>
T &Queue<T>::front() const {
    return container.front();
}

template<class T>
T &Queue<T>::back() const {
    return container.back();
}

template<class T>
void Queue<T>::push(const T &new_data) noexcept {
    container.push_back(new_data);
}

template<class T>
void Queue<T>::pop() {
    container.pop_front();
}

template<class T>
Queue<T> mergeQueues(Queue<T> a, Queue<T> b) {
    Queue<T> c;
    while (!(a.empty() || b.empty())) {
        c.push(a.front());
        c.push(b.front());
        a.pop();
        b.pop();
    }
    for (; !a.empty(); a.pop())
        c.push(a.front());
    for (; !b.empty(); b.pop())
        c.push(b.front());
    return c;
}

int main() {
    Queue<int> q1 = {1, 2, 3, 4, 5}, q2 = {-1, -4, -9, -16, -25, -36, -49};

    cout << "черга 1: ";
    for (auto tmp(q1); !tmp.empty(); tmp.pop())
        cout << tmp.front() << (tmp.size() != 1 ? ' ' : '\n');
    cout << "черга 2: ";
    for (auto tmp(q2); !tmp.empty(); tmp.pop())
        cout << tmp.front() << (tmp.size() != 1 ? ' ' : '\n');

    auto q3 = mergeQueues(q1, q2);

    cout << "черга 3: ";
    for (auto tmp(q3); !tmp.empty(); tmp.pop())
        cout << tmp.front() << (tmp.size() != 1 ? ' ' : '\n');
    return 0;
}