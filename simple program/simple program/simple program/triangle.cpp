#include "triangle.h"
#include <cmath> // Для sqrt и pow

// Вычисление второго катета
double calculateLeg(double hypotenuse, double leg1) {
    return sqrt(pow(hypotenuse, 2) - pow(leg1, 2));
}

// Вычисление радиуса вписанной окружности
double calculateRadius(double hypotenuse, double leg1, double leg2) {
    return (leg1 + leg2 - hypotenuse) / 2;
}
