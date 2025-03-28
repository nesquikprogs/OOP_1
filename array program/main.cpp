#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert> // Для использования assert
using namespace std;

// Функция для заполнения массива случайными числами
void fillArray(double* arr, int size, double min, double max) {
    for (int i = 0; i < size; ++i) {
        arr[i] = min + (max - min) * (rand() / (RAND_MAX + 1.0));
    }
}

// Функция для вывода массива
void printArray(const double* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout.width(8); // Выделяем место для выравнивания чисел
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

// Функция для вычисления произведения элементов массива
double calculateProduct(const double* arr, int size) {
    double product = 1.0; // Начинаем с единицы, чтобы не обнулять произведение
    for (int i = 0; i < size; ++i) {
        product *= arr[i]; // Умножаем каждый элемент на текущее произведение
    }
    return product;
}

// Тестирование функции calculateProduct
void testCalculateProduct() {
    // Тест 1: Массив с положительными числами
    assert(calculateProduct(new double[3]{2.0, 3.0, 4.0}, 3) == 24.0); // 2 * 3 * 4 = 24.0

    // Тест 2: Массив с нулями
    assert(calculateProduct(new double[3]{0.0, 3.0, 5.0}, 3) == 0.0); // 0 * 3 * 5 = 0.0

    // Тест 3: Массив с одним элементом
    assert(calculateProduct(new double[1]{5.0}, 1) == 5.0); // 5.0

    // Тест 4: Массив с отрицательными числами
    assert(calculateProduct(new double[3]{-2.0, 3.0, -4.0}, 3) == 24.0); // (-2) * 3 * (-4) = 24.0

    // Тест 5: Массив с одним нулём
    assert(calculateProduct(new double[1]{0.0}, 1) == 0.0); // 0.0

    // Тест 6: Массив с несколькими отрицательными числами
    assert(calculateProduct(new double[3]{-1.0, -2.0, -3.0}, 3) == -6.0); // (-1) * (-2) * (-3) = -6.0

    cout << "Все тесты прошли успешно!" << endl;
}

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    // Запускаем все тесты на вычисление произведения
    testCalculateProduct();

    // Размер массива, вводимый пользователем
    int size;
    cout << "Введите размер массива: ";
    cin >> size; // Пользователь вводит размер массива

    // Проверка на корректность введённого размера массива
    if (size <= 0) {
        cout << "Размер массива должен быть положительным числом!" << endl;
        return 1;
    }

    // Ввод минимального и максимального значений
    double min, max;
    cout << "Введите минимальное значение: ";
    cin >> min;
    cout << "Введите максимальное значение: ";
    cin >> max;

    // Проверка, чтобы максимальное значение было больше минимального
    if (min >= max) {
        cout << "Минимальное значение должно быть меньше максимального!" << endl;
        return 1;
    }

    double* arr = new double[size]; // Выделяем память под массив

    // Заполняем массив случайными числами
    fillArray(arr, size, min, max);

    // Выводим массив
    cout << "Массив элементов:" << endl;
    printArray(arr, size);

    // Вычисляем произведение элементов массива
    double product = calculateProduct(arr, size);
    cout << "Произведение элементов массива: " << product << endl;

    delete[] arr; // Освобождаем память
    return 0;
}
