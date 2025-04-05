#include <iostream>
#include "include/Rectangle.h"

using namespace std;

int main() {
    double w, h, x, y;

    // Ввод параметров прямоугольника
    cout << "Enter width, height and center coordinates x y: ";
    cin >> w >> h >> x >> y;

    // Создаем объект прямоугольника
    Rectangle rect(w, h, x, y);

    int command;
    do {
        // Выводим список команд
        cout << "********************\n";
        cout << "Choose a command:\n";
        cout << "1. Show parameters\n";
        cout << "2. Check if crosses X-axis\n";
        cout << "3. Check if crosses Y-axis\n";
        cout << "4. Check if point is on boundary\n";
        cout << "5. Calculate perimeter\n";
        cout << "6. Show vertices\n";
        cout << "7. Enter a new rectangle\n";
        cout << "8. End\n";
        cout << "Enter command number: ";
        cin >> command;
        cout << "********************\n";

        switch (command) {
            case 1:
                // Выводим параметры прямоугольника
                rect.printInfo();
                break;
            case 2:
                // Проверка пересечения с осью X
                cout << "Crosses X-axis? " << (rect.crossesXAxis() ? "Yes" : "No") << endl;
                break;
            case 3:
                // Проверка пересечения с осью Y
                cout << "Crosses Y-axis? " << (rect.crossesYAxis() ? "Yes" : "No") << endl;
                break;
            case 4: {
                // Проверка, принадлежит ли точка границе прямоугольника
                double px, py;
                cout << "Enter point coordinates (px py): ";
                cin >> px >> py;
                cout << "Point on boundary? " << (rect.isPointOnBoundary(px, py) ? "Yes" : "No") << endl;
                break;
            }
            case 5:
                // Подсчет периметра
                cout << "Perimeter: " << rect.calculatePerimeter() << endl;
                break;
            case 6:
                // Вывод координат вершин
                rect.printVertices();
                break;
            case 7:
                // Ввод нового прямоугольника
                cout << "Enter width, height and center coordinates (x y): ";
                cin >> w >> h >> x >> y;
                rect = Rectangle(w, h, x, y);  // Создаем новый прямоугольник
                break;
            case 8:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid command. Please try again.\n";
        }
    } while (command != 8);

    return 0;
}