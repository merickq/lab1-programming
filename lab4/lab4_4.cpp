
#include <windows.h>

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main() {
    // Настраиваем русскую кодировку
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Объявляем коэффициенты уравнения
    double a, b, c;

    // Вводим коэффициенты
    cout << "Введите a: ";
    cin >> a;

    cout << "Введите b: ";
    cin >> b;

    cout << "Введите c: ";
    cin >> c;

    // Устанавливаем точность вывода
    cout << fixed << setprecision(2);

    // Проверяем коэффициент a
    if (a == 0) {
        cout << "Это не квадратное уравнение" << endl;

        // Решаем получившееся линейное уравнение
        if (b != 0) {
            double x = -c / b;
            cout << "Корень: x = " << x << endl;
        } else if (c == 0) {
            cout << "Бесконечно много решений" << endl;
        } else {
            cout << "Решений нет" << endl;
        }
    } else {
        // Вычисляем дискриминант
        double D = b * b - 4 * a * c;

        cout << "Дискриминант: " << D << endl;

        // Проверяем значение дискриминанта
        if (D > 0) {
            // Вычисляем два корня
            double x1 = (-b + sqrt(D)) / (2 * a);
            double x2 = (-b - sqrt(D)) / (2 * a);

            cout << "Первый корень: " << x1 << endl;
            cout << "Второй корень: " << x2 << endl;
        } else if (D == 0) {
            // Вычисляем один корень
            double x = -b / (2 * a);

            cout << "Один корень: " << x << endl;
        } else {
            // При отрицательном D действительных корней нет
            cout << "Действительных корней нет" << endl;
        }
    }

    // Ожидаем Enter
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}
