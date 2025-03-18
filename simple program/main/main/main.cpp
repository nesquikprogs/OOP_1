#include <iostream>
#include <clocale>
#include <iomanip> 
#include "triangle.h" // Подключаем заголовочный файл
#include <cassert>  // Для использования assert

using namespace std;

int main() {
    setlocale(LC_ALL, ""); // Устанавливаем локаль для корректного отображения текста

    double hypotenuse, leg1, leg2, radius; // Объявляем переменные для гипотенузы, катетов и радиуса

    // Добавление UI
    cout << "Task #15. Completed by Danil Aleksandrov from the VMK-22 group" << endl;
    cout << "\n";
    cout << "Data entry:" << endl;

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

    // Проверка, что гипотенуза больше первого катета
    assert(hypotenuse > leg1);  // Проверка 1

    // Вычисляем второй катет с помощью функций
    leg2 = calculateLeg(hypotenuse, leg1);

    // Проверка, что второй катет не отрицателен
    assert(leg2 >= 0);  // Проверка 2

    // Вычислям радиус с помощью функций
    radius = calculateRadius(hypotenuse, leg1, leg2);

    // Проверка, что радиус не отрицателен
    assert(radius >= 0);  // Проверка 3

    // Добавление UI
    cout << "\n";
    cout << "Answer:" << endl;

    // Выводим результаты с точностью до 3 знаков
    cout << fixed << setprecision(3);
    cout << "Leg 2: " << leg2 << endl;
    cout << "Radius: " << radius << endl;

    cout << "\n";
    return 0; // Завершаем программу
}
