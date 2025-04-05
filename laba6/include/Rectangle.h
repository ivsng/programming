#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
    double width, height;    // Ширина и высота прямоугольника
    double centerX, centerY; // Координаты центра прямоугольника

public:
    // Конструктор для инициализации прямоугольника
    Rectangle(double w, double h, double x, double y);

    // Метод для вывода информации о прямоугольнике
    void printInfo();

    // Метод для проверки пересечения с осью X
    bool crossesXAxis();

    // Метод для проверки пересечения с осью Y
    bool crossesYAxis();

    // Метод для проверки, принадлежит ли точка границе прямоугольника
    bool isPointOnBoundary(double px, double py);

    // Метод для подсчета периметра прямоугольника
    double calculatePerimeter();

    // Метод для вывода координат вершин прямоугольника
    void printVertices();
};

#endif // RECTANGLE_H