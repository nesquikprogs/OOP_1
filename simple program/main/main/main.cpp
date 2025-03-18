#include <iostream>
#include <clocale>
#include <iomanip> 
#include "triangle.h" // Подключаем заголовочный файл

using namespace std;

int main() {
    setlocale(LC_ALL, ""); // Устанавливаем локаль для корректного отображения текста

    double hypotenuse, leg1, leg2, radius; // Объявляем переменные для гипотенузы, катетов и радиуса

    // Ввод данных
    cout << "Hypotenuse: ";
    cin >> hypotenuse;
    cout << "Leg 1: ";
    cin >> leg1;

    // Проверка корректности введённых данных
    if (hypotenuse <= 0 || leg1 <= 0) {
        cout << "Error! Side lengths must be positive." << endl;
        return 1;
    }
    if (leg1 >= hypotenuse) {
        cout << "Error! Leg can't be >= hypotenuse." << endl;
        return 1;
    }

    // Вычисляем второй катет и радиус
    leg2 = calculateLeg(hypotenuse, leg1);
    radius = calculateRadius(hypotenuse, leg1, leg2);

    // Выводим результаты с точностью до 3 знаков
    cout << fixed << setprecision(3);
    cout << "Leg 2: " << leg2 << endl;
    cout << "Radius: " << radius << endl;

    return 0; // Завершаем программу
}
