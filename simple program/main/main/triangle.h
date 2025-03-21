#ifndef TRIANGLE_H
#define TRIANGLE_H

// Объявляем функции для вычисления второго катета и радиуса вписанной окружности
double calculateLeg(double hypotenuse, double leg1);
double calculateRadius(double hypotenuse, double leg1, double leg2);

// Объявляем функцию для выполнения всех проверок (для использования в main.cpp и triangle.cpp)
void checkAssertions(double hypotenuse, double leg1, double leg2, double radius);

#endif // TRIANGLE_H
