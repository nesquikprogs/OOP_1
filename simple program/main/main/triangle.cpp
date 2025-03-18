#include "triangle.h"
#include <cmath> // для sqrt и pow
#include <cassert>  // Для использования assert

// Вычисление второго катета
double calculateLeg(double hypotenuse, double leg1) {
    assert(hypotenuse > leg1);  // Проверка, что гипотенуза больше катета
    double leg2 = sqrt(pow(hypotenuse, 2) - pow(leg1, 2));
    assert(leg2 >= 0);  // Проверка, что второй катет не отрицателен
    return leg2;
}

// Вычисление радиуса вписанной окружности
double calculateRadius(double hypotenuse, double leg1, double leg2) {
    assert(leg1 > 0 && leg2 > 0 && hypotenuse > 0);  // Проверка, что все стороны положительные
    double radius = (leg1 + leg2 - hypotenuse) / 2;
    assert(radius >= 0);  // Проверка, что радиус не отрицателен
    return radius;
}
