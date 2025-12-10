#include <iostream>
#include <vector>
using namespace std;

struct material
{
    string name;
    vector<int> daily;
    int total;
    float avg;
    int fluct;
};
int main()
{
    int mtcount, days;
    cout << "Кiлькiть матерiалiв: " << endl;
    cin >> mtcount;
    cout << "Кiлькiсть днiв: " << endl;
    cin >> days;
    vector<material> mats(mtcount);
    for (int i = 0; i < mtcount; i++)
    {
        cout << "Назва матерiалу: " << i + 1 << ": ";
        cin >> mats[i].name;
        mats[i].daily.resize(days);
        cout << "Введiть: " << days << " значень для " << mats[i].name <<": "<<  endl;
        for (int j = 0; j < days; j++)
            cin >> mats[i].daily[j];
    }
    float threshold;
    cout << "Порiг для дефiциту: " <<endl;
    cin >> threshold;
    for (int i = 0; i < mtcount; i++)
    {
        int sum = 0;
        int mn = mats[i].daily[0];
        int mx = mats[i].daily[0];
        for ( int j : mats[i].daily)
        {
            sum += j;
            if (j < mn) mn = j;
            if (j > mx) mx = j;
        }
        mats[i].total = sum;
        mats[i].avg = (float)sum / days;
        mats[i].fluct = mx - mn;
    }
    for (int i = 0; i < mtcount; i++)
    {
        cout << "Матерiал: " << mats[i].name << endl;
        cout << "Сумарний обсяг: " << mats[i].total << endl;
        cout << "Середнiй обсяг: " << mats[i].avg << endl;
        cout << "Коливання: " << mats[i].fluct << endl<<endl;
    }
    int max1 = -1, max2 = -1, max3 = -1;
    int id1 = -1, id2 = -1, id3 = -1;
    for (int i = 0; i < mtcount; i++)
    {
        int t = mats[i].total;
        if (t > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = t;
            id3 = id2;
            id2 = id1;
            id1 = i;
        }
        else if (t > max2)
        {
            max3 = max2;
            max2 = t;
            id3 = id2;
            id2 = i;
        }
        else if (t > max3)
        {
            max3 = t;
            id3 = i;
        }
    }
    cout << "Три матерiали за найбiльшим обсягом: " << endl;
    if (id1 != -1)
        cout << "1 - " << mats[id1].name << ": "<<mats[id1].total << endl;
    if (id2 != -1)
        cout << "2 - " << mats[id2].name << ": "<<mats[id2].total << endl;
    if (id3 != -1)
        cout << "3 - " << mats[id3].name << ": "<<mats[id3].total << endl;
    cout << "Дефiцитнi матерiали: " << endl;
    bool any = false;
    for (int i = 0; i < mtcount; i++)
    {
        if (mats[i].avg < threshold)
        {
            any = true;
            cout << mats[i].name << " = " << mats[i].avg << endl;
        }
    }
    if (!any)
        cout << "Немає Дефiцитних" <<endl;

    return 0;
}