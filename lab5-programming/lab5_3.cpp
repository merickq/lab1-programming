#include <windows.h>

#include <iostream>
#include <limits>

int main() {
    // Настраиваем кодировку UTF-8 (65001) для консоли Windows
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int n;
    std::cout << "Введите N: ";

    if (!(std::cin >> n)) {
        std::cout << "Ошибка: необходимо ввести целое число.\n";
        std::cin.clear();
    } else if (n <= 0) {
        // Краевой случай: нельзя вывести 0 или отрицательное число элементов
        std::cout << "Ошибка: N должно быть больше 0.\n";
    } else {
        // Краевой случай: 94-е число Фибоначчи превышает максимум 64-битного long long
        if (n > 93) {
            std::cout
                << "Внимание: отображаются первые 93 числа (дальше переполнение long long).\n";
            n = 93;
        }

        long long a = 0, b = 1;  // Первые два элемента последовательности
        std::cout << "Первые " << n << " чисел Фибоначчи:\n";

        for (int i = 0; i < n; ++i) {
            std::cout << a << " ";   // Выводим текущее число
            long long temp = a + b;  // Вычисляем следующее число
            a = b;                   // Обновляем предыдущие значения
            b = temp;
        }
        std::cout << "\n";
    }

    // Очищаем буфер и ждём нажатия Enter
    std::cout << "\nНажмите Enter для выхода...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}