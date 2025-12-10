#include <iostream>
using namespace std;

int main()
{
    const int N = 10;
    int res[N];
    for (int i = 0; i < N; i++)
        cin >> res[i];
    int high = 0, good = 0, mid = 0, low = 0;
    int sumhigh = 0, sumgood = 0,summid = 0, sumlow = 0;
    int maxhigh = -1, maxgood = -1, maxmid = -1, maxlow = -1;
    for (int i = 0; i < N; i++)
    {
        int x = res[i];
        if (x > 160)
        {
            high++;
            sumhigh += x;
            if (x > maxhigh) maxhigh = x;
        }
        else if (x > 140)
        {
            good++;
            sumgood += x;
            if (x > maxgood) maxgood = x;
        }
        else if (x > 120)
        {
            mid++;
            summid += x;
            if (x > maxmid) maxmid = x;
        }
        else
        {
            low++;
            sumlow += x;
            if (x > maxlow) maxlow = x;
        }
    }
    if (high > 0)
    {
        float avghigh = (float)sumhigh / high;
        cout << "Високий дiапазон: " <<endl;
        cout << "Найкращий результат: " << maxhigh << " см" <<endl;
        cout << "Середнє значення: " << avghigh << " см" <<endl;
    }
        else
            cout << "Немає результатiв у високому дiапазонi" <<endl;
    if (good > 0)
    {
        float avggood = (float)sumgood / good;
        cout << "Достатнiй дiапазон: " <<endl;
        cout << "Найкращий результат: " << maxgood << " см" <<endl;
        cout << "Середнє значення: " << avggood << " см" <<endl;
    }
    else
        cout << "Немає результатiв у достатньому дiапазонi" <<endl;
    if (mid > 0)
    {
        float avgmid = (float)summid / mid;
        cout << "Середнiй дiапазон: " <<endl;
        cout << "Найкращий результат: " << maxmid << " см" <<endl;
        cout << "Середнє значення: " << avgmid << " см" <<endl;
    }
    else
        cout << "Немає результатiв у середньому дiапазонi" <<endl;
    if (high > 0)
    {
        float avglow = (float)sumlow / low;
        cout << "Низький дiапазон: " <<endl;
        cout << "Найкращий результат: " << maxlow << " см" <<endl;
        cout << "Середнє значення: " << avglow << " см" <<endl;
    }
    else
        cout << "Немає результатiв у низькому дiапазонi" <<endl;
    return 0;
}