#include <windows.h>

#include <iostream>
#include <limits>
#include <vector>

int main() {
    // Настраиваем кодировку UTF-8 (65001) для консоли Windows
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    long long n;
    std::cout << "Введите натуральное число (> 1): ";

    if (!(std::cin >> n)) {
        std::cout << "Ошибка: необходимо ввести целое число.\n";
        std::cin.clear();
    } else if (n <= 1) {
        // Краевой случай: 0, 1 и отрицательные числа не раскладываются на простые множители
        std::cout << "Разложение на простые множители возможно только для чисел больше 1.\n";
    } else {
        long long original = n;          // Запоминаем исходное число
        std::vector<long long> factors;  // Динамический массив для хранения множителей

        // Условие divisor <= n / divisor эквивалентно divisor^2 <= n, но защищает от переполнения
        for (long long divisor = 2; divisor <= n / divisor; ++divisor) {
            // Извлекаем все вхождения текущего простого делителя
            while (n % divisor == 0) {
                factors.push_back(divisor);
                n /= divisor;
            }
        }

        // Если после цикла остаток больше 1, добавляем его как последний простой множитель
        if (n > 1) {
            factors.push_back(n);
        }

        // Выводим разложение через разделитель " x "
        std::cout << original << " = ";
        for (size_t i = 0; i < factors.size(); ++i) {
            if (i > 0) std::cout << " x ";
            std::cout << factors[i];
        }
        std::cout << "\n";
    }

    // Очищаем буфер и ждём нажатия Enter
    std::cout << "\nНажмите Enter для выхода...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}