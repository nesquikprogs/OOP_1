#include <iostream>
#include <cmath>
#include <clocale> // Для setlocale
using namespace std;

int main() {
    // Установка локали для корректного отображения русских букв
    setlocale(LC_ALL, "Russian_Russia.1251");

    double hypotenuse, leg1, leg2, radius;

    // Ввод данных
    cout << "Введите длину гипотенузы: ";
    cin >> hypotenuse;
    cout << "Введите длину первого катета: ";
    cin >> leg1;

    // Проверка корректности введённых данных
    if (hypotenuse <= 0 || leg1 <= 0) {
        cout << "Длины сторон должны быть положительными!" << endl;
        return 1;
    }
    if (leg1 >= hypotenuse) {
        cout << "Катет не может быть больше или равен гипотенузе!" << endl;
        return 1;
    }

    // Вычисление второго катета
    // leg2 = sqrt(hypotenuse^2 - leg1^2), где hypotenuse - гипотенуза, leg1 - первый катет
    leg2 = sqrt(pow(hypotenuse, 2) - pow(leg1, 2));

    // Вычисление радиуса вписанной окружности
    // r = (a + b - c) / 2, где a и b - катеты, c - гипотенуза
    radius = (leg1 + leg2 - hypotenuse) / 2;

    // Вывод результатов
    cout << "Второй катет: " << leg2 << endl;
    cout << "Радиус вписанной окружности: " << radius << endl;

    return 0;
}