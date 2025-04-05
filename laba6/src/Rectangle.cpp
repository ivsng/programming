#include <iostream>
#include "Rectangle.h"

using namespace std;

// Конструктор инициализирует параметры прямоугольника
Rectangle::Rectangle(double w, double h, double x, double y) {
    width = w;
    height = h;
    centerX = x;
    centerY = y;
}

// Метод для вывода информации о прямоугольнике
void Rectangle::printInfo() {
    cout << "Rectangle: " << width << " x " << height << endl;
    cout << "Center: (" << centerX << ", " << centerY << ")" << endl;
}

// Метод для проверки, пересекает ли прямоугольник ось X
bool Rectangle::crossesXAxis() {
    return (centerY - height / 2 <= 0 && centerY + height / 2 >= 0); // Проверка по оси Y
}

// Метод для проверки, пересекает ли прямоугольник ось Y
bool Rectangle::crossesYAxis() {
    return (centerX - width / 2 <= 0 && centerX + width / 2 >= 0); // Проверка по оси X
}

// Метод для проверки, принадлежит ли точка границе прямоугольника
bool Rectangle::isPointOnBoundary(double px, double py) {
    double halfWidth = width / 2;
    double halfHeight = height / 2;

    // Проверка принадлежности точки границе прямоугольника
    return (px == centerX - halfWidth || px == centerX + halfWidth) && (py >= centerY - halfHeight && py <= centerY + halfHeight) ||
           (py == centerY - halfHeight || py == centerY + halfHeight) && (px >= centerX - halfWidth && px <= centerX + halfWidth);
}

// Метод для подсчета периметра прямоугольника
double Rectangle::calculatePerimeter() {
    return 2 * (width + height); // Формула периметра прямоугольника
}

// Метод для вывода координат вершин прямоугольника
void Rectangle::printVertices() {
    double halfWidth = width / 2;
    double halfHeight = height / 2;

    cout << "Vertices of the rectangle:" << endl;
    cout << "1. (" << centerX - halfWidth << ", " << centerY - halfHeight << ")" << endl;  // Левый нижний угол
    cout << "2. (" << centerX + halfWidth << ", " << centerY - halfHeight << ")" << endl;  // Правый нижний угол
    cout << "3. (" << centerX - halfWidth << ", " << centerY + halfHeight << ")" << endl;  // Левый верхний угол
    cout << "4. (" << centerX + halfWidth << ", " << centerY + halfHeight << ")" << endl;  // Правый верхний угол
}