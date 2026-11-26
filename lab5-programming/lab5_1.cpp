#define _USE_MATH_DEFINES  // Разрешаем использование математических констант (M_PI)
#include <windows.h>

#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    // Настраиваем кодировку UTF-8 (65001) для корректного отображения кириллицы
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Выводим заголовок таблицы и разделительную черту
    std::cout << std::setw(8) << "x" << std::setw(10) << "sin(x)" << "\n";
    std::cout << std::string(20, '-') << "\n";

    // Фиксируем формат вывода: 4 знака после запятой
    std::cout << std::fixed << std::setprecision(4);

    // Проходим по 11 точкам от 0 до pi с шагом pi/10
    for (int i = 0; i <= 10; ++i) {
        double x = i * M_PI / 10.0;  // Текущее значение аргумента
        double y = std::sin(x);      // Значение функции
        std::cout << std::setw(8) << x << std::setw(10) << y << "\n";
    }

    // Ожидаем нажатия Enter перед закрытием консоли
    std::cout << "\nНажмите Enter для выхода...";
    std::cin.get();
    return 0;
}