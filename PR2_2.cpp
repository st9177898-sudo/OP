#include <iostream>
using namespace std;

int main(){
    int N, first, len = 1, maxlen = 1;
    cout << "Введiть кiлькiсть чисел: ";
    cin >> N;
    if (N <= 0) {
        cout << 0;
        return 0;
    }
    cout << "Введiть перше число: ";
    cin >> first;
    for (int i = 1; i < N; i++){
        int num;
        cin >> num;
        if (num == first)
            len++;
        else
            {
            if (len > maxlen)
                maxlen = len;
            len = 1;
            first = num;
            }
    }
    cout << "Найбiльша серiя: " << maxlen << endl;

    return 0;
}