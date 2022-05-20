#include <iostream>

int main() {
    int n, a;
    std::cout << "enter matrix size, n:";
    std::cin >> n;
    int * matrix[n][n];

    std::cout << "Enter Elements of Matrix: " << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "matrix element[" << i << "][" << j << "]: ";
            std::cin >> *matrix[i][j];
        }
    }
    std::cout << "Your matrix" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i=0; i < n; i++) {
        for (int j=i+1; j < n; j++)
            if (matrix [i][0] > matrix [j][0]){
                for (int k=0; k<n;k++){
                    int * t = matrix[i][k];
                    matrix[i][k] = matrix[j][k];
                    matrix[j][k] = t;
                }
            }
    }

    std::cout << "\nYour result" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
