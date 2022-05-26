#include<iostream>
using namespace std;


int main()
{
	/*
	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 5; j++) {
			if (j == i) {
				continue;
			}
			for (int k = 1; k < 5; k++) {
				if ((k == i) || (k == j)) {
					continue;
				}
				for (int l = 1; l < 5; l++) {
					if ((l == i) || (l == j) || (l == k)) {
						continue;
					}
					cout << i << " " << j << " " << k << " " << l << endl;
				}
			}
		}
	}
	*/
	//
	int n = 4;
	char* arr = new char[] { 'a', 'b', 'c', 'd' };
	int* idx = new int[n];
	//
	for (idx[0] = 0; idx[0] < n; idx[0]++) {
		for (idx[1] = 0; idx[1] < n; idx[1]++) {
			if (idx[1] == idx[0]) {
				continue;
			}
			for (idx[2] = 0; idx[2] < n; idx[2]++) {
				if ((idx[2] == idx[0]) || (idx[2] == idx[1])) {
					continue;
				}
				for (idx[3] = 0; idx[3] < n; idx[3]++) {
					if ((idx[3] == idx[0]) || (idx[3] == idx[1]) || (idx[3] == idx[2])) {
						continue;
					}
					for (int i = 0; i < n; i++) {
						cout << arr[idx[i]] << " ";
					}
					cout << endl;
				}
			}
		}
	}
	//
	cout << "\ndone" << endl;
	system("pause");
	return 0;
}