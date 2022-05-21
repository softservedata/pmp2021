#include<iostream>
using namespace std;

void setIn(int*& set, int n)
{
    set = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        set[i] = -1;
    }
}

int lastFreePosSet(const int* set, int n)
{
    int result = n;
    for (int i = 0; i < n; i++)
    {
        if (set[i] < 0)
        {
            result = i;
            break;
        }
    }
    return result;
}
void setPrn(const int* set, int n, const char* message)
{
    cout << "\nSet " << message << endl;
    for (int i = 0; i < n; i++)
    {
        cout << set[i] << "\t ";
    }
    cout << endl;
}


void setAdd(int* set0, int element, int n)
{
    bool isPresent = false;
    int n0 = lastFreePosSet(set0, n);

    for (int i0 = 0; i0 < n0; i0++)
    {
        if (set0[i0] == element)
        {
            isPresent = true;
            n0--;
            break;
        }
    }
    if ((!isPresent) && (n0 < n))
    {
        set0[n0] = element;
        n0 = n0 + 1;
    }
}


void sortByMax(int* arr, int n)
{
    int imax = 0;
    int max = 0;
    for (int i = 0; i < n - 1; i++)
    {
        imax = 0;
        max = arr[imax];
        for (int j = 0; j < n - i; j++)
        {
            if (max < arr[j])
            {
                imax = j;
                max = arr[imax];
            }
        }
        arr[imax] = arr[n - i - 1];
        arr[n - i - 1] = max;
    }
}
int* intersection(int* a, int* b, int m, int n, int& eleminintersection)
{
    int* c = new int[100];
    int ic = 0;
    int i = 0, j = 0;
    sortByMax(a, m);
    sortByMax(b, n);
    while (i < m && j < n)
    {
        if (a[i] < b[j])
            i++;
        else if (a[i] > b[j])
            j++;
        else
        {
            c[ic++] = a[i++];
            j++;
        }
    }
    eleminintersection = ic;
    return c;
}

int* unionofsets(int* a, int* b, int m, int n, int& eleminunion)
{
    int* c = new int[100];
    int i = 0, j = 0;
    sortByMax(a, m);
    sortByMax(b, n);
    int ic = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j]) {
            c[ic++] = a[i++];
        }
        else if (a[i] > b[j]) {
            c[ic++] = b[j++];
        }
        else
        {
            c[ic++] = a[i++];
            j++;
        }
    }
    while (i < m) {
        c[ic++] = a[i++];
    }
    while (j < n) {
        c[ic++] = b[j++];
    }
    eleminunion = ic;
    return c;
}


int* read(int& n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }
    return arr;
}

int main() {
    int n, m;
    cout << "n = ";
    cin >> n;
    int* set1;
    int* set2;
    setIn(set1, n);
    for (int i = 0; i < n; i++) {
        int num;
        cout << "num" << i << " = ";
        cin >> num;
        setAdd(set1, num, n);
    }
    cout << "m = ";
    cin >> m;
    setIn(set2, m);
    setPrn(set1, n, "set 1 is");
    for (int i = 0; i < m; i++) {
        int num;
        cout << "n" << i << " = ";
        cin >> num;
        setAdd(set2, num, m);
    }
    setPrn(set2, m, "set 2 is");
    int r = 0;
    int* setofunion = unionofsets(set1, set2, n, m, r);
    setPrn(setofunion, r, "Union of two sets");
    int* intersectionsets = intersection(set1, set2, n, m, r);
    setPrn(intersectionsets, r, "Intersection of two sets");
}