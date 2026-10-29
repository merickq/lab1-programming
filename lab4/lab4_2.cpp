
#include <windows.h>

#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main() {
    // Настраиваем русскую кодировку
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Создаём переменные для трёх чисел
    double a, b, c;

    // Вводим числа
    cout << "Введите первое число: ";
    cin >> a;

    cout << "Введите второе число: ";
    cin >> b;

    cout << "Введите третье число: ";
    cin >> c;

    // Создаём переменную для максимума
    double maximum;

    // Сравниваем числа
    if (a >= b && a >= c) {
        maximum = a;
    } else if (b >= a && b >= c) {
        maximum = b;
    } else {
        maximum = c;
    }

    // Настраиваем вывод до двух знаков
    cout << fixed << setprecision(2);

    // Выводим максимальное число
    cout << "Максимальное число: " << maximum << endl;

    // Ожидаем Enter
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}
