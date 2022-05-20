#include <iostream>
using namespace std;






void graf_prn(int** matrix, int* vector, int n, const char* message)
{
    cout << "\nMatrix " << message << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < vector[i]; j++)
        {
            cout << matrix[i][j] << "\t ";
        }
        cout << endl;
    }
}



void print(const int* set, int n, const char* message)
{
    cout << "\nSet " << message << endl;
    for (int i = 0; i < n; i++)
    {
        cout << set[i] << "\t ";
    }
    cout << endl;
}















int** read_graf (int n)
{
	int** graf = new int* [] {
		new int[] {0, 1, 1, 0, 0, 0, 0, 0},
			new int[] {1, 0, 1, 1, 0, 0, 0, 0},
			new int[] {1, 1, 0, 0, 0, 0, 0, 0},
			new int[] {0, 1, 0, 0, 1, 1, 0, 0},
			new int[] {0, 0, 0, 1, 0, 1, 1, 0},
			new int[] {0, 0, 0, 1, 1, 0, 1, 1},
			new int[] {0, 0, 0, 0, 1, 1, 0, 1},
			new int[] {0, 0, 0, 0, 0, 1, 1, 0}
	};
	return graf;
}
void print_graf(int**& graf, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << graf[i][j] << '\t';
		cout << endl;
	}
}
void delete_graf(int** graf, int n)
{
    for (int i = 0; i < n; i++)
        delete[] graf[i];
    delete[] graf;
}
void transform(int**& new_graf, int*& vct, int** graf, int n) {
    new_graf = new int* [n];
    for (int i = 0; i < n; i++) {
        new_graf[i] = new int[n];
    }
    vct = new int[n];
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = 0; j < n; j++) {
            if (graf[i][j] == 1) {
                new_graf[i][s] = j;
                s += 1;
            }
        }
        vct[i] = s;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = vct[i]; j < n; j++)
        {
            new_graf[i][j] = -1;
        }
    }
}
void init(int*& set, int n)
{
    set = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        set[i] = -1;
    }
}
int last_position(const int* set, int n)
{
    int res = n;
    for (int i = 0; i < n; i++)
    {
        if (set[i] < 0)
        {
            res = i;
            break;
        }
    }
    return res;
}
int first_elem(const int* set, int n)
{
    int res = -1;
    if (n > 0)
    {
        res = set[0];
    }
    return res;
}
void add(int* set0, int elem, int n)
{
    bool bool_val = false;
    int n0 = last_position(set0, n);
    for (int i0 = 0; i0 < n0; i0++)
    {
        if (set0[i0] == elem)
        {
            bool_val = true;
            break;
        }
    }
    if ((!bool_val) && (n0 < n))
    {
        set0[n0] = elem;
        n0 += 1;
    }
}
void add(int* set0, const int* set1, int n)
{
    int n0 = last_position(set0, n);
    int n1 = last_position(set1, n);
    int* arr1 = nullptr;
    int* arr2 = nullptr;
    init(arr1, n);
    init(arr2, n);
    for (int i1 = 0; i1 < n0; i1++) {
        arr1[set0[i1]] = 1;
    }
    for (int i2 = 0; i2 < n1; i2++) {
        arr2[set1[i2]] = 1;
    }
    for (int i = 0; i < n; i++) {
        if ((arr1[i] == -1) && (arr2[i] == 1) && (n0 < n)) {
            set0[n0] = i;
            n0 = n0 + 1;
        }
    }
    delete[]arr1;
    delete[]arr2;
}
void sub(int* set0, int elem, int n)
{
    int n0 = last_position(set0, n);
    for (int i0 = 0; i0 < n0; i0++)
    {
        if (set0[i0] == elem)
        {
            for (int j = i0; j < n0; j++)
            {
                set0[j] = set0[j + 1];
            }
            n0 = n0 - 1;
            break;
        }
    }
}
void sub(int* set0, const int* set1, int n)
{
    int n0 = last_position(set0, n);
    int n1 = last_position(set1, n);
    int* arr1 = nullptr;
    int* arr2 = nullptr;
    init(arr1, n);
    init(arr2, n);
    for (int i1 = 0; i1 < n0; i1++) {
        arr1[set0[i1]] = 1;
    }
    for (int i2 = 0; i2 < n1; i2++) {
        arr2[set1[i2]] = 1;
    }
    for (int i = 0; i < n0; i++) {
        set0[i] = -1;
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        if ((arr1[i] == 1) && (arr2[i] == -1) && s < n0) {
            set0[s] = i;
            s += 1;
        }
    }
    delete[]arr1;
    delete[]arr2;
}
bool is_emp(int* set, int n)
{
    return last_position(set, n) == 0;
}
bool is_full(int* set, int n)
{
    return last_position(set, n) == n;
}
bool is_graf_union(int** graf, int* vct, int n)
{
    bool bool_val;
    int v = -1;
    int* to_do;
    int* visited;
    init(to_do, n);
    init(visited, n);
    for (int i = 0; i < n; i++)
    {
        if (vct[i] > 0)
        {
            v = i;
            break;
        }
    }
    add(to_do, v, n);
    while (!(is_emp(to_do, n)))
    {
        v = first_elem(to_do, n);
        if (v < 0)
        {
            break;
        }

        add(visited, v, n);
        add(to_do, graf[v], n);
        sub(to_do, visited, n);
    }
    bool_val = is_full(visited, n);
    delete[] to_do;
    delete[] visited;
    return bool_val;
}
bool if_graf_union(int** graf, int n) {
    bool bool_val;
    int* vct;
    int** new_graf;
    transform(new_graf, vct, graf, n);
    bool_val = is_graf_union(new_graf, vct, n);
    delete[] vct;
    delete_graf(new_graf, n);
    return bool_val;
}

void find_bridge(int** graf, int n) {
    if (!if_graf_union(graf, n)) {
        cout << "input graph isn't union" << endl;
    }
    else {
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (graf[i][j] == 1) {
                    graf[i][j] = 0;
                    graf[j][i] = 0;
                    if (!if_graf_union(graf, n)) {
                        k++;
                        cout << "bridge: " << i << " - " << j << endl;
                    }
                    graf[i][j] = 1;
                    graf[j][i] = 1;
                }
            }
        }
        if (k == 0) {
            cout << "no bridges" << endl;
        }
    }
}
int main010()
{
	int n = 8;
	int** graf = read_graf(n);
	print_graf(graf, n);
    find_bridge(graf, n);
	delete_graf(graf, n);
	return 0;
}
