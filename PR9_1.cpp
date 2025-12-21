#include <iostream>
using namespace std;
class Entity {
private:
    string name;
    int hp;
    int level;
public:
    Entity(string name, int hp, int level) {
        this->name = name;
        this->hp = hp;
        this->level = level;
    }
    string getName() const { return name; }
    int getHp() const { return hp; }
    int getLevel() const { return level; }
    void takeDamage(int damage) {
        hp -= damage;
        if (hp < 0) hp = 0;
    }
    void levelUp() {
        level++;
    }
    void printInfo() const {
        cout << "Name: " << name << ", Health: " << hp << ", Level: " << level <<endl;
    }
};
int main() {
    Entity hero("sf", 100, 1);
    Entity monster("qop", 50, 1);
    hero.printInfo();
    monster.printInfo();
    monster.takeDamage(20);
    monster.printInfo();
    hero.levelUp();
    hero.printInfo();

    return 0;
}