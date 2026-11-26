#include <windows.h>

#include <iostream>
#include <limits>

int main() {
    // Настраиваем кодировку UTF-8 (65001) для консоли Windows
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int n;
    std::cout << "Введите высоту фигур N (например, 5): ";

    if (!(std::cin >> n)) {
        std::cout << "Ошибка: необходимо ввести целое число.\n";
        std::cin.clear();
    } else if (n <= 0) {
        // Краевой случай: невозможно построить фигуру нулевой или отрицательной высоты
        std::cout << "Ошибка: высота N должна быть больше 0.\n";
    } else {
        // 1. Прямоугольник N x N
        std::cout << "Прямоугольник:\n";
        for (int i = 0; i < n; ++i) {      // Внешний цикл по строкам
            for (int j = 0; j < n; ++j) {  // Внутренний цикл по столбцам
                std::cout << "*";
            }
            std::cout << "\n";
        }

        // 2. Прямоугольный треугольник
        std::cout << "\nТреугольник:\n";
        for (int i = 1; i <= n; ++i) {  // В i-й строке выводим ровно i звёздочек
            for (int j = 0; j < i; ++j) {
                std::cout << "*";
            }
            std::cout << "\n";
        }

        // 3. Ёлочка (равнобедренный треугольник)
        std::cout << "\nЁлочка:\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < n - i; ++j) std::cout << " ";      // Отступ пробелами слева
            for (int j = 0; j < 2 * i - 1; ++j) std::cout << "*";  // Нечётное количество звёздочек
            std::cout << "\n";
        }

        // 4. Ромб (при N = 1 нижний цикл не запустится и выведется 1 звёздочка)
        std::cout << "\nРомб:\n";
        // Верхняя часть ромба (от 1 до N)
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < n - i; ++j) std::cout << " ";
            for (int j = 0; j < 2 * i - 1; ++j) std::cout << "*";
            std::cout << "\n";
        }
        // Нижняя часть ромба (от N - 1 вниз до 1)
        for (int i = n - 1; i >= 1; --i) {
            for (int j = 0; j < n - i; ++j) std::cout << " ";
            for (int j = 0; j < 2 * i - 1; ++j) std::cout << "*";
            std::cout << "\n";
        }
    }

    // Очищаем буфер и ждём нажатия Enter
    std::cout << "\nНажмите Enter для выхода...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}