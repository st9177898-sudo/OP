#include <iostream>
using namespace std;

int main()
{
    int N, mask;
    cout << "Введiть кiлькiсть чисел: ";
    cin >> N;
    cout << "Введiть маску: ";
    cin >> mask;
    for (int i = 0; i < N; i++)
    {
        int x;
        cout << "Введiть число: ";
        cin >> x;
        cout << "Вiдсутнi бiти в числi " << x << ": ";
        for (int bit = 0; bit < 32; bit++)
        {
            if ((mask & (1 << bit)) != 0 && (x & (1 << bit)) == 0)
            {
                cout << bit << " ";
            }
        }
    }
}