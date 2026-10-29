
#include <windows.h>

#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main() {
    // Настраиваем русскую кодировку
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Объявляем переменные для сторон
    double a, b, c;

    // Вводим длины сторон
    cout << "Введите первую сторону: ";
    cin >> a;

    cout << "Введите вторую сторону: ";
    cin >> b;

    cout << "Введите третью сторону: ";
    cin >> c;

    // Устанавливаем формат вывода
    cout << fixed << setprecision(2);

    // Проверяем положительность сторон
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "Стороны должны быть положительными" << endl;
    }
    // Проверяем существование треугольника
    else if (a + b > c && a + c > b && b + c > a) {
        cout << "Треугольник существует" << endl;

        // Проверяем равенство всех сторон
        if (a == b && b == c) {
            cout << "Тип: равносторонний" << endl;
        }
        // Проверяем равенство любых двух сторон
        else if (a == b || a == c || b == c) {
            cout << "Тип: равнобедренный" << endl;
        }
        // Если все стороны разные
        else {
            cout << "Тип: разносторонний" << endl;
        }
    } else {
        cout << "Треугольник не существует" << endl;
    }

    // Ожидаем Enter
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}
