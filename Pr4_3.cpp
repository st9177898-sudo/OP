#include <iostream>
using namespace std;

int main()
{
    const int N = 7;
    int harvest[N];
    for (int i = 0; i < N; i++)
        cin >> harvest[i];
    int maxhar = harvest[0];
    int maxday = 0;
    for (int i = 1; i < N; i++)
        if (harvest[i] > maxhar)
        {
            maxhar = harvest[i];
            maxday = i;
        }
    cout << "Найбiльший врожай: " << maxhar << " кг" << endl;
    cout << "День з найбiльшим врожаєм: " << maxday + 1 << endl;

    return 0;
}