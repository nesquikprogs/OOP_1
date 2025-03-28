#include <iostream>
#include <cstdlib>
#include <ctime>
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

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    int size; // Размер массива, вводимый пользователем
    cout << "Введите размер массива: ";
    cin >> size; // Пользователь вводит размер массива

    // Проверка на корректность введённого размера массива
    if (size <= 0) {
        cout << "Размер массива должен быть положительным числом!" << endl;
        return 1;
    }

    double min = 1.0, max = 10.0; // Диапазон для случайных чисел

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
