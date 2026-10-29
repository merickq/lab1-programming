
#include <windows.h>

#include <iostream>
#include <limits>
using namespace std;

int main() {
    // Настраиваем русскую кодировку
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Объявляем переменную для года
    int year;

    // Запрашиваем год
    cout << "Введите год: ";
    cin >> year;

    // Проверяем правильность года
    if (year <= 0) {
        cout << "Некорректный год" << endl;
    }
    // Проверяем условие високосного года
    else if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << year << " - високосный год" << endl;
    } else {
        cout << year << " - не високосный год" << endl;
    }

    // Ожидаем Enter
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}
