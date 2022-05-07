#include<iostream>
using namespace std;

struct Person
{
	int id;
	string name;
	//
	Person(int id, string name)
	{
		this->id = id;
		this->name = name;
	}
};

void personsCreate(Person**& persons, int& n)
{
	persons = new Person* [] {
			new Person(123, "e"),
			new Person(126, "g"),
			new Person(223, "b"),
			new Person(103, "d"),
			new Person(333, "f"),
			new Person(563, "ibc"),
			new Person(763, "c"),
			new Person(893, "h"),
			new Person(413, "ab"),
	};
	n = 9;
}

void personsDelete(void* elements)
{
	delete[] elements;
}

void personPrint(Person* person, const char* message)
{
	cout << "\nPerson " << message << endl;
	if (person != NULL)
	{
		cout << "id = " << person->id << "  name = " << person->name << endl;
	}
	else
	{
		cout << "Person not found" << endl;
	}
}

void personsPrint(Person** persons, int n, const char* message)
{
	cout << "\nPerson " << message << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "id = " << persons[i]->id << "  name = " << persons[i]->name << endl;
	}
}

void arrayPrint(int* arr, int n, const char* message)
{
	cout << "\nArray " << message << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t ";
	}
	cout << endl;
}

int* personsHashNameFirst(Person** persons, int n)
{
	int* hash = new int[n];
	string current;
	//
	for (int i = 0; i < n; i++)
	{
		current = persons[i]->name;
		hash[i] = current.empty() ? 0 : (int)current[0];
	}
	return hash;
}

// sortByBubble
int* personsIndex(int* arr, int n)
{
	int temp;
	bool isSorted = false;
	int* index = new int[n];
	//
	for (int i = 0; i < n; i++)
	{
		index[i] = i;
	}
	//
	for (int i = 0; !isSorted && (i < n - 1); i++)
	{
		isSorted = true;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				isSorted = false;
				//
				temp = index[j];
				index[j] = index[j + 1];
				index[j + 1] = temp;
			}
		}
	}
	return index;
}

Person* personsSearchByName(Person** persons, int* nameIndex, int n, const string name)
{
	Person* person = NULL;
	int posBegin = 0;
	int posEnd = n - 1;
	int avg = -1;
	//
	do {
		avg = (int)((posBegin + posEnd) / 2);
		//
		cout << "\nposBegin = " << posBegin << "  posEnd = " << posEnd <<	"  avg = " << avg << endl;
		personPrint(persons[nameIndex[avg]], "Current persons[nameIndex[avg]]");
		system("pause");
		//
		if (name == persons[nameIndex[avg]]->name)
		{
			person = persons[nameIndex[avg]];
			break;
		}
		else if (name  < persons[nameIndex[avg]]->name)
		{
			posEnd = avg - 1;
		}
		else
		{
			posBegin = avg + 1;
		}
	} while (posBegin <= posEnd);
	return person;
}

int main10al()
{
	int n = 0;
	Person** persons = NULL;
	int* hash = NULL;
	int* index = NULL;
	Person* SearchResult = NULL;
	//
	personsCreate(persons, n);
	personsPrint(persons, n, "Original");
	//
	hash = personsHashNameFirst(persons,n);
	arrayPrint(hash, n, "Original hash");
	//
	index = personsIndex(hash, n);
	arrayPrint(index, n, "index");
	//
	//SearchResult = personsSearchByName(persons, index, n, "ab");
	//SearchResult = personsSearchByName(persons, index, n, "f");
	SearchResult = personsSearchByName(persons, index, n, "j");
	//SearchResult = personsSearchByName(persons, index, n, "bb");
	personPrint(SearchResult, "SearchResult");
	//
	personsDelete(index);
	personsDelete(hash);
	personsDelete(persons);
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}