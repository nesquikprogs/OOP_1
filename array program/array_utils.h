#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <string>

namespace array_utils { // Пространство имен для модуля

    // Объявление функций
    
    // Заполнение массива случайными числами
    // Аргуменыты - указатель на массив, размер, мин.знач, макс.знач
    void fillArray(double* arr, int size, double min, double max);

    // Вывод массива
    // Аргуменыты - указатель на массив, размер
    void printArray(const double* arr, int size);

    // Перемножение элементов массива
    // Аргуменыты - указатель на массив, размер
    double calculateProduct(const double* arr, int size);

    // Тесты ассертами
    void testCalculateProduct();

    // Запись в файл
    // Аргуменыты - указатель на массив, размер, имя файла
    void writeArrayToFile(const double* arr, int size, const std::string& filename);

    // Чтение из файла
    // Аргуменыты - указатель на массив, размер, имя файла
    void readArrayFromFile(double* arr, int& size, const std::string& filename);

}

#endif 
