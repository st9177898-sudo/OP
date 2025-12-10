#include <iostream>
using namespace std;

int main()
{
    const int N = 7;
    int temp[N];
    for (int i = 0; i < N; i++)
        cin >> temp[i];
    int max = temp[0];
    int min = temp[0];
    int maxday = 0;
    int minday = 0;
    int sum = temp[0];
    for (int i = 1; i < N; i++)
    {
        sum += temp[i];
        if (temp[i] > max)
        {
            max = temp[i];
            maxday = i;
        }
        if (temp[i] < min)
        {
            min = temp[i];
            minday = i;
        }
    }
    float average = (float)sum / N;
    int aboveAverage = 0;
    for (int i = 0; i < N; i++)
    {
        if (temp[i] > average)
            aboveAverage++;
    }
    cout << "Найвища температура: " << max << " день - " << maxday + 1 << endl;
    cout << "Найнижча температура: " << min << " день - " << minday + 1 << endl;
    cout << "Середня температура: " << average << endl;
    cout << "Днiв вище середньої: " << aboveAverage << endl;
}