#include "triangle.h"
#include <cmath> // для sqrt и pow
#include <cassert>  // Для использования assert

// Функция для выполнения всех проверок
void checkAssertions(double hypotenuse, double leg1, double leg2, double radius) {
    assert(hypotenuse > leg1);  // Проверка, что гипотенуза больше катета
    assert(leg2 >= 0);  // Проверка, что второй катет не отрицателен
    assert(radius >= 0);  // Проверка, что радиус не отрицателен
}

// Вычисление второго катета
double calculateLeg(double hypotenuse, double leg1) {
    double leg2 = sqrt(pow(hypotenuse, 2) - pow(leg1, 2));
    return leg2;
}

// Вычисление радиуса вписанной окружности
double calculateRadius(double hypotenuse, double leg1, double leg2) {
    double radius = (leg1 + leg2 - hypotenuse) / 2;
    return radius;
}
