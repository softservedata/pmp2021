#include <iostream>
using namespace std;

class Employee
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

	/*
	friend ostream& operator<<(ostream& out, const Employee& date)
	{
		out << "\nEmployee: name = " << date.name << ", id = " << date.id << endl;
		return out;
	}
	*/

	/*int compareTo(Comparable* e)
	{
		return 0;
		return this->getId() > ((Employee*)e)->getId();
	}*/
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

	Employee getMax(Employee* arr, int n)
	{
		Employee result = arr[0];
		for (int i = 0; i < n; i++)
		{
			//if (result < arr[i])
			{
				result = arr[i];
			}
		}
		return result;
	}
};

int main()
{
	Operation* operation = new Operation();
	//
	int n = 6;
	//int* arr = new int[] { 6, 3, 8, 2, 9, 1 };
	Employee** arr = new Employee*[] { new Employee("Ivan", 4), new Employee("Petro", 2) };
	//
	//
	cout << "Original Array:  ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i]->toString() << "  ";
	}
	cout << endl;
	//
	//cout << "max = " << operation->getMax(arr, n) << endl;
	//
	for (int i = 0; i < n; i++)
	{
		delete arr[i];
	}
	//
	delete[] arr;
	delete operation;
	//
	cout << "done" << endl;
	system("pause");
	return 0;
}
