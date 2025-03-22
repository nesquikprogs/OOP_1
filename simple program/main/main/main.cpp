#include <iostream>
#include <clocale>
#include <iomanip>
#include "triangle.h" // Подключаем заголовочный файл
#include <cassert>  // Для использования assert

using namespace std;

int main() {
    setlocale(LC_ALL, "ru"); // Устанавливаем локаль для корректного отображения текста

    double hypotenuse, leg1, leg2, radius; // Объявляем переменные для гипотенузы, катетов и радиуса

    // Добавление UI
    cout << "Задача #15. Выполнено Александровым Данилом, ВМК-22" << endl;
    cout << "\n";
    cout << "Входные данные:" << endl;

    // Ввод данных
    cout << "Гипотенуза: ";
    cin >> hypotenuse;
    cout << "Катет 1: ";
    cin >> leg1;

    // Проверка корректности введённых данных
    if (hypotenuse <= 0 || leg1 <= 0) {
        cout << "Ошибка! Длины сторон треугольника не могут быть отрицательными." << endl;
        return 1;
    }
    if (leg1 >= hypotenuse) {
        cout << "Ошибка! Катет не может быть длиннее гипотенузы." << endl;
        return 1;
    }

    // Вычисляем второй катет с помощью функций
    leg2 = calculateLeg(hypotenuse, leg1);

    // Вычисляем радиус с помощью функций
    radius = calculateRadius(hypotenuse, leg1, leg2);

    // Выполняем проверки
    checkAssertions(hypotenuse, leg1, leg2, radius);

    // Добавление UI
    cout << "\n";
    cout << "Ответ:" << endl;

    // Выводим результаты с точностью до 3 знаков
    cout << fixed << setprecision(3);
    cout << "Катет 2: " << leg2 << endl;
    cout << "Радиус вписанной окружности: " << radius << endl;

    cout << "\n";
    return 0; // Завершаем программу
}
