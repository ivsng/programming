#ifndef RECTANGLE_H
#define RECTANGLE_H

// Базовый класс, описывающий прямоугольник
class Rectangle {
private:
    double width, height;    // Размеры прямоугольника
    double centerX, centerY; // Координаты центра

public:
    Rectangle(double w, double h, double x, double y);  // Конструктор

    void printInfo();                      // Вывод параметров
    bool crossesXAxis();                   // Пересекает ось X?
    bool crossesYAxis();                   // Пересекает ось Y?
    bool isPointOnBoundary(double px, double py); // Точка на границе?
    double calculatePerimeter();           // Подсчет периметра
    void printVertices();                  // Вывод вершин

    double getCenterX() const;             // Геттер X
    double getCenterY() const;             // Геттер Y
    void setCenter(double x, double y);    // Сеттер центра
};

#endif // RECTANGLE_H