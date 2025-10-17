#include <iostream>
using namespace std;

int main()
{
    int N;
    cout << "Введiть кiлькiсть елементiв"<< endl;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = N - 1; i >= 0; i--)
    {
        if (arr[i] > 0)
        {
            cout << "Останнiй додатний елемент массиву - " << arr[i] << endl;
        }
    }
    return 0;
}