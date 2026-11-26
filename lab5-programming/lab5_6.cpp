#include <windows.h>

#include <iostream>
#include <limits>

int main() {
    // Настраиваем кодировку UTF-8 (65001) для консоли Windows
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    long long n;  // Используем long long, чтобы избежать переполнения при перевороте больших чисел
    std::cout << "Введите целое число: ";

    if (!(std::cin >> n)) {
        std::cout << "Ошибка: необходимо ввести целое число.\n";
        std::cin.clear();
    } else if (n < 0) {
        // Краевой случай: отрицательные числа не могут быть палиндромами
        std::cout << n << " — не палиндром\n";
    } else {
        long long original = n;     // Исходное число
        long long reversedNum = 0;  // Перевёрнутое число
        long long temp = n;         // Временная переменная для разбора разрядов

        // Переворачиваем число справа налево
        while (temp > 0) {
            int digit = temp % 10;
            reversedNum = reversedNum * 10 + digit;
            temp /= 10;
        }

        // Сравниваем оригинал с его зеркальной копией
        if (original == reversedNum) {
            std::cout << original << " — палиндром\n";
        } else {
            std::cout << original << " — не палиндром\n";
        }
    }

    // Очищаем буфер и ждём нажатия Enter
    std::cout << "\nНажмите Enter для выхода...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}