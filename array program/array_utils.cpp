#include "array_utils.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <cassert>
#include <vector>

using namespace std;

namespace array_utils { // Пространство имен для модуля

    // Заполнение массива случайными числами
    // Аргументы - указатель на массив, размер, мин.знач, макс.знач
    void fillArray(vector<double>& arr, double min, double max) {
        for (size_t i = 0; i < arr.size(); ++i) {
            arr[i] = min + (max - min) * (rand() / (RAND_MAX + 1.0));
        }
    }

    // Вывод массива
    // Аргументы - указатель на массив, размер
    void printArray(const vector<double>& arr) {
        for (size_t i = 0; i < arr.size(); ++i) {
            cout.width(8); // Выделяем место для выравнивания чисел
            cout << arr[i] << " ";
            if ((i + 1) % 10 == 0) {
                cout << endl;
            }
        }
        cout << endl;
    }

    // Перемножение элементов массива
    // Аргументы - указатель на массив, размер
    double calculateProduct(const vector<double>& arr) {
        double product = 1.0;
        for (size_t i = 0; i < arr.size(); ++i) {
            product *= arr[i];
        }
        return product;
    }

    // Тесты ассертами
    void testCalculateProduct() {
        assert(calculateProduct(vector<double>{2.0, 3.0, 4.0}) == 24.0);
        assert(calculateProduct(vector<double>{0.0, 3.0, 5.0}) == 0.0);
        assert(calculateProduct(vector<double>{5.0}) == 5.0);
        assert(calculateProduct(vector<double>{-2.0, 3.0, -4.0}) == 24.0);
        assert(calculateProduct(vector<double>{0.0}) == 0.0);
        assert(calculateProduct(vector<double>{-1.0, -2.0, -3.0}) == -6.0);
        cout << "Все тесты прошли успешно!" << endl;
    }

    // Запись в файл
    // Аргументы - указатель на массив, размер, имя файла
    void writeArrayToFile(const vector<double>& arr, const string& filename) {
        ofstream outFile(filename);
        if (!outFile) {
            throw runtime_error("Не удалось открыть файл для записи!");
        }

        for (size_t i = 0; i < arr.size(); ++i) {
            outFile << arr[i] << endl;
        }
        outFile.close();
        cout << "Массив успешно записан в файл " << filename << endl;
    }

    // Чтение из файла
    // Аргументы - указатель на массив, размер, имя файла
    void readArrayFromFile(vector<double>& arr, const string& filename) {
        ifstream inFile(filename);
        if (!inFile) {
            throw runtime_error("Не удалось открыть файл для чтения!");
        }

        size_t index = 0;
        while (inFile >> arr[index]) {
            ++index;
        }
        inFile.close();
        cout << "Массив успешно загружен из файла " << filename << endl;
    }

}
