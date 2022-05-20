#include<iostream>
using namespace std;

struct LNode1
{
	int data;
	LNode1* link;
};

void listDelete(LNode1* list);
//

void listCreate(LNode1*& list)
{
	listDelete(list);
	list = NULL;
}

void listPush(LNode1*& list, int element)
{
	LNode1* ltemp = new LNode1();
	ltemp->data = element;
	ltemp->link = list;
	list = ltemp;
}

void listArrPush(LNode1*& list, int* element, int n)
{
	for (int i = 0; i < n; i++)
	{
		listPush(list, element[i]);
	}
}

bool listIsEmpty(LNode1* list)
{
	return (list == NULL);
}

int listPop(LNode1*& list, bool* result = NULL)
{
	int element = 0;
	bool status = !listIsEmpty(list);
	//
	if (result == NULL)
	{
		result = &status;
	}
	else
	{
		*result = status;
	}
	if (*result)
	{
		LNode1* last = list;
		if (list->link == NULL)
		{
			list = list->link;
		}
		else
		{
			LNode1* ltemp = list;
			while (ltemp->link->link != NULL)
			{
				ltemp = ltemp->link;
			}
			last = ltemp->link;
			ltemp->link = NULL;
		}
		element = last->data;
		delete last;
	}
	return element;
}

void listDelete(LNode1* list)
{
	LNode1* ltemp = NULL;
	while (list != NULL)
	{
		ltemp = list;
		list = list->link;
		delete ltemp;
	}
}

void listPrint(LNode1* list, const char* Message)
{
	cout << "\nList: " << Message << endl;
	//
	LNode1* ltemp = list;
	while (ltemp != NULL)
	{
		cout << ltemp->data << "  ";
		ltemp = ltemp->link;
	}
	cout << endl;
}

void listPrintArr(int* arr, int n, const char* message)
{
	cout << "\nArray " << message << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t ";
	}
	cout << endl;
}

int main13a()
{
	int i = 0;
	int n = 10;
	int* elemArray = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* resArray = new int[n] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	//
	LNode1* lp = NULL;
	listCreate(lp);
	listArrPush(lp, elemArray, n);
	//
	listPrintArr(elemArray, n, "elemArray");
	listPrint(lp, "Original list");
	//
	while (!listIsEmpty(lp))
	{
		resArray[i] = listPop(lp);
		i++;
	}
	listPrintArr(resArray, n, "resArray");
	//
	listDelete(lp);
	delete[] elemArray;
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}

