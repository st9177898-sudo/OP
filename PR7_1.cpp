#include <iostream>
using namespace std;

struct Player {
    string name;
    int hp;
    int xp;
    int potions;
};
void PrintPlayer(Player p) {
    cout << p.name << " HP=" << p.hp << " XP=" << p.xp << " Potions=" << p.potions << endl;
}
void Heal(Player &p, int amount) {
    if (p.potions > 0) {
        p.hp += amount;
        p.potions--;
    }
}
void GainXP(Player *p, int amount) {
    if (p) p->xp += amount;
}
template <typename T>
T Clamp(T v, T mn, T mx) {
    if (v < mn) return mn;
    if (v > mx) return mx;
    return v;
}
Player Duplicate(const Player &p) {
    Player c = p;
    c.name = p.name + "_copy";
    return c;
}
int main() {
    Player p1;
    Player p2 = Duplicate(p1);
    cout << "Введiть першого iм'я героя: " << endl;
    cin >> p1.name;
    cout << "Введiть першого зроров'я героя: " << endl;
    cin >> p1.hp;
    cout << "Введiть першого досвiд героя: " << endl;
    cin >> p1.xp;
    cout << "Введiть кiлькiсть зiлля першого героя: " << endl;
    cin >> p1.potions;
    cout << "Введiть другого iм'я героя: " << endl;
    cin >> p2.name;
    cout << "Введiть другого зроров'я героя: " << endl;
    cin >> p2.hp;
    cout << "Введiть другого досвiд героя: " << endl;
    cin >> p2.xp;
    cout << "Введiть кiлькiсть зiлля другого героя: " << endl;
    cin >> p2.potions;
    PrintPlayer(p1);
    PrintPlayer(p2);
    Heal(p1, 20);
    PrintPlayer(p1);
    GainXP(&p1, 15);
    PrintPlayer(p1);
    p1.hp = Clamp(p1.hp, 0, 100);
    PrintPlayer(p1);

    return 0;
}