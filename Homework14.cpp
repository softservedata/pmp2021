#include <iostream>
using namespace std;

struct LNode1
{
	int dat;
	LNode1* link;
};

void pushQueue(LNode1*& head, int num)
{
	LNode1* ptr = new LNode1();
	ptr->dat = num;
	ptr->link = nullptr;
	if (head == nullptr)
	{
		head = ptr;
		return;
	}
	LNode1* temp = head;
	while (temp->link != nullptr)
	{
		temp = temp->link;
	}
	temp->link = ptr;
}

void listDelete(LNode1*& list)
{
	LNode1* ltemp = NULL;
	while (list != NULL)
	{
		ltemp = list;
		list = list->link;
		delete ltemp;
	}
}

void copy(LNode1* list, LNode1*& listCopy)
{
	if (listCopy != NULL)
	{
		listDelete(listCopy);
		listCopy = nullptr;
	}

	LNode1* ptr = list;
	while (ptr != nullptr)
	{
		pushQueue(listCopy, ptr->dat);
		ptr = ptr->link;
	}
}

void printQueue(LNode1* list, const char* Message)
{
	cout << "Queue: " << Message << endl;
	//
	LNode1* ltemp = list;
	while (ltemp != NULL)
	{
		cout << ltemp->dat << "  ";
		ltemp = ltemp->link;
	}
	cout << endl;
}



bool listIsEmpty(LNode1* head)
{
	return (head == NULL);
}


int popQueue(LNode1*& head)
{
	int element = 0;
	//
	if (head == NULL)
	{
		return element;
	}

	if (head->link == nullptr)
	{
		element = head->dat;
		delete head;
		head = nullptr;
		return element;
	}

	LNode1* ptr = head;
	head = head->link;
	element = ptr->dat;
	delete ptr;
	return element;
}


void Union(LNode1* queue, LNode1* queue1, LNode1*& queue2)
{
	LNode1* _queue = nullptr;
	copy(queue, _queue);

	LNode1* _queue1 = nullptr;
	copy(queue1, _queue1);
	//
	LNode1* ptr = _queue;
	LNode1* ptr1 = _queue1;

	if (queue2 != nullptr)
	{
		cout << "N0" << endl;
		listDelete(queue2);
	}


	while (_queue != nullptr && _queue1 != nullptr)
	{
		int el1 = popQueue(_queue);
		pushQueue(queue2, el1);
		//
		int el2 = popQueue(_queue1);

		pushQueue(queue2, el2);
	}

	while (_queue != nullptr)
	{
		int el1 = popQueue(_queue);

		pushQueue(queue2, el1);
	}

	while (_queue1 != nullptr)
	{
		int el2 = popQueue(_queue1);

		pushQueue(queue2, el2);

	}
}



int main()
{
	//
	int n;
	cout << "n = ";
	cin >> n;
	LNode1* queue = nullptr;
	for (int i = 0; i < n; i++)
	{
		pushQueue(queue, i);
	}

	printQueue(queue, "0");
	cout << endl;
	//
	int n1;
	cout << "n1 = ";
	cin >> n1;
	LNode1* queue1 = nullptr;
	for (int i = n1; i <= n + n1; i++)
	{
		pushQueue(queue, i);
	}

	printQueue(queue, "");
	cout << endl;
	//
	LNode1* queue2 = nullptr;
	Union(queue, queue1, queue2);
	printQueue(queue2, "Union");
	cout << endl;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
