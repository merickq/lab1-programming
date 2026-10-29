
#include <windows.h>

#include <iostream>
#include <limits>
using namespace std;

int main() {
    // Устанавливаем кодировку UTF-8
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Переменная для возраста
    int age;

    // Запрашиваем возраст
    cout << "Введите возраст: ";
    cin >> age;

    // Проверяем возрастную категорию
    if (age < 0) {
        cout << "Некорректный возраст" << endl;
    } else if (age <= 12) {
        cout << "Ребёнок" << endl;
    } else if (age <= 17) {
        cout << "Подросток" << endl;
    } else if (age <= 64) {
        cout << "Взрослый" << endl;
    } else {
        cout << "Пожилой" << endl;
    }

    // Ожидаем Enter
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}
