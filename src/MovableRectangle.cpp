#include "MovableRectangle.h"

// Конструктор: сохраняем исходное положение и передаем параметры базовому классу
MovableRectangle::MovableRectangle(double w, double h, double x, double y)
    : Rectangle(w, h, x, y), originalX(x), originalY(y) {}

// Переместить прямоугольник в новую точку
void MovableRectangle::moveTo(double newX, double newY) {
    setCenter(newX, newY);
}

// Сместить на dx, dy
void MovableRectangle::moveBy(double dx, double dy) {
    setCenter(getCenterX() + dx, getCenterY() + dy);
}

// Вернуть прямоугольник в начальное положение
void MovableRectangle::reset() {
    setCenter(originalX, originalY);
}