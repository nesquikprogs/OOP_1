#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "computations.h"
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8"); // Установка русской локали для вывода текста в консоль
    srand(time(0)); // Инициализация генератора случайных чисел

    try {
        // Пример записи и чтения массива из файла
        size_t n;

        cout << "Введите количество элементов массива: ";
        cin >> n;

        if (n <= 0) {
            throw invalid_argument("Количество элементов массива должно быть положительным.");
        }

        // Используем vector вместо обычного массива
        vector<double> arr(n);

        // Заполнение массива случайными числами
        fillArray(arr, 1.0, 10.0);

        // Вывод массива
        cout << "Сгенерированный массив: " << endl;
        printArray(arr);

        // Записываем массив в файл
        writeArrayToFile(arr, "array_data.txt");

        // Очистка массива
        arr.clear();

        // Чтение массива из файла
        cout << "\nЧтение массива из файла:" << endl;
        readArrayFromFile(arr, "array_data.txt");

        // Вывод массива из файла
        cout << "Массив из файла: " << endl;
        printArray(arr);

        // Вычисление и вывод произведения элементов
        cout << "Произведение элементов массива: " << computeProduct(arr) << endl;

    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
