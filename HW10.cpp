#include <iostream>
using namespace std;

int** grafr(int n)
{
	int** graf = new int* [] {
		new int[] {0, 2, 0, 0, 0},
			new int[] {2, 0, 1, 0, 0},
			new int[] {0, 1, 0, 3, 0},
			new int[] {0, 0, 2, 0, 1},
			new int[] {1, 0, 0, 1, 0},
	};
	return graf;
}
void print(int**& graf, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << graf[i][j] << '\t';
		cout << endl;
	}
}
void find(int** graf, int n)
{
	int count;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graf[i][j] == 1) {
				graf[i][j] = 0;
				graf[j][i] = 0;
				count = 0;
				for (int k = 0; k < n; k++) {
					if (graf[i][k] == 0) {
						count++;
					}
				}
				if (count != n) {
					graf[i][j] = 1;
					graf[j][i] = 1;
				}
				else cout << "i=" << i << ", " << "j=" << j << endl;

			}

		}
	}
	cout << "no";
}
void delete_graf(int** graf, int n)
{
	for (int i = 0; i < n; i++)
		delete[] graf[i];
	delete[] graf;
}
int main10()
{
	int n = 5;
	int** graf = grafr(n);
	print(graf, n);
	find(graf, n);
	delete_graf(graf, n);
	return 0;
}