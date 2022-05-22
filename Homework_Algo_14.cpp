#include<iostream>
using namespace std;

struct LNode1
{
    int data;
    LNode1* link;
};

void listDelete(LNode1* list);


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

void readingn(int& n, const char* Message){
    do {
        cout << Message;
        cin >> n;
    } while (n <= 0);
}

void readList(int& n, LNode1*& list, const char* Message1, const char* Message2){
    cout<<"reading your list"<<endl;
    readingn(n, Message2);
    int* arr=new int[n];
    cout<<endl;
    for(int i=n-1; i>-1; i--){
        cout<<Message1<<"["<<n-1-i<<"] = ";
        cin>>arr[i];
    }
    listArrPush(list, arr, n);
    delete[] arr;
    cout<<endl;
}

bool listIsEmpty(LNode1* list)
{
    return (list == NULL);
}

int listPop(LNode1*& list, bool* result = NULL)
{
    int element = 0;
    bool status = !listIsEmpty(list);
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

void listUnite(int n1, LNode1*& list1, int n2, LNode1*& list2, LNode1*& list3){
    int* arr1=new int[n1];
    int* arr2=new int[n2];
    for(int i=n1-1; i>-1; i--){
        arr1[i]= listPop(list1);
    }
    for(int i=n2-1; i>-1; i--){
        arr2[i]= listPop(list2);
    }
    int* arr3=new int[n1+n2];
    int s1=0;
    int s2=0;
    for(int i=0; i<n1+n2; i++){
        if(s1<n1 && s2<n2){
            if(i%2==0){
                arr3[n1+n2-1-i]=arr1[s1];
                s1=s1+1;
            }
            else{
                arr3[n1+n2-1-i]=arr2[s2];
                s2=s2+1;
            }
        }
        else if(s1>=n1){
            arr3[n1+n2-1-i]=arr2[s2];
            s2=s2+1;
        }
        else if(s2>=n2){
            arr3[n1+n2-1-i]=arr1[s1];
            s1=s1+1;
        }
    }
    listArrPush(list3, arr3, n1+n2);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
}

int main()
{
    int n1, n2;
    LNode1* list1=NULL;
    LNode1* list2=NULL;
    LNode1* list3=NULL;
    listCreate(list1);
    listCreate(list2);
    readList(n1, list1, "List 1", "n1 = ");
    readList(n2, list2, "List 2", "n2 = ");
    listCreate(list3);
    listUnite(n1, list1, n2, list2, list3);
    listPrint(list3, "United list");
    listDelete(list1);
    listDelete(list2);
    listDelete(list3);
    return 0;
}