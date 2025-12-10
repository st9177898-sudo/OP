#include <iostream>
using namespace std;

struct Array {
private:
    int *a;
    int n;
public:
    Array(int size) {
        n = size;
        a = new int[n];
    }
    ~Array() {
        delete[] a;
    }
    void fill() {
        for (int i = 0; i < n; i++)
            cin >> a[i];
    }
    void print() {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
};

int main() {
    int k;
    cout << "Розмiр масиву: ";
    cin >> k;
    Array arr(k);
    cout << "Введiть " << k << " елементiв: ";
    arr.fill();
    cout << "Масив: ";
    arr.print();

    return 0;
}