#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;

// Функция для заполнения массива случайными числами в заданном диапазоне
void fillArray(double* arr, int size, double min, double max) {
    for (int i = 0; i < size; ++i) {
        arr[i] = min + (max - min) * (rand() / (RAND_MAX + 1.0));
    }
}

// Функция для вывода массива по 10 элементов в строке
void printArray(const double* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    srand(time(0)); // Инициализация генератора случайных чисел

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    if (n <= 0) {
        cerr << "Ошибка: размер массива должен быть натуральным числом!" << endl;
        return 1;
    }

    double* arr = new double[n];

    double min, max;
    cout << "Введите диапазон случайных чисел (min max): ";
    cin >> min >> max;

    fillArray(arr, n, min, max);
    cout << "Сгенерированный массив:\n";
    printArray(arr, n);

    delete[] arr; // Освобождаем память
    return 0;
}
