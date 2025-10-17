#include <iostream>
using namespace std;

int main()
{
    bool found= false;
    int arr[15];
    cout << "Введiть числа:" << endl;
    for (int i = 0; i < 15; i++)
        cin >> arr[i];
    cout << "Повторюються числа: " << endl;
    for (int i = 0; i < 15; i++)
    {
        int count = 0;
        for (int j = 0; j < 15; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        bool print = false;
        for (int k = 0; k < i; k++)
        {
            if (arr[k] == arr[i])
                print = true;
        }
        if (count > 1 && !print)
        {
            cout << arr[i] << " " << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Повторiв немає" << endl;
    return 0;
}