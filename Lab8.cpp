#include <iostream>
using namespace std;

struct order {
private:
    int quantity;
    double price;
public:
    static int count;
    order(int q, double p) {
        this->quantity = q;
        this->price = p;
        count++;
    }
    ~order() {
        count--;
    }
    int getquan() {
        return quantity;
    }
    void setquan(int q) {
        if(q >= 0) {
            quantity = q;
        }
    }
    double getPrice() {
        return price;
    }
    void setprice(double p) {
        if(p >= 0) {
            price = p;
        }
    }
    static void showcount() {
        cout << "Кількість об'єктів Order: " << count << endl;
    }
    bool isquaneven() {
        if(quantity == 0) return true;
        if(quantity == 1) return false;
        order temp(quantity - 2, price);
        return temp.isquaneven();
    }
    void display() {
        cout << "Quantity: " << quantity << ", Price: " << price << endl;
    }
};
int order::count = 0;

int main() {
    int q;
    double p;
    cout << "Введіть quantity для першого замовлення: ";
    cin >> q;
    cout << "Введіть price для першого замовлення: ";
    cin >> p;
    order o1(q, p);
    cout << "Введіть quantity для другого замовлення: ";
    cin >> q;
    cout << "Введіть price для другого замовлення: ";
    cin >> p;
    order o2(q, p);
    cout << "o1 quantity парне? " << (o1.isquaneven() ? "Так" : "Ні") << endl;
    cout << "o2 quantity парне? " << (o2.isquaneven() ? "Так" : "Ні") << endl;
    order::showcount();

    return 0;
}