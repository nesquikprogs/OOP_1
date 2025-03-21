#ifndef COMPUTATIONS_H
#define COMPUTATIONS_H

#include <stdexcept>  // Для исключений
#include <vector>     // Для работы с vector

// Объявление функции для вычисления произведения элементов массива
double computeProduct(const std::vector<double>& arr);

// Объявление функции для записи массива в файл
void writeArrayToFile(const std::vector<double>& arr, const char* filename);

// Объявление функции для чтения массива из файла
void readArrayFromFile(std::vector<double>& arr, const char* filename);

// Объявление функции для заполнения массива случайными числами
void fillArray(std::vector<double>& arr, double minVal, double maxVal);

// Объявление функции для вывода массива на экран
void printArray(const std::vector<double>& arr);

#endif // COMPUTATIONS_H
