#include<iostream>
using namespace std;
int main3()
{
	

	long long a, sum, mult = 1, d = 0;
	cout << "Enter a = ";
	cin >> a;

	for (int i = 1; d < a; i++) {
		sum = 0;
		for (int j = 0; j < i && d < a; j++)
		{
			sum += ++d;
		}
		mult *= sum;

	}

	cout << "Result = " << mult << endl;

	//b s=1+(1*2)+(1*2*3)+⋯+(1*2*…*n); 

	long long a, sum=0, mult;

	cout << "Enter a = ";
	cin >> a;
	
	for (int i = 1; i <= a; i++) {
		mult = 1;
		for (int j = 1; j <= i; j++)
		{
			mult *= j;
		}
		sum += mult;
	}

	cout << "Result = " << sum << endl;


	return 0;
	system("pause");
}