#include <iostream>
#include <vector>

using namespace std;
class entity {
protected:
    string name;
    int hp;
public:
    entity(string name, int hp) {
        this->name = name;
        this->hp = hp;
    }
    virtual void attack() = 0;
    virtual void printInfo() const {
        cout << "Name: " << name << ", Health: " << hp << endl;
    }
    virtual ~entity() {}
};
class Hero : public entity {
private:
    int level;
public:
    Hero(string name, int hp, int level) : entity(name, hp) {
        this->level = level;
    }
    void attack() override {
        cout << name << " атакує мечем!" << endl;
    }
    void printInfo() const override {
        cout << "Hero: " << name << ", Health: " << hp << ", Level: " << level << endl;
    }
};
class Monster : public entity {
private:
    string type;
public:
    Monster(string name, int hp, string type) : entity(name, hp) {
        this->type = type;
    }
    void attack() override {
        cout << name << " кидає вогняний шар!" << endl;
    }
    void printInfo() const override {
        cout << "Monster: " << name << ", Health: " << hp << ", Type: " << type << endl;
    }
};

int main() {
    vector<entity*> entities;
    Hero* hero = new Hero("Knight", 100, 5);
    Monster* monster = new Monster("Goblin", 50, "Earth");
    entities.push_back(hero);
    entities.push_back(monster);
    for (entity* e : entities) {
        e->printInfo();
        e->attack();
    }
    for (entity* e : entities) {
        delete e;
    }

    return 0;
}