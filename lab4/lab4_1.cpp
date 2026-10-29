
#include <windows.h>

#include <iostream>
#include <limits>
using namespace std;

int main() {
    // Настраиваем кодировку для русского языка
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Объявляем переменную для числа
    int number;

    // Запрашиваем число у пользователя
    cout << "Введите целое число: ";
    cin >> number;

    // Проверяем число на чётность
    if (number % 2 == 0) {
        cout << "Число чётное" << endl;
    } else {
        cout << "Число нечётное" << endl;
    }

    // Проверяем делимость на 3
    if (number % 3 == 0) {
        cout << "Число делится на 3" << endl;
    } else {
        cout << "Число не делится на 3" << endl;
    }

    // Определяем знак числа
    if (number > 0) {
        cout << "Число положительное" << endl;
    } else if (number < 0) {
        cout << "Число отрицательное" << endl;
    } else {
        cout << "Число равно нулю" << endl;
    }

    // Ожидаем нажатия Enter
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}
