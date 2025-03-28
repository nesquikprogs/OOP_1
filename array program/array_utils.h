#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <vector>
#include <string>

namespace array_utils { // Пространство имен для модуля

    // Заполнение массива случайными числами
    // Аргументы - указатель на массив, размер, мин.знач, макс.знач
    void fillArray(std::vector<double>& arr, double min, double max);

    // Вывод массива
    // Аргументы - указатель на массив, размер
    void printArray(const std::vector<double>& arr);

    // Перемножение элементов массива
    // Аргументы - указатель на массив, размер
    double calculateProduct(const std::vector<double>& arr);

    // Тесты ассертами
    void testCalculateProduct();

    // Запись в файл
    // Аргументы - указатель на массив, размер, имя файла
    void writeArrayToFile(const std::vector<double>& arr, const std::string& filename);

    // Чтение из файла
    // Аргументы - указатель на массив, размер, имя файла
    void readArrayFromFile(std::vector<double>& arr, const std::string& filename);

}

#endif
