#include "computations.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

// Функция для вычисления произведения элементов массива
double computeProduct(const double* arr, int size) {
    double product = 1.0;
    for (int i = 0; i < size; i++) {
        product *= arr[i];
    }
    return product;
}

// Функция для записи массива в файл
void writeArrayToFile(const double* arr, int size, const char* filename) {
    ofstream outFile(filename); // Открываем файл для записи
    if (!outFile) {
        cerr << "Не удалось открыть файл для записи!" << endl;
        return;
    }

    // Записываем размер массива, затем сами элементы
    outFile << size << endl;
    for (int i = 0; i < size; i++) {
        outFile << arr[i] << endl;
    }

    outFile.close();
}

// Функция для чтения массива из файла
void readArrayFromFile(double* arr, int& size, const char* filename) {
    ifstream inFile(filename); // Открываем файл для чтения
    if (!inFile) {
        cerr << "Не удалось открыть файл для чтения!" << endl;
        return;
    }

    // Считываем размер массива
    inFile >> size;

    // Читаем элементы массива
    for (int i = 0; i < size; i++) {
        inFile >> arr[i];
    }

    inFile.close();
}

// Функция для заполнения массива случайными числами
void fillArray(double* arr, int size, double minVal, double maxVal) {
    for (int i = 0; i < size; i++) {
        arr[i] = minVal + (maxVal - minVal) * (rand() / (double)RAND_MAX);
    }
}

// Функция для вывода массива на экран
void printArray(const double* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
