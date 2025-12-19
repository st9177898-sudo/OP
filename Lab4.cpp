#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Введіть кількість рядків матриці: ";
    cin >> n;
    cout << "Введіть кількість стовпців матриці: ";
    cin >> m;
    int a[50][50];
    cout << "Введіть елементи матриці по рядках:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    int maxSum = a[0][0];
    int top = 0, bottom = 0, left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        int temp[50] = {0};
        for (int j = i; j < n; j++) {
            for (int k = 0; k < m; k++) {
                temp[k] += a[j][k];
            }

            int curSum = temp[0];
            int startCol = 0;

            for (int k = 0; k < m; k++) {
                if (k == 0 || curSum < 0) {
                    curSum = temp[k];
                    startCol = k;
                }
                else
                    curSum += temp[k];
                if (curSum > maxSum) {
                    maxSum = curSum;
                    top = i;
                    bottom = j;
                    left = startCol;
                    right = k;
                }
            }
        }
    }
    cout << endl;
    cout << "Максимальна сума елементів підматриці: " << maxSum << endl;
    cout << "Підматриця знаходиться:" << endl;
    cout << "Верхній рядок: " << top << endl;
    cout << "Нижній рядок: " << bottom << endl;
    cout << "Лівий стовпець: " << left << endl;
    cout << "Правий стовпець: " << right << endl;

    return 0;
}