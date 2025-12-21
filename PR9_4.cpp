#include <iostream>

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
    virtual void printInfo() const {
        cout << name << " | HP: " << hp << endl;
    }
    virtual ~entity() {}
    void takeDamage(int dmg) {
        hp -= dmg;
        if (hp < 0) hp = 0;
    }
    void heal(int amount) {
        hp += amount;
    }
    string getName() const {
        return name;
    }
};
class hero : public entity {
private:
    int level;
public:
    hero(string name, int hp, int level) : entity(name, hp) {
        this->level = level;
    }
    void attack(entity& target) {
        cout << name << " атакує " << target.getName() << " на " << level * 10 << " HP!" << endl;
        target.takeDamage(level * 10);
    }
    void healSelf(int amount) {
        cout << name << " лікується на " << amount << " HP!" << endl;
        heal(amount);
    }
    void printInfo() const override {
        cout << "Hero: " << name << " | HP: " << hp << " | Level: " << level << endl;
    }
};
class monster : public entity {
private:
    string type;
public:
    monster(string name, int hp, string type) : entity(name, hp) {
        this->type = type;
    }
    void attack(entity& target) {
        cout << name << " (" << type << ") атакує " << target.getName() << " на 15 HP!" << endl;
        target.takeDamage(15);
    }
    void printInfo() const override {
        cout << "Monster: " << name << " | HP: " << hp << " | Type: " << type << endl;
    }
};

int main() {
    hero myHero("Knight", 100, 3);
    monster myMonster("Goblin", 60, "Earth");
    myHero.printInfo();
    myMonster.printInfo();
    cout << endl;
    myHero.attack(myMonster);
    myMonster.printInfo();
    cout << endl;
    myMonster.attack(myHero);
    myHero.printInfo();
    cout << endl;
    myHero.healSelf(20);
    myHero.printInfo();

    return 0;
}