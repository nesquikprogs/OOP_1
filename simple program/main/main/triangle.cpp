#include "triangle.h"
#include <cmath>
#include <cassert>

// Функция с набором ассертов, проверяющая корректность работы calculateLeg() и calculateRadius()
void runAssertions() {
    // Проверка расчета второго катета
    assert(calculateLeg(5, 3) == 4.0);
    assert(calculateLeg(10, 8) == 6.0);
    assert(calculateLeg(13, 12) == 5.0);

    // Проверка расчета радиуса вписанной окружности
    assert(calculateRadius(5, 3, 4) == 1.0);
    assert(calculateRadius(10, 8, 6) == 2.0);
    assert(calculateRadius(13, 12, 5) == 2.0);

    // Дополнительные проверки для дробных значений
    assert(abs(calculateLeg(5.5, 3.3) - 4.4) < 0.001);
    assert(abs(calculateLeg(7.2, 5.4) - 4.763) < 0.001);

    // Дополнительные проверки для радиуса с дробными числами
    assert(abs(calculateRadius(5.5, 3.3, 4.4) - 1.1) < 0.001);
    assert(abs(calculateRadius(7.2, 5.4, 4.32) - 1.26) < 0.001);
}

// Функция вычисления второго катета по теореме пифагора с аргументами hypotenuse - гипотенуза, leg1 - первый катит
double calculateLeg(double hypotenuse, double leg1) {
    return sqrt(pow(hypotenuse, 2) - pow(leg1, 2));
}

// Функция вычисления радиуса вписанной окружности по формуле r = (a + b - c) / 2  с аргументами hypotenuse - гипотенуза, leg1 - первый катит, leg2 - второй катит
double calculateRadius(double hypotenuse, double leg1, double leg2) {
    return (leg1 + leg2 - hypotenuse) / 2;
}
