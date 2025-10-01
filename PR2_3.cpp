#include <iostream>
using namespace std;

int main()
{
    int x, pattern;
    cout << "Введiть число x: ";
    cin >> x;
    cout << "Введiть маску pattern: ";
    cin >> pattern;
    if ((x & pattern) == pattern)
        cout << "У x встановленi всi бiти з маски pattern"<< endl;
    else
        cout << "У x не всi бiти з маски pattern" << endl;

    return 0;
}