#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Введіть кількість рядків: ";
    cin >> n;
    cout << "Введіть кількість стовпців: ";
    cin >> m;
    int a[50][50];
    int zeroCount = 0;
    cout << "Введіть елементи матриці по рядках:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                zeroCount++;
            }
        }
    }
    int total = n * m;
    double percent = (float)zeroCount * 100 / total;
    cout << endl;
    cout << "Кількість нульових елементів: " << zeroCount << endl;
    cout << "Відсоток нулів від загальної кількості: " << percent << "%" << endl;

    return 0;
}