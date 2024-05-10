#include <iostream>

// Функция для чтения массива с клавиатуры
void readArray(int array[]) {
    std::cout << "enter 10 elements:\n";
    for (int i = 0; i < 10; ++i) {
        std::cin >> array[i]; // Считываем элементы массива и сохраняем их в памяти
    }
}

// Функция для нахождения индекса максимального элемента в массиве
int findMaxIndex(int array[]) {
    int maxIndex = 0;
    for (int i = 1; i < 10; ++i) {
        if (array[i] > array[maxIndex]) {
            maxIndex = i; // Находим индекс максимального элемента в массиве
        }
    }
    return maxIndex;
}

// Функция для удаления максимального элемента из массива
void removeMaxElement(int array[], int& size, int maxIndex) {
    for (int i = maxIndex; i < size - 1; ++i) {
        array[i] = array[i + 1]; // Сдвигаем элементы влево, чтобы заменить максимальный элемент
    }
    size--; // Уменьшаем размер массива после удаления элемента
}

// Функция для вывода массива в консоль
void printArray(const int array[], int size) {
    std::cout << "final array:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " "; // Выводим элементы массива после удаления максимального элемента
    }
    std::cout << std::endl;
}

int main() {
    int array[10];
    int size = 10;

    readArray(array); // Вызываем функцию для чтения массива

    int maxIndex = findMaxIndex(array); // Находим индекс максимального элемента
    removeMaxElement(array, size, maxIndex); // Удаляем максимальный элемент из массива

    printArray(array, size); // Выводим измененный массив

    return 0;
}