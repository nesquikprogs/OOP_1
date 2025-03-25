#ifndef TRIANGLE_H
#define TRIANGLE_H

// Объявляем функции для вычисления второго катета и радиуса вписанной окружности
double calculateLeg(double hypotenuse, double leg1);
double calculateRadius(double hypotenuse, double leg1, double leg2);

// Объявляем функцию для выполнения всех проверок
void runAssertions();

#endif // TRIANGLE_H
