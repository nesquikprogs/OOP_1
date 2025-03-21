#include "computations.h"

// Функция для вычисления произведения элементов массива
double computeProduct(const double* arr, int size) {
    double product = 1.0;
    for (int i = 0; i < size; i++) {
        product *= arr[i];
    }
    return product;
}
