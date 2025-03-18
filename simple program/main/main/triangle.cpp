#include "triangle.h"
#include <cmath> // для sqrt и pow

// Вычисление второго катета
double calculateLeg(double hypotenuse, double leg1) {
    return sqrt(pow(hypotenuse, 2) - pow(leg1, 2)); // Используем теорему Пифагора для вычисления второго катета
}

// Вычисление радиуса вписанной окружности
double calculateRadius(double hypotenuse, double leg1, double leg2) {
    return (leg1 + leg2 - hypotenuse) / 2; // Формула для вычисления радиуса вписанной окружности
}
