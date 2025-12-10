#include <iostream>
using namespace std;

namespace MyTools {
    bool valid(int m) {
        return m >= 0 && m <= 12;
    }
}

int main() {
    int mark;
    cout << "Введiть оцiнку (0-12): ";
    cin >> mark;
    if (!cin)
    {
        cout<< "Помилка, введiть число" << endl;
        return 0;
    }
    if (MyTools::valid(mark))
        cout << "Оцiнка коректна" << endl;
    else
        cout << "Некоректна оцiнка" << endl;

    return 0;
}