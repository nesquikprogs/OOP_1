#ifndef COMPUTATIONS_H
#define COMPUTATIONS_H

// Объявление функции для вычисления произведения элементов массива
double computeProduct(const double* arr, int size);

// Объявление функции для записи массива в файл
void writeArrayToFile(const double* arr, int size, const char* filename);

// Объявление функции для чтения массива из файла
void readArrayFromFile(double* arr, int& size, const char* filename);

// Объявление функции для заполнения массива случайными числами
void fillArray(double* arr, int size, double minVal, double maxVal);

// Объявление функции для вывода массива на экран
void printArray(const double* arr, int size);

#endif // COMPUTATIONS_H
