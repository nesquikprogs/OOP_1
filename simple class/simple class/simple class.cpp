#include <string>
#include <iostream>

using namespace std;

class Character {
private:
    string name;
    int health;
    int level;

public:
    // Геттеры
    string getName() const {
        return name;
    }

    int getHealth() const {
        return health;
    }

    int getLevel() const {
        return level;
    }

    // Сеттеры
    void setName(const string& newName) {
        name = newName;
    }

    void setHealth(int newHealth) {
        health = newHealth;
    }

    void setLevel(int newLevel) {
        level = newLevel;
    }

    // Метод для отображения информации о персонаже
    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Level: " << level << endl;
    }
};

int main() {

    // Создание персонажа с помощью конструктора по умолчанию
    Character enemy;
    enemy.setName("Orc");
    enemy.setHealth(80);
    enemy.setLevel(2);
    enemy.displayInfo();

    return 0;
}