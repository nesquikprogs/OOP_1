#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
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

// Функция для тестирования computeProduct с помощью assert
void testComputeProduct() {
    // Тест 1: Ожидаемое произведение 1.0 * 2.0 * 3.0 * 4.0 = 24.0
    double arr1[] = {1.0, 2.0, 3.0, 4.0};
    assert(computeProduct(arr1, 4) == 24.0);

    // Тест 2: Ожидаемое произведение 0.5 * 2.0 * 2.0 = 2.0
    double arr2[] = {0.5, 2.0, 2.0};
    assert(computeProduct(arr2, 3) == 2.0);

    // Тест 3: Ожидаемое произведение 10.0 (один элемент)
    double arr3[] = {10.0};
    assert(computeProduct(arr3, 1) == 10.0);

    // Тест 4: Ожидаемое произведение 0.0 * 5.0 * 6.0 = 0.0
    double arr4[] = {0.0, 5.0, 6.0};
    assert(computeProduct(arr4, 3) == 0.0);

    cout << "Все тесты прошли успешно!" << endl;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

 // Установка русского языка в консоли
    srand(time(0)); // Инициализация генератора случайных чисел

    // Выполнение тестов
    testComputeProduct();
    
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
