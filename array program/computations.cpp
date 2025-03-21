#include "computations.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>  // Для обработки исключений
#include <vector>
using namespace std;

// Функция для вычисления произведения элементов массива
double computeProduct(const std::vector<double>& arr) {
    if (arr.empty()) {
        throw invalid_argument("Массив не может быть пустым.");
    }

    double product = 1.0;
    for (double val : arr) {
        product *= val;
    }
    return product;
}

// Функция для записи массива в файл
void writeArrayToFile(const std::vector<double>& arr, const char* filename) {
    if (arr.empty()) {
        throw invalid_argument("Массив не может быть пустым.");
    }

    ofstream outFile(filename); // Открываем файл для записи
    if (!outFile) {
        throw runtime_error("Не удалось открыть файл для записи!");
    }

    // Записываем размер массива, затем сами элементы
    outFile << arr.size() << endl;
    for (double val : arr) {
        outFile << val << endl;
    }

    outFile.close();
}

// Функция для чтения массива из файла
void readArrayFromFile(std::vector<double>& arr, const char* filename) {
    ifstream inFile(filename); // Открываем файл для чтения
    if (!inFile) {
        throw runtime_error("Не удалось открыть файл для чтения!");
    }

    // Считываем размер массива
    size_t size;
    inFile >> size;
    arr.resize(size);  // Устанавливаем размер вектору

    // Читаем элементы массива
    for (size_t i = 0; i < size; i++) {
        inFile >> arr[i];
    }

    inFile.close();
}

// Функция для заполнения массива случайными числами
void fillArray(std::vector<double>& arr, double minVal, double maxVal) {
    if (arr.empty()) {
        throw invalid_argument("Массив не может быть пустым.");
    }

    for (double& val : arr) {
        val = minVal + (maxVal - minVal) * (rand() / (double)RAND_MAX);
    }
}

// Функция для вывода массива на экран
void printArray(const std::vector<double>& arr) {
    if (arr.empty()) {
        throw invalid_argument("Массив не может быть пустым.");
    }

    for (double val : arr) {
        cout << val << " ";
    }
    cout << endl;
}
