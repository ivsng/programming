#ifndef MOVABLERECTANGLE_H
#define MOVABLERECTANGLE_H

#include "Rectangle.h"

// Производный класс: добавляет возможность перемещать и сбрасывать положение
class MovableRectangle : public Rectangle {
private:
    double originalX, originalY; // Сохраняем изначальное положение центра

public:
    MovableRectangle(double w, double h, double x, double y); // Конструктор

    void moveTo(double newX, double newY); // Переместить в новую точку
    void moveBy(double dx, double dy);     // Сместить на dx/dy
    void reset();                          // Сброс в начальное положение
};

#endif // MOVABLERECTANGLE_H