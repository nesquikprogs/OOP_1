﻿#include <iostream>
#include <clocale>
#include <iomanip>
#include "triangle.h"

using namespace std;

int main() {
    // Вызов функции с набором ассертов, проверяющих корректность calculateLeg() и calculateRadius()
    runAssertions(); 

    // Установка локали для вывода русских букв в консоль
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Объявление переменных для хранения данных (hypotenuse - гипотенуза, leg1 - первый катит, leg2 - второй катит, radius - радиус вписааной окружности)
    double hypotenuse, leg1, leg2, radius;

    cout << "Задача #15. Выполнено Александровым Данилом, ВМК-22" << endl;
    cout << "\n";
    cout << "Входные данные:" << endl;

    cout << "Гипотенуза: ";
    cin >> hypotenuse;
    cout << "Катет 1: ";
    cin >> leg1;

    // Блок проверки исключительных ситуаций (гипотенуза и катет <= 0, катет >= гипотенуза )
    if (hypotenuse <= 0 || leg1 <= 0) {
        cout << "Ошибка! Длины сторон треугольника не могут быть отрицательными." << endl;
        return 1;
    }
    if (leg1 >= hypotenuse) {
        cout << "Ошибка! Катет не может быть длиннее гипотенузы." << endl;
        return 1;
    }

    // Присваивание leg2(второй катет) результата выполнения функции calculateLeg c переданными аргументами: гипотенуза и первый катет
    leg2 = calculateLeg(hypotenuse, leg1);

    // Присваивание radius(радиус вписанной окружности) результата выполнения функции calculateRadius c переданными аргументами: гипотенуза, первый катет и второй катет
    radius = calculateRadius(hypotenuse, leg1, leg2);

    cout << "\nОтвет:" << endl;
    
    // Фиксированный вывод трех символов после запятой
    cout << fixed << setprecision(3);
    
    cout << "Катет 2: " << leg2 << endl;
    cout << "Радиус вписанной окружности: " << radius << endl;
    cout << "\n";
    return 0;
}
