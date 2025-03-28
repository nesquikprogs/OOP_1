#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert> // Для использования assert
#include <fstream>  // Для работы с файлами
#include <stdexcept> // Для исключений
using namespace std;

// Создаём пространство имён для модуля
namespace array_utils {

    // Функция для заполнения массива случайными числами
    void fillArray(double* arr, int size, double min, double max) {
        for (int i = 0; i < size; ++i) {
            arr[i] = min + (max - min) * (rand() / (RAND_MAX + 1.0));
        }
    }

    // Функция для вывода массива
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

    // Функция для вычисления произведения элементов массива
    double calculateProduct(const double* arr, int size) {
        double product = 1.0; // Начинаем с единицы, чтобы не обнулять произведение
        for (int i = 0; i < size; ++i) {
            product *= arr[i]; // Умножаем каждый элемент на текущее произведение
        }
        return product;
    }
    
    // Тестирование функции calculateProduct
    void testCalculateProduct() {
        // Тест 1: Массив с положительными числами
        assert(calculateProduct(new double[3]{2.0, 3.0, 4.0}, 3) == 24.0); // 2 * 3 * 4 = 24.0

        // Тест 2: Массив с нулями
        assert(calculateProduct(new double[3]{0.0, 3.0, 5.0}, 3) == 0.0); // 0 * 3 * 5 = 0.0

        // Тест 3: Массив с одним элементом
        assert(calculateProduct(new double[1]{5.0}, 1) == 5.0); // 5.0

        // Тест 4: Массив с отрицательными числами
        assert(calculateProduct(new double[3]{-2.0, 3.0, -4.0}, 3) == 24.0); // (-2) * 3 * (-4) = 24.0

        // Тест 5: Массив с одним нулём
        assert(calculateProduct(new double[1]{0.0}, 1) == 0.0); // 0.0

        // Тест 6: Массив с несколькими отрицательными числами
        assert(calculateProduct(new double[3]{-1.0, -2.0, -3.0}, 3) == -6.0); // (-1) * (-2) * (-3) = -6.0

        cout << "Все тесты прошли успешно!" << endl;
    }

    // Функция для записи массива в файл
    void writeArrayToFile(const double* arr, int size, const string& filename) {
        ofstream outFile(filename);
        if (!outFile) {
            throw runtime_error("Не удалось открыть файл для записи!");
        }

        for (int i = 0; i < size; ++i) {
            outFile << arr[i] << endl;  // Записываем каждый элемент массива в новый строку
        }
        outFile.close();
        cout << "Массив успешно записан в файл " << filename << endl;
    }

    // Функция для чтения массива из файла
    void readArrayFromFile(double* arr, int& size, const string& filename) {
        ifstream inFile(filename);
        if (!inFile) {
            throw runtime_error("Не удалось открыть файл для чтения!");
        }

        int index = 0;
        while (inFile >> arr[index]) {
            ++index;
        }
        size = index;  // Устанавливаем размер массива
        inFile.close();
        cout << "Массив успешно загружен из файла " << filename << endl;
    }
}

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    // Запускаем все тесты на вычисление произведения
    array_utils::testCalculateProduct();

    try {
        // Размер массива, вводимый пользователем
        int size;
        cout << "Введите размер массива: ";
        cin >> size; // Пользователь вводит размер массива

        // Проверка на корректность введённого размера массива
        if (size <= 0) {
            throw invalid_argument("Размер массива должен быть положительным числом!");
        }

        // Ввод минимального и максимального значений
        double min, max;
        cout << "Введите минимальное значение: ";
        cin >> min;
        cout << "Введите максимальное значение: ";
        cin >> max;

        // Проверка, чтобы максимальное значение было больше минимального
        if (min >= max) {
            throw invalid_argument("Минимальное значение должно быть меньше максимального!");
        }

        double* arr = new double[size]; // Выделяем память под массив

        // Заполняем массив случайными числами
        array_utils::fillArray(arr, size, min, max);

        // Выводим массив
        cout << "Массив элементов:" << endl;
        array_utils::printArray(arr, size);

        // Записываем массив в файл
        string filename = "array_data.txt";
        array_utils::writeArrayToFile(arr, size, filename);

        // Создаём новый массив для чтения данных из файла
        double* arrFromFile = new double[size];

        // Загружаем массив из файла
        array_utils::readArrayFromFile(arrFromFile, size, filename);

        // Выводим массив из файла
        cout << "Массив, загруженный из файла:" << endl;
        array_utils::printArray(arrFromFile, size);

        // Вычисляем произведение элементов массива
        double product = array_utils::calculateProduct(arrFromFile, size);
        cout << "Произведение элементов массива: " << product << endl;

        // Освобождаем память
        delete[] arr;
        delete[] arrFromFile;

    } catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
