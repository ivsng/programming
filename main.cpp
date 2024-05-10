#include <iostream>

// Функция для чтения матрицы с клавиатуры
void readMatrix(int matrix[4][5]) {
    std::cout << "enter matrix 4*5:\n"; 
    for (int i = 0; i < 4; ++i) { // Перебор строк 
        for (int j = 0; j < 5; ++j) { // Перебор элементов в строке
            std::cin >> matrix[i][j];
        }
    }
}

// Функция для вывода матрицы в консоль
void printMatrix(const int matrix[4][5]) { 
    for (int i = 0; i < 4; ++i) { 
        for (int j = 0; j < 5; ++j) { 
            std::cout << matrix[i][j] << " ";//"\t"; 
        }
        std::cout << std::endl; 
    }
}

// Функция для обработки матрицы и массива B
void processMatrix(int matrix[4][5], int result[]) {
    int product, count; // Переменная для хранения произведения и счетчик до первого нулевого
    for (int i = 0; i < 4; ++i) { // Перебор строк матрицы
        if (matrix[i][0] == 0) { // Если 1й элемент строки 0, то произведение элементов до нулевого тоже 0
            product = 0;
            count = 0;
        }
        else{
            product = 1; 
            count = 0; 
        }
        for (int j = 0; j < 5; ++j) { 
            if (matrix[i][j] == 0) { // Если ноль
                matrix[i][j] = count; // Заменяем на счетччик
                break; // Завершение обработки этой строки
            }
            product *= matrix[i][j]; 
            ++count; // Увеличение счетчика
        }
        result[i] = product; // Записываем произведение элементов до нуля в массив B
    }
}

// Функция для вывода массива B
void printArray(const int array[], int size) {
    std::cout << "array B:\n"; // Заголовок для вывода массива B
    for (int i = 0; i < size; ++i) { // Перебор элементов массива B
        std::cout << array[i] << " "; // Вывод элемента массива B в консоль
    }
    std::cout << std::endl; // Переход на новую строку после вывода массива
}

int main() {
    int matrix[4][5]; // Массив для хранения матрицы
    int result[4]; // Произведения элементов до первого нуля в каждой строке

    readMatrix(matrix);

    std::cout << "original matrix:\n";
    printMatrix(matrix);

    processMatrix(matrix, result);

    std::cout << "final matrix:\n";
    printMatrix(matrix);

    printArray(result, 4);

    return 0; 
}
