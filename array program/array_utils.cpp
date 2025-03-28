#include "array_utils.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <cassert> 

using namespace std;

namespace array_utils { // Пространство имен для модуля

    // Заполнение массива случайными числами
    // Аргуменыты - указатель на массив, размер, мин.знач, макс.знач
    void fillArray(double* arr, int size, double min, double max) {
        for (int i = 0; i < size; ++i) {
            arr[i] = min + (max - min) * (rand() / (RAND_MAX + 1.0));
        }
    }

    // Вывод массива
    // Аргуменыты - указатель на массив, размер
    void printArray(const double* arr, int size) {
        for (int i = 0; i < size; ++i) {
            cout.width(8); // Выделяем место для выравнивания чисел
            cout << arr[i] << " ";
            if ((i + 1) % 10 == 0) {
                cout << endl;
            }
        }
        cout << endl;
    }

    // Перемножение элементов массива
    // Аргуменыты - указатель на массив, размер
    double calculateProduct(const double* arr, int size) {
        double product = 1.0;
        for (int i = 0; i < size; ++i) {
            product *= arr[i];
        }
        return product;
    }

    
    // Тесты ассертами
    void testCalculateProduct() {
        assert(calculateProduct(new double[3]{2.0, 3.0, 4.0}, 3) == 24.0);
        assert(calculateProduct(new double[3]{0.0, 3.0, 5.0}, 3) == 0.0);
        assert(calculateProduct(new double[1]{5.0}, 1) == 5.0);
        assert(calculateProduct(new double[3]{-2.0, 3.0, -4.0}, 3) == 24.0);
        assert(calculateProduct(new double[1]{0.0}, 1) == 0.0);
        assert(calculateProduct(new double[3]{-1.0, -2.0, -3.0}, 3) == -6.0);
        cout << "Все тесты прошли успешно!" << endl;
    }

    // Запись в файл
    // Аргуменыты - указатель на массив, размер, имя файла
    void writeArrayToFile(const double* arr, int size, const string& filename) {
        ofstream outFile(filename);
        if (!outFile) {
            throw runtime_error("Не удалось открыть файл для записи!");
        }

        for (int i = 0; i < size; ++i) {
            outFile << arr[i] << endl;
        }
        outFile.close();
        cout << "Массив успешно записан в файл " << filename << endl;
    }

    // Чтение из файла
    // Аргуменыты - указатель на массив, размер, имя файла
    void readArrayFromFile(double* arr, int& size, const string& filename) {
        ifstream inFile(filename);
        if (!inFile) {
            throw runtime_error("Не удалось открыть файл для чтения!");
        }

        int index = 0;
        while (inFile >> arr[index]) {
            ++index;
        }
        size = index;
        inFile.close();
        cout << "Массив успешно загружен из файла " << filename << endl;
    }

}
