#include <iostream>
#include <clocale>
#include <iomanip> 
#include "triangle.h" // Подключаем заголовочный файл

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    double hypotenuse, leg1, leg2, radius;

    cout << "Hypotenuse: ";
    cin >> hypotenuse;
    cout << "Leg 1: ";
    cin >> leg1;

    if (hypotenuse <= 0 || leg1 <= 0) {
        cout << "Error! Side lengths must be positive." << endl;
        return 1;
    }
    if (leg1 >= hypotenuse) {
        cout << "Error! Leg can't be >= hypotenuse." << endl;
        return 1;
    }

    // Вычисляем второй катет и радиус с помощью функций
    leg2 = calculateLeg(hypotenuse, leg1);
    radius = calculateRadius(hypotenuse, leg1, leg2);

    cout << fixed << setprecision(3);
    cout << "Leg 2: " << leg2 << endl;
    cout << "Radius: " << radius << endl;

    return 0;
}
