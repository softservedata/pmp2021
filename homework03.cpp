#include<iostream>
using namespace std;
int main3()
{
	//a s = 1*(2+3)*(4+5+6)*...*(...+n)

	long long n, sum, mult = 1, d = 0;
	cout << "Enter n = ";
	cin >> n;

	for (int i = 1; d < n; i++) {
		sum = 0;
		for (int j = 0; j < i && d < n; j++)
		{
			sum += ++d;
		}
		mult *= sum;

	}

	cout << "Result = " << mult << endl;

	//b s=1+(1*2)+(1*2*3)+⋯+(1*2*…*n); 

	long long n, sum=0, mult;

	cout << "Enter n = ";
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
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