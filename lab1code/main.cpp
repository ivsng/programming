#include <iostream>
#include <cmath>

void findDiagonal(int& st_a, int& st_b, int& st_c, float& dia) { //ссылаемся на значения
    dia = sqrt(pow(st_a, 2) + pow(st_b, 2) + pow(st_c, 2)); // Используем формулу для нахождения диагонали
}

int main() {
    int a, b, c;
    std::cout << "a: ";
    std::cin >> a;

    std::cout << "b: ";
    std::cin >> b;

    std::cout << "c: ";
    std::cin >> c;

    float diagonal; // Переменная для хранения результата вычисления диагонали

    // Вызываем функцию для нахождения диагонали и передаем переменную diagonal по ссылке

    findDiagonal(a, b, c, diagonal);

    // Выводим результат
    std::cout << "diagonal = ";
    std::cout.precision(2);
    std::cout << std::fixed << diagonal << std::endl;
    return 0;
}

