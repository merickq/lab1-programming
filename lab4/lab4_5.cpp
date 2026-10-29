
#include <windows.h>

#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main() {
    // Устанавливаем кодировку UTF-8
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Объявляем переменные
    double a, b;
    char operation;

    // Вводим первое число
    cout << "Введите первое число: ";
    cin >> a;

    // Вводим второе число
    cout << "Введите второе число: ";
    cin >> b;

    // Запрашиваем математическую операцию
    cout << "Введите операцию (+, -, *, /): ";
    cin >> operation;

    // Настраиваем вывод дробных чисел
    cout << fixed << setprecision(2);

    // Выбираем действие
    switch (operation) {
        case '+':
            // Сложение
            cout << "Результат: " << a + b << endl;
            break;

        case '-':
            // Вычитание
            cout << "Результат: " << a - b << endl;
            break;

        case '*':
            // Умножение
            cout << "Результат: " << a * b << endl;
            break;

        case '/':
            // Деление с проверкой на ноль
            if (b != 0) {
                cout << "Результат: " << a / b << endl;
            } else {
                cout << "Ошибка: деление на ноль!" << endl;
            }
            break;

        default:
            // Если операция неизвестна
            cout << "Неизвестная операция" << endl;
    }

    // Ожидаем Enter
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}
