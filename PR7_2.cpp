#include <iostream>
using namespace std;

struct Dish {
    string name;
    float price;
    int taste;
};
struct Cart {
    Dish items[10];
    int count;
    float total;
};
int FindTastiest(Dish dishes[], int n) {
    if (n == 0) return -1;
    int best = 0;
    for (int i = 1; i < n; i++) {
        if (dishes[i].taste > dishes[best].taste)
            best = i;
    }
    return best;
}
void ApplyDiscount(Dish &d, float percent) {
    d.price = d.price * (100.0f - percent) / 100.0f;
}
void FixName(Dish *d, const string &newName) {
    if (d) d->name = newName;
}
template <typename T>
T Limit(T v, T mn, T mx) {
    if (v < mn) return mn;
    if (v > mx) return mx;
    return v;
}
void RecalcTotal(Cart &c) {
    c.total = 0;
    for (int i = 0; i < c.count; i++)
        c.total += c.items[i].price;
}
Cart CopyCart(const Cart &c) {
    Cart copy = c;
    return copy;
}
void PrintDish(const Dish &d) {
    cout << d.name << "  Цiна: " << d.price << "  Смачнiсть: " << d.taste << endl;
}
void PrintCart(const Cart &c) {
    cout << "Кошик " << c.count << " позицiй, разом: " << c.total << endl;
    for (int i = 0; i < c.count; i++)
        PrintDish(c.items[i]);
}

int main() {
    int n;
    cout << "Кiлькiсть страв у меню: " << endl;
    cin >> n;
    if (n > 10) n = 10;
    Dish menu[10];
    for (int i = 0; i < n; i++) {
        cout << "Страва " << i + 1 << endl;
        cout << "Назва: ";
        cin >> menu[i].name;
        cout << "Цiна: ";
        cin >> menu[i].price;
        cout << "Оцiнка (0-100): ";
        cin >> menu[i].taste;
        cout << endl;
    }
    cout << "Меню: "<<endl;
    for (int i = 0; i < n; i++)
        PrintDish(menu[i]);
    int best = FindTastiest(menu, n);
    if (best != -1) {
        cout << "Найсмачнiша страва: "<<endl;
        PrintDish(menu[best]);
    }
    Cart cart;
    cart.count = 0;
    cart.total = 0;
    int k;
    cout << "Скiльки страв додати у кошик (до " << n << "): "<<endl;
    cin >> k;
    if (k > n) k = n;
    if (k > 10) k = 10;
    for (int i = 0; i < k; i++) {
        cart.items[i] = menu[i];
    }
    cart.count = k;
    RecalcTotal(cart);

    cout << "Початковий кошик: "<<endl;
    PrintCart(cart);
    if (cart.count > 0) {
        cout << "Застосувати знижку 20% до першої страви."<<endl;
        ApplyDiscount(cart.items[0], 20.0f);
        cart.items[0].price = Limit(cart.items[0].price, 0.0f, 1000.0f);
        RecalcTotal(cart);
    }
    if (cart.count > 1) {
        cout << "Виправляємо назву другої страви."<<endl;
        FixName(&cart.items[1], "Special");
    }
    cout << "Кошик пiсля акцiй:"<<endl;
    PrintCart(cart);
    cout << "Створюємо копiю кошика для промоакцiї."<<endl;
    Cart promoCart = CopyCart(cart);
    cout << "Копiя кошика: "<<endl;
    PrintCart(promoCart);

    return 0;
}