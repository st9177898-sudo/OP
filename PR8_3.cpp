#include <iostream>
using namespace std;

struct Number {
private:
    int value;
    int sumDigRec(int x) const {
        if (x < 0) x = -x;
        if (x < 10) return x;
        return x % 10 + sumDigRec(x / 10);
    }
public:
    Number(int v = 0) {
        this->value = v;
    }
    void setValue(int v) {
        this->value = v;
    }
    int getValue() const {
        return value;
    }
    int sumDig() const {
        return sumDigRec(this->value);
    }
};

int main() {
    int n;
    cout << "Введiть число: ";
    cin >> n;
    Number num(n);
    cout << "Сума цифр: " << num.sumDig() << endl;

    return 0;
}