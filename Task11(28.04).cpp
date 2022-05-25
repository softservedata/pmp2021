#include <iostream>
using namespace std;

// Написати методи для об’єднання та перетину множин. 
// Реалізувати алгоритми зі складністю O(n). 


int setWithLastPosition(const int* set, int n)
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

void sorting(int*& a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				int buf = a[j];
				a[j] = a[j + 1];
				a[j + 1] = buf;
			}
		}
	}
}

void setInitialisation(int*& set, int n)
{
	set = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		set[i] = -1;
	}
}

void setAdding(int*& set0, int element, int n)
{
	bool isPresent = false;
	int n0 = setWithLastPosition(set0, n);

	for (int i0 = 0; i0 < n0; i0++)
	{
		if (set0[i0] == element)
		{
			isPresent = true;
			return;
		}
	}
	if ((!isPresent) && (n0 < n))
	{

		set0[n0] = element;
		n0 = n0 + 1;
		sorting(set0, n);
	}
}

void setPrinting(const int* set, int n, const char* message)
{
	cout << "\nSet " << message << endl;
	int p = setWithLastPosition(set, n);
	for (int i = 0; i < p; i++)
	{
		cout << set[i] << "\t ";
	}
	cout << endl;
}

void setUnification(int* a, int n1, int* b, int n2, int*& c, int& n3)
{
	c = new int[n1 + n2];
	for (int i = 0; i < n1 + n2; i++)
	{
		c[i] = -1;
	}
	int p1 = setWithLastPosition(a, n1);
	int p2 = setWithLastPosition(b, n2);
	int i1 = 0;
	int j1 = 0;
	int i = 1;
	n3 = n1 + n2;
	if (a[0] > b[0])
	{
		c[0] = a[0];
		i1++;
	}
	else
	{
		c[0] = b[0];
		j1++;
	}
	while (i1 < p1 && j1 < p2)
	{
		if (a[i1] >= b[j1])
		{
			if (a[i1] != c[i - 1])
			{
				c[i] = a[i1];
				i++;
			}
			i1++;
		}
		else
		{
			if (b[j1] != c[i - 1])
			{
				c[i] = b[j1];
				i++;
			}
			j1++;
		}
	}
	if (i1 < p1)
	{
		if (a[i1] == c[i - 1])
		{
			i1++;
		}
		for (int k = i1; k < p1; k++)
		{
			c[i] = a[k];
			i++;
		}
	}
	else
	{
		if (b[j1] == c[i - 1])
		{
			j1++;
		}
		for (int k = j1; k < p2; k++)
		{
			c[i] = b[k];
			i++;
		}
	}
	for (int k = i; k < n3; k++)
	{
		c[k] = -1;
	}
}

void intersection(int* a, int n1, int* b, int n2, int*& c, int& n3)
{
	int nMax = n1 < n2 ? n1 : n2;
	c = new int[nMax];
	n3 = 0;
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			if (a[i] == b[j])
			{
				c[n3] = a[i];
				n3++;
				break;
			}
		}
	}
}

int main()
{

	int* a;
	int n1 = 5;
	setInitialisation(a, n1);
	setAdding(a, 7, n1);
	setAdding(a, 7, n1);
	setAdding(a, 5, n1);
	setAdding(a, 4, n1);
	setAdding(a, 1, n1);
	setAdding(a, 8, n1);


	int* b;
	int n2 = 3;
	setInitialisation(b, n2);
	setAdding(b, 5, n2);
	setAdding(b, 3, n2);
	setAdding(b, 1, n2);


	setPrinting(a, n1, "First set");
	setPrinting(b, n2, "Second set");


	int* u;
	int uSize = 0;
	setUnification(a, n1, b, n2, u, uSize);
	setPrinting(u, uSize, "Union");


	int* per;
	int perSize;
	intersection(a, n1, b, n2, per, perSize);
	setPrinting(per, perSize, "Inersection");

	return 0;