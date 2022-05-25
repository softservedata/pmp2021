
#include <iostream>

using namespace std;

// Прочитати матриці A та B розміром n´n. Обчислити величину (A – B)^2. 
// Прочитати дійсну матрицю розміром n´n.
// Вияснити, чи задана матриця володіє діагональною перевагою(діагональні елементи по модулю переважають інших у своїх стрічці).

int** formingOfMatrix (int k) 
{
    int** matrix = new int* [k];
    for (int i = 0; i < k; ++i) {
        matrix[i] = new int[k] {};
    }
    return matrix;
}

void reading (int** matrix, int k) 
{ 
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> matrix[i][j];
        }
    }
}

int** printing (int** matrix, int k) 
{
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int** subtraction (int**& matrixA, int**& matrixB, int& k) 
{
    int** temporaryVar = new int* [k];
    for (int i = 0; i < k; i++) {
        temporaryVar[i] = new int[k];
        for (int j = 0; j < k; j++) {
            temporaryVar[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return temporaryVar;
}


int** toSquare (int**& matrix, int& k) 
{
    int** temporaryVar = new int* [k];
    for (int i = 0; i < k; i++) {
        temporaryVar[i] = new int[k];
        for (int j = 0; j < k; j++) {
            temporaryVar[i][j] = 0;
            for (int n = 0; n < k; n++)
                temporaryVar[i][j] += matrix[i][n] * matrix[n][j];
        }
    }
    return temporaryVar;
}

int** removing (int**& matrix, int k) 
{ 
    for (int i = 0; i < k; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

bool diagonalAdvantage(int** matrix, int& m) 
{
    int diagonal = 0;
    for (int i = 0; i < m; i++) {
        diagonal = matrix[i][i];
        for (int j = 0; j < m; j++) {
            if (abs(diagonal) < matrix[i][j]) 
                return false;
        }
    }
    return true;
}

int main() 
{
    int size;
    cout << "Enter size of matrix: ";
    cin >> size;
    int** firstMatrix = formingOfMatrix(size), ** secondMatrix = formingOfMatrix(size);

    cout << "Enter elements of first matrix : " << endl;
    reading(firstMatrix, size);
    cout << "Enter elements of second matrix : " << endl;
    reading(secondMatrix, size);

    int** C = subtraction(firstMatrix, secondMatrix, size);
    int** Result = toSquare(C, size);
    cout << "\nResult is : " << endl;

    printing(Result, size);
    removing(secondMatrix, size);
    removing(C, size);
    removing(Result, size);
    removing(firstMatrix, size);


    cout << "Now you can check if this matrix have diagonal advantage" << endl;

    int size;
    cout << "So,enter size value: ";
    cin >> size;
    int** matrix = formingOfMatrix(size);
    cout << "Now,enter elements of this matrix " << endl;
    reading(matrix, size);

    if (diagonalAdvantage(matrix, size)) 
    {
        cout << "This matrix have diagonal advantage" << endl;
    }
    else 
    {
        cout << "This matrix dont have diagonal advantage" << endl;
    }

    removing(matrix, size);
}
