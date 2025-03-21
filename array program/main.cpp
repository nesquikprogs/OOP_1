#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "computations.h"

using namespace std;

// Функция для тестирования computeProduct с помощью assert
void testComputeProduct() {
    double arr1[] = {1.0, 2.0, 3.0, 4.0};
    assert(computeProduct(arr1, 4) == 24.0);

    double arr2[] = {0.5, 2.0, 2.0};
    assert(computeProduct(arr2, 3) == 2.0);

    double arr3[] = {10.0};
    assert(computeProduct(arr3, 1) == 10.0);

    double arr4[] = {0.0, 5.0, 6.0};
    assert(computeProduct(arr4, 3) == 0.0);

    cout << "Все тесты прошли успешно!" << endl;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8"); // Установка русской локали для вывода текста в консоль
    srand(time(0)); // Инициализация генератора случайных чисел

    // Пример записи и чтения массива из файла
    int n;
    double* arr;

    cout << "Введите количество элементов массива: ";
    cin >> n;
    
    arr = new double[n];
    
    // Заполнение массива случайными числами
    fillArray(arr, n, 1.0, 10.0);
    
    // Вывод массива
    cout << "Сгенерированный массив: " << endl;
    printArray(arr, n);
    
    // Записываем массив в файл
    writeArrayToFile(arr, n, "array_data.txt");

    // Очистка массива
    delete[] arr;
    
    // Чтение массива из файла
    cout << "\nЧтение массива из файла:" << endl;
    arr = new double[n];
    int sizeFromFile;
    readArrayFromFile(arr, sizeFromFile, "array_data.txt");

    // Вывод массива из файла
    cout << "Массив из файла: " << endl;
    printArray(arr, sizeFromFile);

    // Вычисление и вывод произведения элементов
    cout << "Произведение элементов массива: " << computeProduct(arr, sizeFromFile) << endl;

    delete[] arr;
    
    return 0;
}
