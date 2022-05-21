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
LNode1* alternate(LNode1* list1, LNode1* list2) {
	LNode1* result = NULL;
	int i = 0;
	listCreate(result);
	while (!listIsEmpty(list1)) {
		if (!listIsEmpty(list2)) {
			if (i % 2 == 0) {
				listPush(result, listPop(list1));
			}
			else {
				listPush(result, listPop(list2));
			}
			i++;
		}
		else {
			listPush(result, listPop(list1));
			i++;
		}
	}
	if (listIsEmpty(list1) && !listIsEmpty(list2)) {
		while (!listIsEmpty(list2))
		{
			listPush(result, listPop(list2));
			i++;
		}
	}
	return result;
}

int main()
{
	int i = 0;
	int n = 10;
	int m = 7;
	int* elemArray1 = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* resArray1 = new int[n] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int* elemArray2 = new int[] { 11, 22, 33, 44, 55, 66, 77, 88 };
	int* resArray2 = new int[m] { 0, 0, 0, 0, 0, 0, 0, 0 };
	//
	LNode1* lp1 = NULL;
	listCreate(lp1);
	listArrPush(lp1, elemArray1, n);

	listPrintArr(elemArray1, n, "elemArray");
	listPrint(lp1, "Original list");

	LNode1* lp2 = NULL;
	listCreate(lp2);
	listArrPush(lp2, elemArray2, m);

	listPrintArr(elemArray2, m, "elemArray");
	listPrint(lp2, "Original list");

	LNode1* result = alternate(lp1, lp2);
	listPrint(result, "result of alternate union list");
	delete[] elemArray1;
	delete[] elemArray2;
	/*listDelete(lp1);
	listDelete(lp2);*/
	listDelete(result);
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}
