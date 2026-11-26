#include <windows.h>

#include <iostream>
#include <limits>

int main() {
    // Настраиваем кодировку UTF-8 (65001) для консоли Windows
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int n;
    std::cout << "Введите N: ";

    // Проверяем корректность ввода и граничные условия
    if (!(std::cin >> n)) {
        // Сработал флаг ошибки потока (введены нечисловые символы)
        std::cout << "Ошибка: необходимо ввести целое число.\n";
        std::cin.clear();
    } else if (n < 0) {
        // Краевой случай: факториал отрицательного числа не существует
        std::cout << "Ошибка: N должно быть неотрицательным числом (N >= 0).\n";
    } else {
        // Используем long long для защиты от быстрого переполнения
        long long sumNumbers = 0;
        long long product = 1;  // Для N = 0 корректно даст 0! = 1
        long long sumSquares = 0;

        for (int i = 1; i <= n; ++i) {
            sumNumbers += i;
            if (i <= 20) {
                product *=
                    i;  // Максимальный факториал, помещающийся в 64-битный long long, это 20!
            }
            // Явное приведение к long long предотвращает переполнение типа int при умножении i * i
            sumSquares += static_cast<long long>(i) * i;
        }

        std::cout << "Сумма: " << sumNumbers << "\n";
        if (n > 20) {
            std::cout << "Произведение (N!): переполнение типа long long (N > 20)\n";
        } else {
            std::cout << "Произведение (N!): " << product << "\n";
        }
        std::cout << "Сумма квадратов: " << sumSquares << "\n";
    }

    // Очищаем остаток строки в буфере ввода и ждём нажатия Enter
    std::cout << "\nНажмите Enter для выхода...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}