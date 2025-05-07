#include <iostream>
#include <string>

// класс одного узла односвязного списка
class Node {
public:
    int value;             
    Node* nextNode;  

    Node(int inputValue) {
        value = inputValue;     
        nextNode = nullptr;    
    }
};

// Класс самого односвязного списка
class SinglyLinkedList {
private:
    Node* firstNode;  // Указатель на начало (голову) списка

public:
    // Конструктор: создаёт пустой список
    SinglyLinkedList() {
        firstNode = nullptr; // В начале список пуст, голова указывает в никуда
    }

    // освобождает память
    ~SinglyLinkedList() {
        clear();
    }

    // Метод добавления нового значения в конец списка
    void addToEnd(int newValue) {
        Node* newNode = new Node(newValue); // Создаём новый узел с переданным значением

        if (firstNode == nullptr) {
            // Если список пустой — новый узел становится первым
            firstNode = newNode;
        } else {
            // Иначе ищем конец списка
            Node* currentNode = firstNode;          
            while (currentNode->nextNode != nullptr) {
                currentNode = currentNode->nextNode;
            }
            // дошли до последнего, связываем его с новым узлом
            currentNode->nextNode = newNode;
        }
    }

    void insertAfterSecondZero(int b1, int b2, int b3) {
        int zeroCount = 0;                    
        Node* currentNode = firstNode;        

        // Перебираем узлы списка один за другим
        while (currentNode != nullptr) {
            if (currentNode->value == 0) {
                zeroCount++;                 // Увеличиваем счётчик, если узел содержит 0

                if (zeroCount == 2) {
                    // Когда нашли второй 0 — начинаем вставку

                    // Создаём 3 новых узла с заданными значениями
                    Node* nodeB1 = new Node(b1);
                    Node* nodeB2 = new Node(b2);
                    Node* nodeB3 = new Node(b3);

                    // Устанавливаем связи: каждый указывает на следующий
                    nodeB3->nextNode = currentNode->nextNode; 
                    nodeB2->nextNode = nodeB3;                
                    nodeB1->nextNode = nodeB2;                

                    // Подключаем цепочку новых узлов после второго 0
                    currentNode->nextNode = nodeB1;

                    return;
                }
            }

            currentNode = currentNode->nextNode;
        }
        std::cout << "Error: less than two zeros found.\n";
    }

    // печать всего списка в консоль
    void printList() const {
        Node* currentNode = firstNode;  // Начинаем с головы

        while (currentNode != nullptr) {
            std::cout << currentNode->value << " "; // Печатаем значение текущего узла
            currentNode = currentNode->nextNode;    // Переходим к следующему
        }
    }

    // Метод очистки списка — освобождает всю выделенную память
    void clear() {
        Node* currentNode = firstNode; // Начинаем с головы

        // Пока есть узлы
        while (currentNode != nullptr) {
            Node* nextToDelete = currentNode->nextNode; // Запоминаем следующий узел
            delete currentNode;                         // Удаляем текущий узел
            currentNode = nextToDelete;                 // Переходим к следующему
        }

        // После очистки устанавливаем голову в nullptr
        firstNode = nullptr;
    }
};

// Функция ввода списка от пользователя
void readListFromUser(SinglyLinkedList& list) {
    std::cout << "Enter numbers (type 'q' to finish):\n";

    while (true) {
        std::string input;
        std::cin >> input; // Считываем ввод как строку

        if (input == "q")  // Если пользователь ввёл q — заканчиваем ввод
            break;

        try {
            int number = std::stoi(input); // Преобразуем строку в целое число
            list.addToEnd(number);         // Добавляем число в конец списка
        } catch (...) {
            // Если введена не цифра и не "q", выводим предупреждение
            std::cout << "Invalid input. Enter an integer or 'q'.\n";
        }
    }
}

int main() {
    SinglyLinkedList list;      // Создаём экземпляр списка
    int value1, value2, value3; 

    readListFromUser(list);    // запрос на список чисел

    std::cout << "Enter B1, B2, B3: ";
    std::cin >> value1 >> value2 >> value3;

    std::cout << "\nBefore insertion:\n";
    list.printList();

    // Выполняем вставку после второго нуля
    list.insertAfterSecondZero(value1, value2, value3);

    // Выводим список после вставки
    std::cout << "\nAfter insertion:\n";
    list.printList();

    return 0; 
}