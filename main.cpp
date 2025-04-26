#include <iostream>
#include "include/MovableRectangle.h"  // Подключение заголовка производного класса

using namespace std;

int main() {
    // Переменные для параметров прямоугольника
    double w, h, x, y;

    // Ввод начальных параметров прямоугольника
    cout << "Enter width, height and center coordinates x y: ";
    cin >> w >> h >> x >> y;

    // Создание объекта производного класса
    MovableRectangle rect(w, h, x, y);

    int command;
    do {
        // Меню команд для пользователя
        cout << "\n********************\n";
        cout << "Choose a command:\n";
        cout << "1. Show parameters\n";
        cout << "2. Check if crosses X-axis\n";
        cout << "3. Check if crosses Y-axis\n";
        cout << "4. Check if point is on boundary\n";
        cout << "5. Calculate perimeter\n";
        cout << "6. Show vertices\n";
        cout << "7. Move to new center\n";
        cout << "8. Move by dx, dy\n";
        cout << "9. Reset to original position\n";
        cout << "10. End\n";
        cout << "Enter command number: ";
        cin >> command;
        cout << "********************\n";

        // Обработка команды
        switch (command) {
            case 1:  rect.printInfo(); break;
            case 2:  cout << "Crosses X-axis? " << (rect.crossesXAxis() ? "Yes" : "No") << endl; break;
            case 3:  cout << "Crosses Y-axis? " << (rect.crossesYAxis() ? "Yes" : "No") << endl; break;
            case 4: {
                double px, py;
                cout << "Enter point (px py): ";
                cin >> px >> py;
                cout << "Point on boundary? " << (rect.isPointOnBoundary(px, py) ? "Yes" : "No") << endl;
                break;
            }
            case 5:  cout << "Perimeter: " << rect.calculatePerimeter() << endl; break;
            case 6:  rect.printVertices(); break;
            case 7: {
                double newX, newY;
                cout << "Enter new center (x y): ";
                cin >> newX >> newY;
                rect.moveTo(newX, newY);
                break;
            }
            case 8: {
                double dx, dy;
                cout << "Enter dx and dy: ";
                cin >> dx >> dy;
                rect.moveBy(dx, dy);
                break;
            }
            case 9:  rect.reset(); break;
            case 10: cout << "Exiting...\n"; break;
            default: cout << "Invalid command.\n";
        }
    } while (command != 10);

    return 0;
}