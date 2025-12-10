#include <iostream>
using namespace std;

struct Car {
    string model;
    int mileage;
    int fuel;
    int speed;
    bool active;
};
void ChangeSpeed(Car &c, int d) {
    c.speed += d;
    if (c.speed < 0) c.speed = 0;
}
void Refuel(Car *c, int amount) {
    if (c) c->fuel += amount;
}
Car CopyCar(Car c) {
    c.model = c.model + "_copy";
    return c;
}
template <typename T>
int MaxIndex(T a[], int n) {
    if (n == 0) return -1;
    int b = 0;
    for (int i = 1; i < n; i++)
        if (a[i] > a[b]) b = i;
    return b;
}
void Print(const Car &c) {
    cout << c.model << " " << c.mileage << " " << c.fuel << " " << c.speed << " " << c.active << endl;
}

int main() {
    int n;
    cout << "Кiлькiсть авто: "<< endl;
    cin >> n;
    Car x[100];
    for (int i = 0; i < n; i++) {
        cout << "Авто " << i << endl;
        cout << "Модель: ";
        cin >> x[i].model;
        cout << "Пробiг: ";
        cin >> x[i].mileage;
        cout << "Паливо: ";
        cin >> x[i].fuel;
        cout << "Швидкiсть: ";
        cin >> x[i].speed;
        cout << "Стан (1 активне, 0 сервiс): ";
        cin >> x[i].active;
        cout << endl;
    }
    int id, d;
    cout << "Номер авто для змiни швидкостi: ";
    cin >> id;
    cout << "На скiльки змiнити швидкiсть: ";
    cin >> d;
    ChangeSpeed(x[id], d);
    int id2, f;
    cout << "Номер авто для заправки: ";
    cin >> id2;
    cout << "Скiльки додати палива: ";
    cin >> f;
    Refuel(&x[id2], f);
    int id3;
    cout << "Номер авто для створення копiї: ";
    cin >> id3;
    Car c2 = CopyCar(x[id3]);
    cout << "Копiя: ";
    Print(c2);
    int m[100], s[100];
    for (int i = 0; i < n; i++) {
        m[i] = x[i].mileage;
        s[i] = x[i].speed;
    }
    int mi = MaxIndex(m, n);
    int si = MaxIndex(s, n);
    cout << "Найбiльший пробiг: ";
    Print(x[mi]);
    cout << "Найвища швидкiсть: ";
    Print(x[si]);

    return 0;
}