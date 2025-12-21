#include <iostream>

using namespace std;
class Entity {
private:
    string name;
    int hp;
    int lvl;
    static int count;
public:
    Entity(string name, int hp, int lvl) {
        this->name = name;
        this->hp = hp;
        this->lvl = lvl;
        count++;
    }
    ~Entity() {
        count--;
    }
    void printInfo() const {
        cout << "Name: " << name
             << ", Health: " << hp
             << ", Level: " << lvl << endl;
    }
    static int getCount() {
        return count;
    }
};
int Entity::count = 0;

int main() {
    cout << "Кількість об'єктів: " << Entity::getCount() << endl;
    Entity hero("Knight", 100, 1);
    Entity monster("Goblin", 50, 1);
    cout << "Кількість об'єктів після створення: " << Entity::getCount() << endl;
    {
        Entity npc("Villager", 30, 1);
        cout << "Кількість об'єктів після створення NPC: " << Entity::getCount() << endl;
    }
    cout << "Кількість об'єктів після видалення NPC: " << Entity::getCount() << endl;

    return 0;
}