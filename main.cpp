#include <iostream>

using namespace std;

/**
  * @brief Читает матрицу
  * @param matrix матрица которая будет заполнена
  * @param rows количество рядов
  * @param cols кол-во столбцов
*/
void readMatrix(int** matrix, int rows, int cols) {
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

/**
  * @brief Нахождение суммы элементов
  * @param rows количество рядов
  * @param cols кол-во столбцов
  * @return сумма строки матрицы
*/
int rowSum(int* row, int cols) {
    int sum = 0;
    for (int i = 0; i < cols; i++) {
        sum += row[i];
    }
    return sum;
}

/**
  * @brief Обмен местами 2х строк
  * @param a первая строка
  * @param b вторая строка
*/
void swap(int*& a, int*& b) {
    int* temp = a;
    a = b;
    b = temp;
}

/**
  * @brief Сортировка матрицы основываясь на сумме
  * @param matrix матрица
  * @param rows количество рядов
  * @param cols кол-во столбцов
*/
void sortRows(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            if (rowSum(matrix[j], cols) > rowSum(matrix[j + 1], cols)) {
                swap(matrix[j], matrix[j + 1]);
            }
        }
    }
}

/**
  * @brief Вывод матрицы на экран
  * @param matrix матрица
  * @param rows количество рядов
  * @param cols кол-во столбцов
*/
void displayMatrix(int** matrix, int rows, int cols) {
    cout << "Sorted matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;

    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    // Выделение памяти под матрицу
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    readMatrix(matrix, rows, cols);

    sortRows(matrix, rows, cols);

    displayMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}