#include "computations.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>  // Для контроля вывода

namespace ArrayUtils {

    // Функция для вычисления произведения элементов массива
    double computeProduct(const double* arr, int size) {
        double product = 1.0;
        for (int i = 0; i < size; i++) {
            product *= arr[i];
        }
        return product;
    }

    // Функция для заполнения массива случайными числами в заданном диапазоне
    void fillArray(double* arr, int size, double minVal, double maxVal) {
        for (int i = 0; i < size; i++) {
            arr[i] = minVal + (maxVal - minVal) * (rand() / (double)RAND_MAX);
        }
    }

    // Функция для вывода массива на экран по 10 элементов в строке
    void printArray(const double* arr, int size) {
        for (int i = 0; i < size; i++) {
            // Выводим 10 элементов в строке
            std::cout << std::fixed << std::setprecision(2) << arr[i] << " "; // Ограничиваем вывод до 2 знаков после запятой
            if ((i + 1) % 10 == 0) {
                std::cout << std::endl; // Перенос строки после 10-го элемента
            }
        }
        // Если осталось меньше 10 элементов, все равно завершаем вывод новой строкой
        if (size % 10 != 0) {
            std::cout << std::endl;
        }
    }

}
