#include <iostream>
using namespace std;

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
void mosty_grafa(int** graf, int n)
{
	int count;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			if (graf[i][j] == 1){
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
int main010()
{
	int n = 8;
	int** graf = read_graf(n);
	print_graf(graf, n);
	mosty_grafa(graf, n);
	delete_graf(graf, n);
	return 0;
}