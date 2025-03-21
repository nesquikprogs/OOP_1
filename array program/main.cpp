#include <iostream>
#include <cstdlib>
#include <ctime>
#include "computations.h"

using namespace std;

// Функция для заполнения массива случайными числами
void fillArray(double* arr, int size, double minVal, double maxVal) {
    for (int i = 0; i < size; i++) {
        arr[i] = minVal + (maxVal - minVal) * (rand() / (double)RAND_MAX);
    }
}

// Функция для вывода массива
void printArray(const double* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian"); // Установка русского языка в консоли
    srand(time(0)); // Инициализация генератора случайных чисел

    int n;
    double minVal, maxVal;
    
    cout << "Введите количество элементов массива: ";
    cin >> n;
    
    cout << "Введите минимальное и максимальное значения диапазона: ";
    cin >> minVal >> maxVal;
    
    // Создание динамического массива
    double* arr = new double[n];
    
    // Заполнение массива случайными числами
    fillArray(arr, n, minVal, maxVal);
    
    // Вывод массива
    cout << "Сгенерированный массив: ";
    printArray(arr, n);
    
    // Вычисление и вывод произведения элементов
    cout << "Произведение элементов массива: " << computeProduct(arr, n) << endl;
    
    // Освобождение памяти
    delete[] arr;
    
    return 0;
}
