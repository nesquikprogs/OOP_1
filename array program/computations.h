#ifndef COMPUTATIONS_H
#define COMPUTATIONS_H

namespace ArrayUtils {
    // Объявление функции вычисления произведения элементов массива
    double computeProduct(const double* arr, int size);
    
    // Объявление функции для заполнения массива случайными числами
    void fillArray(double* arr, int size, double minVal, double maxVal);

    // Объявление функции для вывода массива
    void printArray(const double* arr, int size);
}

#endif // COMPUTATIONS_H
