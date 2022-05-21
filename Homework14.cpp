
#include <iostream>
using namespace std;

struct LNode1
{
	int data;
	LNode1* link;
};

void pushQueue(LNode1*& head, int num)
{
	LNode1* ptr = new LNode1();
	ptr->data = num;
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
		pushQueue(listCopy, ptr->data);
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
		cout << ltemp->data << "  ";
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
		element = head->data;
		delete head;
		head = nullptr;
		return element;
	}

	LNode1* ptr = head;
	head = head->link;
	element = ptr->data;
	delete ptr;
	return element;
}


void Union(LNode1* queue1, LNode1* queue2, LNode1*& queue3)
{
	LNode1* _queue1=nullptr;
	copy(queue1, _queue1);

	LNode1* _queue2=nullptr;
	copy(queue2, _queue2);
	//
	LNode1* ptr1 = _queue1;
	LNode1* ptr2 = _queue2;

	if (queue3 != nullptr)
	{
		cout << "N0" << endl;
		listDelete(queue3);
	}


	while (_queue1!= nullptr && _queue2 != nullptr)
	{
		int el1 = popQueue(_queue1);
		pushQueue(queue3, el1);
		//
		int el2 = popQueue(_queue2);

		pushQueue(queue3, el2);
	}

	while (_queue1 != nullptr)
	{
		int el1 = popQueue(_queue1);

		pushQueue(queue3, el1);
	}

	while (_queue2 != nullptr)
	{
		int el2 = popQueue(_queue2);

		pushQueue(queue3, el2);

	}
}



int main()
{
	//
	int n1;
	cout << "n1 = ";
	cin >> n1;
	LNode1* queue1=nullptr;
	for (int i = 0; i < n1; i++)
	{
		pushQueue(queue1, i);
	}
	
	printQueue(queue1, "1");
	cout << endl;
	//
	int n2;
	cout << "n2 = ";
	cin >> n2;
	LNode1* queue2=nullptr;
	for (int i = n1; i <= n1+n2; i++)
	{
		pushQueue(queue2, i);
	}

	printQueue(queue2, "2");
	cout << endl;
	//
	LNode1* queue3 = nullptr;
	Union(queue1, queue2, queue3);
	printQueue(queue3, "Union");
	cout << endl;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}

