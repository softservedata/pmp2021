#include <iostream>
using namespace std;

class Comparable
{
public:
	virtual int compareTo(Comparable*) = 0;
	virtual string toString() = 0;
};

class Employee : public Comparable
{
private:
	string name;
	int id;

public:
	Employee(string name = "", int id = 0)
	{
		this->name = name;
		this->id = id;
		cout << "constructor Employee() done" << endl;
	}

	virtual ~Employee()
	{
		cout << "destructor ~Employee() done" << endl;
	}

	string getName()
	{
		return name;
	}

	int getId()
	{
		return id;
	}

	string toString()
	{
		return "\nEmployee: name = " + getName() + ", id = " + (char)(getId() + 48);
	}

	bool operator<(Employee* other)
	{
		return this->id < other->id;
	}

	static bool predicate(Employee* first, Employee* second)
	{
		cout << "\t\t\t static bool predicate() done, first->id = " << first->id << "  second->id = " << second->id << endl;
		return first->id > second->id;
	}

	/*
	friend ostream& operator<<(ostream& out, const Employee& date)
	{
		out << "\nEmployee: name = " << date.name << ", id = " << date.id << endl;
		return out;
	}
	*/

	int compareTo(Comparable* e) // return + if this > e; - if this < e; 0 if this == e
	{
		//return 0;
		//return this->getId() > ((Employee*)e)->getId();
		return this->getId() - ((Employee*)e)->getId();
	}
};


class Operation
{
public:
	Operation()
	{
		cout << "\tconstructor Operation() done" << endl;
	}

	virtual ~Operation()
	{
		cout << "\tdestructor ~Operation() done" << endl;
	}

	int getMax(int* arr, int n)
	{
		int result = arr[0];
		for (int i = 0; i < n; i++)
		{
			if (result < arr[i])
			{
				result = arr[i];
			}
		}
		return result;
	}

	Employee* getMax(Employee** arr, int n)
	{
		cout << "\t\tEmployee* getMax(Employee** arr, int n)" << endl;
		Employee* result = arr[0];
		for (int i = 0; i < n; i++)
		{
			if (*result < arr[i])
			//if (result->operator<())
			{
				result = arr[i];
			}
		}
		return result;
	}

	Comparable* getMax(Comparable** arr, int n)
	{
		cout << "\t\tComparable* getMax(Comparable** arr, int n)" << endl;
		Comparable* result = arr[0];
		for (int i = 0; i < n; i++)
		{
			if (result->compareTo(arr[i]) < 0)
			{
				result = arr[i];
			}
		}
		return result;
	}

	Employee* getMax(Employee** arr, int n, bool(*comp)(Employee*, Employee*))  //  bool(*comp)(Employee*, Employee*) ret true if par1>par2;
	{
		cout << "\t\tEmployee* getMax(Employee** arr, int n, bool(*comp)(Employee*, Employee*))" << endl;
		Employee* result = arr[0];
		for (int i = 0; i < n; i++)
		{
			if (!comp(result, arr[i]))
			{
				result = arr[i];
			}
		}
		return result;
	}

};

int main04()
{
	//
	Operation* operation = new Operation();
	//
	int n = 4;
	//int* arr = new int[] { 6, 3, 8, 2, 9, 1 };
	Employee** arr = new Employee*[] { new Employee("Ivan", 4), new Employee("Petro", 2), new Employee("Stepan",5), new Employee("Ira", 3) };
	//Comparable** arr = new Comparable*[] { new Employee("Ivan", 4), new Employee("Petro", 2), new Employee("Stepan",5), new Employee("Ira", 3) };
	//
	cout << "Original Array:  ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i]->toString() << endl;
	}
	cout << endl;
	//
	//cout << "max = " << operation->getMax(arr, n)->toString() << endl;
	cout << "max = " << operation->getMax(arr, n, Employee::predicate)->toString() << endl;
	//
	for (int i = 0; i < n; i++)
	{
		delete arr[i];
	}
	//
	delete[] arr;
	delete operation;
	//

	//
	cout << "done" << endl;
	system("pause");
	return 0;
}
