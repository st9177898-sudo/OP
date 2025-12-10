#include <iostream>
using namespace std;

int main()
{
    int m;
    cout << "Довжина подiй m: ";
    cin >> m;
    int *a = new int[m];
    cout << "Введiть " << m << " кодiв подiй (-1, 0, 1, 2):"<<endl;
    int *p = a;
    while (p < a + m)
    {
        cin >> *p;
        p++;
    }
    cout << "Початковий масив подiй: " <<endl;
    p = a;
    while (p < a + m)
    {
        cout << *p << " ";
        p++;
    }
    cout << endl;
    int balance = 0;
    int *writeptr = a;
    int newlen = 0;
    int bestlen = 0;
    int beststart = -1;
    int bestend = -1;
    int curlen = 0;
    int curstart = 0;
    int ammopfx = 0;
    int idx = 0;
    for (int *r = a; r < a + m; r++)
    {
        int x = *r;
        if (x == -1) balance--;
        else if (x == 1) balance++;
        if (x !=0){
            *writeptr = x;
            int delta = 0;
            if (x == 1) delta = 1;
            else if (x == 2) delta = -1;
            ammopfx += delta;
            if (ammopfx < 0)
            {
                ammopfx = 0;
                curlen = 0;
                curstart = idx + 1;
            }
            else
            {
                curlen++;
                if (curlen > bestlen)
                {
                    bestlen = curlen;
                    beststart = curstart;
                    bestend = idx;
                }
            }
            writeptr++;
            newlen++;
            idx++;
        }
    }
    cout << "Стислий журнал: " <<endl;
    for (int i = 0; i < newlen; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "Баланс постачання: " << balance <<endl;
    if (bestlen > 0)
    {
        cout << "Найдовший фрагмент, де префiксна сума по боєприпасах жодного разу не стає вiд'ємною:" << endl;
        cout << "Довжина: " << bestlen << endl;
        cout << "Початок: позицiя " << (beststart + 1) << ", кiнець, позицiя " <<(bestend + 1) <<endl;
    }
    else
        cout << "Немає фрагмента, де  префiксна сума по поєприпасах нiколи не є вiд'ємною" << endl;
    delete [] a;

    return 0;
}