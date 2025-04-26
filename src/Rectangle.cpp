#include <iostream>
#include "Rectangle.h"

using namespace std;

// Конструктор базового класса
Rectangle::Rectangle(double w, double h, double x, double y) {
    width = w;
    height = h;
    centerX = x;
    centerY = y;
}

// Вывод информации о прямоугольнике
void Rectangle::printInfo() {
    cout << "Rectangle: " << width << " x " << height << endl;
    cout << "Center: (" << centerX << ", " << centerY << ")" << endl;
}

// Проверка пересечения с осью X
bool Rectangle::crossesXAxis() {
    return (centerY - height / 2 <= 0 && centerY + height / 2 >= 0);
}

// Проверка пересечения с осью Y
bool Rectangle::crossesYAxis() {
    return (centerX - width / 2 <= 0 && centerX + width / 2 >= 0);
}

// Проверка принадлежности точки границе
bool Rectangle::isPointOnBoundary(double px, double py) {
    double halfWidth = width / 2;
    double halfHeight = height / 2;

    return (px == centerX - halfWidth || px == centerX + halfWidth) && (py >= centerY - halfHeight && py <= centerY + halfHeight) ||
           (py == centerY - halfHeight || py == centerY + halfHeight) && (px >= centerX - halfWidth && px <= centerX + halfWidth);
}

// Расчет периметра
double Rectangle::calculatePerimeter() {
    return 2 * (width + height);
}

// Вывод координат всех четырёх вершин
void Rectangle::printVertices() {
    double halfWidth = width / 2;
    double halfHeight = height / 2;

    cout << "Vertices of the rectangle:" << endl;
    cout << "1. (" << centerX - halfWidth << ", " << centerY - halfHeight << ")" << endl;
    cout << "2. (" << centerX + halfWidth << ", " << centerY - halfHeight << ")" << endl;
    cout << "3. (" << centerX - halfWidth << ", " << centerY + halfHeight << ")" << endl;
    cout << "4. (" << centerX + halfWidth << ", " << centerY + halfHeight << ")" << endl;
}

// Геттеры/сеттер для центра (используются в производном классе)
double Rectangle::getCenterX() const { return centerX; }
double Rectangle::getCenterY() const { return centerY; }
void Rectangle::setCenter(double x, double y) {
    centerX = x;
    centerY = y;
}