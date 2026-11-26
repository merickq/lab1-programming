#include <windows.h>

#include <cmath>
#include <iostream>
#include <limits>

int main() {
    // Настраиваем кодировку UTF-8 (65001) для консоли Windows
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    long long n;
    std::cout << "Введите целое число: ";

    if (!(std::cin >> n)) {
        std::cout << "Ошибка: необходимо ввести целое число.\n";
        std::cin.clear();
    } else if (n == 0) {
        // Краевой случай: ноль содержит 1 цифру, её сумма и произведение равны 0
        std::cout << "Количество цифр: 1\n";
        std::cout << "Сумма цифр: 0\n";
        std::cout << "Произведение цифр: 0\n";
        std::cout << "Перевёрнутое число: 0\n";
    } else {
        // Краевой случай: корректно обрабатываем отрицательные числа (включая LLONG_MIN)
        int sign = (n < 0) ? -1 : 1;
        unsigned long long temp = (n < 0) ? static_cast<unsigned long long>(-(n + 1)) + 1
                                          : static_cast<unsigned long long>(n);

        int count = 0;                       // Количество цифр
        long long total = 0;                 // Сумма цифр
        long long product = 1;               // Произведение цифр
        unsigned long long reversedNum = 0;  // Перевёрнутое число

        // Разбираем число по разрядам с конца
        while (temp > 0) {
            int digit = temp % 10;                   // Получаем младший разряд
            ++count;                                 // Увеличиваем счётчик
            total += digit;                          // Суммируем цифры
            product *= digit;                        // Перемножаем цифры
            reversedNum = reversedNum * 10 + digit;  // Формируем зеркальное число
            temp /= 10;                              // Убираем обработанный младший разряд
        }

        std::cout << "Количество цифр: " << count << "\n";
        std::cout << "Сумма цифр: " << total << "\n";
        std::cout << "Произведение цифр: " << product << "\n";
        std::cout << "Перевёрнутое число: " << (sign < 0 ? "-" : "") << reversedNum << "\n";
    }

    // Очищаем буфер и ждём нажатия Enter
    std::cout << "\nНажмите Enter для выхода...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}